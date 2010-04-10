################################################################################################
# Copyright (c) 2006-2010 Trevor Williams                                                      #
#                                                                                              #
# This program is free software; you can redistribute it and/or modify                         #
# it under the terms of the GNU General Public License as published by the Free Software       #
# Foundation; either version 2 of the License, or (at your option) any later version.          #
#                                                                                              #
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;    #
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
# See the GNU General Public License for more details.                                         #
#                                                                                              #
# You should have received a copy of the GNU General Public License along with this program;   #
# if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. #
################################################################################################

proc ttk_optionMenu {w v args} {

  global $v

  ttk::menubutton $w -textvariable $v
  $w configure -menu [menu $w.m -tearoff 0]

  foreach value $args {
    $w.m add radiobutton -variable $v -label $value -value $value
  }

  set $v [lindex $args 0]

  return $w

}

# Include the necessary auxiliary files 
source [file join $HOME scripts menu_create.tcl]
source [file join $HOME scripts cov_create.tcl]
source [file join $HOME scripts process_file.tcl]
source [file join $HOME scripts toggle.tcl]
source [file join $HOME scripts comb.tcl]
source [file join $HOME scripts fsm.tcl]
source [file join $HOME scripts help.tcl]
source [file join $HOME scripts summary.tcl]
source [file join $HOME scripts preferences.tcl]
source [file join $HOME scripts cdd_view.tcl]
source [file join $HOME scripts assert.tcl]
source [file join $HOME scripts verilog.tcl]
source [file join $HOME scripts memory.tcl]
source [file join $HOME scripts wizard.tcl]
source [file join $HOME scripts gen_new.tcl]
source [file join $HOME scripts gen_report.tcl]
source [file join $HOME scripts gen_rank.tcl]
source [file join $HOME scripts viewer.tcl]
source [file join $HOME scripts balloon.tcl]
source [file join $HOME scripts exclude.tcl]
if {[tk windowingsystem] eq "aqua"} {
  source [file join $HOME scripts windowlist.tcl]
}

# The Tablelist package is used for displaying instance/module hit/miss/total/percent hit information
package require Tablelist
#package require tile
#package require tablelist_tile 4.8

set last_block              ""
set lwidth                  -1 
set lwidth_h1               -1
set main_start_search_index 1.0
set curr_uncov_index        ""
set prev_uncov_index        ""
set next_uncov_index        ""
set input_cdd               ""

array set tablelistopts {
  selectbackground   RoyalBlue1
  selectforeground   white
  stretch	     all
  stripebackground   #EDF3FE
  relief             flat
  border             0
  showseparators     yes
  takefocus          0
  setfocus           1
  activestyle        none
}

proc main_view {} {

  global race_msgs prev_uncov_index next_uncov_index
  global HOME main_start_search_index
  global main_geometry
  global mod_inst_tl_columns mod_inst_tl_init_hidden mod_inst_tl_width
  global mod_inst_type

  # Start off 

  # Get all race condition reason messages
  set race_msgs ""
  tcl_func_get_race_reason_msgs

  # Create the frame for menubar creation
  menu_create

  # Create the bottom frame
  ttk::panedwindow .bot -width 1000 -height 500 -orient horizontal

  # Create frames for pane handle
  ttk::frame .bot.left  -relief raised -borderwidth 1
  ttk::frame .bot.right -relief raised -borderwidth 1

  ###############################
  # POPULATE RIGHT BOTTOM FRAME #
  ###############################

  # Create table windows
  trace add variable cov_rb write cov_change_metric

  # Create notebook
  ttk::notebook .bot.right.nb
  bind .bot.right.nb <<NotebookTabChanged>> {
    set cov_rb [lindex [split [.bot.right.nb tab current -text] " "] 0]
    cov_change_metric
  }

  foreach metric [list line toggle memory logic fsm assert] {

    .bot.right.nb add [ttk::frame .bot.right.nb.$metric] -text [string totitle $metric] -underline 0

    # Create the textbox header frame
    ttk::frame .bot.right.nb.$metric.h
    ttk::label .bot.right.nb.$metric.h.tl -text "Cur   Line #       Verilog Source" -anchor w
    ttk::frame .bot.right.nb.$metric.h.pn
    ttk::label .bot.right.nb.$metric.h.pn.prev -image [image create photo -file [file join $HOME scripts left_arrow.gif]] -state disabled
    bind .bot.right.nb.$metric.h.pn.prev <Button-1> {
      if {$cov_rb == "Line"} {
        goto_uncov $prev_uncov_index line
      } elseif {$cov_rb == "Toggle"} {
        goto_uncov $prev_uncov_index toggle
      } elseif {$cov_rb == "Memory"} {
        goto_uncov $prev_uncov_index memory
      } elseif {$cov_rb == "Logic"} {
        goto_uncov $prev_uncov_index logic
      } elseif {$cov_rb == "FSM"} {
        goto_uncov $prev_uncov_index fsm
      } elseif {$cov_rb == "Assert"} {
        goto_uncov $prev_uncov_index assert
      }
    }
    set_balloon .bot.right.nb.$metric.h.pn.prev "Click to view the previous uncovered item"
    ttk::label .bot.right.nb.$metric.h.pn.next -image [image create photo -file [file join $HOME scripts right_arrow.gif]] -state disabled
    bind .bot.right.nb.$metric.h.pn.next <Button-1> {
      if {$cov_rb == "Line"} {
        goto_uncov $next_uncov_index line
      } elseif {$cov_rb == "Toggle"} {
        goto_uncov $next_uncov_index toggle
      } elseif {$cov_rb == "Memory"} {
        goto_uncov $next_uncov_index memory
      } elseif {$cov_rb == "Logic"} {
        goto_uncov $next_uncov_index logic
      } elseif {$cov_rb == "FSM"} {
        goto_uncov $next_uncov_index fsm
      } elseif {$cov_rb == "Assert"} {
        goto_uncov $next_uncov_index assert
      }
    }
    set_balloon .bot.right.nb.$metric.h.pn.next "Click to view the next uncovered item"
    frame .bot.right.nb.$metric.h.search -borderwidth 1 -relief ridge -bg white
    label .bot.right.nb.$metric.h.search.find -image [image create photo -file [file join $HOME scripts find.gif]] -background white -state disabled -relief flat
    bind .bot.right.nb.$metric.h.search.find <ButtonPress-1> {
      perform_search .bot.right.nb.$metric.txt .bot.right.nb.$metric.h.search.e .info main_start_search_index
    }
    set_balloon .bot.right.nb.$metric.h.search.find "Click to find the next occurrence of the search string"
    entry .bot.right.nb.$metric.h.search.e -width 15 -state disabled -relief flat -bg white
    bind .bot.right.nb.$metric.h.search.e <Return> {
      perform_search .bot.right.nb.$metric.txt .bot.right.nb.$metric.h.search.e .info main_start_search_index
    }
    label .bot.right.nb.$metric.h.search.clear -image [image create photo -file [file join $HOME scripts clear.gif]] -background white -state disabled -relief flat
    bind .bot.right.nb.$metric.h.search.clear <ButtonPress-1> {
      .bot.right.nb.$metric.txt tag delete search_found
      .bot.right.nb.$metric.h.search.e delete 0 end
      set main_start_search_index 1.0
    }
    set_balloon .bot.right.nb.$metric.h.search.clear "Click to clear the search string"

    # Pack the previous/next frame
    pack .bot.right.nb.$metric.h.pn.prev -side left
    pack .bot.right.nb.$metric.h.pn.next -side left

    # Pack the search frame
    pack .bot.right.nb.$metric.h.search.find  -side left
    pack .bot.right.nb.$metric.h.search.e     -side left -padx 3
    pack .bot.right.nb.$metric.h.search.clear -side left

    # Pack the textbox header frame
    pack .bot.right.nb.$metric.h.tl     -side left
    pack .bot.right.nb.$metric.h.pn     -side left -expand yes
    pack .bot.right.nb.$metric.h.search -side right

    # Create the text widget to display the modules/instances
    text           .bot.right.nb.$metric.txt -yscrollcommand ".bot.right.nb.$metric.vb set" -xscrollcommand ".bot.right.nb.$metric.hb set" -wrap none -state disabled
    ttk::scrollbar .bot.right.nb.$metric.vb -command ".bot.right.nb.$metric.txt yview"
    ttk::scrollbar .bot.right.nb.$metric.hb -orient horizontal -command ".bot.right.nb.$metric.txt xview"

    # Pack the right paned window
    grid rowconfigure    .bot.right.nb.$metric 1 -weight 1
    grid columnconfigure .bot.right.nb.$metric 0 -weight 1
    grid .bot.right.nb.$metric.h   -row 0 -column 0 -columnspan 2 -sticky nsew
    grid .bot.right.nb.$metric.txt -row 1 -column 0 -sticky nsew
    grid .bot.right.nb.$metric.vb  -row 1 -column 1 -sticky ns
    grid .bot.right.nb.$metric.hb  -row 2 -column 0 -sticky ew

    pack .bot.right.nb -fill both -expand yes

  }

  ##############################
  # POPULATE LEFT BOTTOM FRAME #
  ##############################

  # Create module/instance menubutton
  ttk_optionMenu .bot.left.mi mod_inst_type Module Instance
  trace add variable mod_inst_type write cov_change_type
  set_balloon .bot.left.mi "Selects the coverage accumulated by module or instance"

  # Create hierarchical window
  ttk::treeview  .bot.left.tree -selectmode browse -show tree -xscrollcommand {.bot.left.hb set} -yscrollcommand {.bot.left.vb set} -columns {Summary}
  ttk::scrollbar .bot.left.vb                      -command {.bot.left.tree yview}
  ttk::scrollbar .bot.left.hb   -orient horizontal -command {.bot.left.tree xview}

  grid rowconfigure    .bot.left 1 -weight 1
  grid columnconfigure .bot.left 0 -weight 1
  grid .bot.left.mi   -row 0 -column 0 -sticky ew
  grid .bot.left.tree -row 1 -column 0 -sticky news
  grid .bot.left.vb   -row 1 -column 1 -sticky ns
  grid .bot.left.hb   -row 2 -column 0 -sticky ew

  # Bind the listbox selection event
  bind .bot.left.tree <<TreeviewSelect>> populate_text

  # Pack the bottom window
  update
  .bot add .bot.left
  if {$mod_inst_tl_width != ""} {
    .bot.left configure -width $mod_inst_tl_width
  }
  .bot add .bot.right

  # Create bottom information bar
  ttk::label .info -anchor w -relief raised

  # Pack the widgets
  pack .bot  -fill both -expand yes
  pack .info -fill both

  # Set the window icon
  wm title . "Covered - Verilog Code Coverage Tool"

  # If window position variables have been set, use them
  if {$main_geometry != ""} {
    wm geometry . $main_geometry
  }

  # Set focus on the new window
  wm focusmodel . active
  raise .

  # Set icon
  set icon_img [image create photo -file [file join $HOME scripts cov_icon.gif]]
  wm iconphoto . -default $icon_img

  # Catch the closing of the application and potentially save GUI elements
  wm protocol . WM_DELETE_WINDOW {
    check_to_save_and_close_cdd exiting
    save_gui_elements . .
    destroy .
  }
  bind . <Destroy> {
    check_to_save_and_close_cdd exiting
    save_gui_elements . %W
  }
 
}

proc populate_treeview {} {

  global mod_inst_type last_mod_inst_type cdd_name block_list
  global uncov_fgColor uncov_bgColor
  global lb_fgColor lb_bgColor
  global summary_list

  # Remove contents currently in listboxes
  .bot.left.tree delete [.bot.left.tree children {}]

  if {$cdd_name != ""} {

    # If we are in module mode, list modules (otherwise, list instances)
    if {$mod_inst_type == "Module"} {

      # Get the list of functional units
      set block_list [tcl_func_get_funit_list]

      # Calculate the summary_list array
      calculate_summary

      foreach block $block_list {
        set value "($summary_list($block,total_hit) / $summary_list($block,total_total)) $summary_list($block,total_percent)%"
        .bot.left.tree insert {} end -id $block -text [tcl_func_get_funit_name $block] -values [list $value] -tag tag[lindex $block 0]
        .bot.left.tree tag configure tag[lindex $block 0] -background $summary_list($block,total_color)
      }

    } else {

      # Get the list of functional unit instances
      set block_list [tcl_func_get_instance_list]

      # Calculate the summary_list array
      calculate_summary

      set inst_block() {}
      foreach block $block_list {
        set inst_name [tcl_func_get_inst_scope $block]
        set mod_name  [tcl_func_get_funit_name $block]
        set inst_block($inst_name) $block
        set parent    $inst_block([join [lrange [split $inst_name .] 0 end-1] .])
        set child     [lindex [split $inst_name .] end]
        set value     "($summary_list($block,total_hit) / $summary_list($block,total_total)) $summary_list($block,total_percent)%"
        .bot.left.tree insert $parent end -id $block -text "$child ($mod_name)" -values [list $value] -tag tag[lindex $block 0]
        .bot.left.tree tag configure tag[lindex $block 0] -background $summary_list($block,total_color)
      }

    }

    # Set the last module/instance type variable to the current
    set last_mod_inst_type $mod_inst_type

  }

}

proc populate_text {} {

  global cov_rb block_list curr_block summary_list
  global mod_inst_type last_mod_inst_type
  global last_block
  global start_search_index
  global curr_toggle_ptr

  set curr_block [lindex [.bot.left.tree selection] 0]

  if {$curr_block != ""} {

    if {$last_block != $curr_block || $last_mod_inst_type != $mod_inst_type} {

      set last_block      $curr_block
      set curr_toggle_ptr ""

      # Reset starting search index
      set start_search_index 1.0
      set curr_uncov_index   ""

      # Set the summary information in the Tabs
      .bot.right.nb tab 0 -text "Line ($summary_list($curr_block,line_hit)/$summary_list($curr_block,line_total)) $summary_list($curr_block,line_percent)%"
      .bot.right.nb tab 1 -text "Toggle ($summary_list($curr_block,toggle_hit)/$summary_list($curr_block,toggle_total)) $summary_list($curr_block,toggle_percent)%"
      .bot.right.nb tab 2 -text "Memory ($summary_list($curr_block,memory_hit)/$summary_list($curr_block,memory_total)) $summary_list($curr_block,memory_percent)%"
      .bot.right.nb tab 3 -text "Logic ($summary_list($curr_block,comb_hit)/$summary_list($curr_block,comb_total)) $summary_list($curr_block,comb_percent)%"
      .bot.right.nb tab 4 -text "FSM ($summary_list($curr_block,fsm_hit)/$summary_list($curr_block,fsm_total)) $summary_list($curr_block,fsm_percent)%"
      .bot.right.nb tab 5 -text "Assert ($summary_list($curr_block,assert_hit)/$summary_list($curr_block,assert_total)) $summary_list($curr_block,assert_percent)%"

      if {$cov_rb == "Line"} {
        process_line_cov
        goto_uncov $curr_uncov_index line
        .bot.right.nb.line.h.search.e     configure -state normal -bg white
        .bot.right.nb.line.h.search.find  configure -state normal
        .bot.right.nb.line.h.search.clear configure -state normal
      } elseif {$cov_rb == "Toggle"} {
        process_toggle_cov
        goto_uncov $curr_uncov_index toggle
        .bot.right.nb.toggle.h.search.e     configure -state normal -bg white
        .bot.right.nb.toggle.h.search.find  configure -state normal
        .bot.right.nb.toggle.h.search.clear configure -state normal
      } elseif {$cov_rb == "Memory"} {
        process_memory_cov
        goto_uncov $curr_uncov_index memory
        .bot.right.nb.memory.h.search.e     configure -state normal -bg white
        .bot.right.nb.memory.h.search.find  configure -state normal
        .bot.right.nb.memory.h.search.clear configure -state normal
      } elseif {$cov_rb == "Logic"} {
        process_comb_cov
        goto_uncov $curr_uncov_index logic
        .bot.right.nb.logic.h.search.e     configure -state normal -bg white
        .bot.right.nb.logic.h.search.find  configure -state normal
        .bot.right.nb.logic.h.search.clear configure -state normal
      } elseif {$cov_rb == "FSM"} {
        process_fsm_cov
        goto_uncov $curr_uncov_index fsm
        .bot.right.nb.fsm.h.search.e     configure -state normal -bg white
        .bot.right.nb.fsm.h.search.find  configure -state normal
        .bot.right.nb.fsm.h.search.clear configure -state normal
      } elseif {$cov_rb == "Assert"} {
        process_assert_cov
        goto_uncov $curr_uncov_index assert
        .bot.right.nb.assert.h.search.e     configure -state normal -bg white
        .bot.right.nb.assert.h.search.find  configure -state normal
        .bot.right.nb.assert.h.search.clear configure -state normal
      }


    }

  }

}

proc clear_text {} {

  global last_block

  # Clear the textboxes
  foreach metric [list line toggle memory logic fsm assert] {
    .bot.right.nb.$metric.txt configure -state normal
    .bot.right.nb.$metric.txt delete 1.0 end
    .bot.right.nb.$metric.txt configure -state disabled
  }

  # Reset the last_block
  set last_block ""

}

proc perform_search {tbox ebox ibox index} {

  upvar $index start_search_index 

  set value [$ebox get]
  set index [$tbox search $value $start_search_index]

  # Delete search_found tag
  $tbox tag delete search_found

  if {$index != ""} {

    if {$start_search_index > $index} {
      $ibox configure -text "End of file reached.  Searching from the beginning..."
    } else {
      $ibox configure -text ""
    }

    # Highlight found text
    set value_len [string length $value]
    $tbox tag add search_found $index "$index + $value_len chars"
    $tbox tag configure search_found -background orange1

    # Make the text visible
    $tbox see $index 

    # Calculate next starting index
    set indices [split $index .]
    set start_search_index [lindex $indices 0].[expr [lindex $indices 1] + 1]

  } else {

    # Output a message specifying that the searched string could not be found
    $ibox configure -text "String \"$value\" not found"

    # Clear the contents of the search entry box
    $ebox delete 0 end

    # Reset search index
    set start_search_index 1.0

  }

  # Set focus to text box
  focus $tbox

  return 1

}

proc rm_pointer {curr_ptr metric} {

  upvar $curr_ptr ptr

  # Allow the textbox to be changed
  .bot.right.nb.$metric.txt configure -state normal

  # Delete old cursor, if it is displayed
  if {$ptr != ""} {
    .bot.right.nb.$metric.txt delete $ptr.0 $ptr.3
    .bot.right.nb.$metric.txt insert $ptr.0 "   "
  }

  # Disable textbox
  .bot.right.nb.$metric.txt configure -state disabled

  # Disable "Show current selection" menu item
  .menubar.view entryconfigure 2 -state disabled

  # Clear current pointer
  set ptr ""

}

proc set_pointer {curr_ptr line metric} {

  upvar $curr_ptr ptr

  # Remove old pointer
  rm_pointer ptr $metric

  # Allow the textbox to be changed
  .bot.right.nb.metric.txt configure -state normal

  # Display new pointer
  .bot.right.nb.metric.txt delete $line.0 $line.3
  .bot.right.nb.metric.txt insert $line.0 "-->"

  # Set the textbox to not be changed
  .bot.right.nb.metric.txt configure -state disabled

  # Make sure that we can see the current toggle pointer in the textbox
  .bot.right.nb.metric.txt see $line.0

  # Enable the "Show current selection" menu option
  .menubar.view entryconfigure 2 -state normal

  # Set the current pointer to the specified line
  set ptr $line

}

proc goto_uncov {curr_index metric} {

  global prev_uncov_index next_uncov_index curr_uncov_index
  global cov_rb

  # Calculate the name of the tag to use
  if {$cov_rb == "Line"} {
    set tag_name "uncov_colorMap"
  } else {
    set tag_name "uncov_button"
  }

  # Display the given index, if it has been specified
  if {$curr_index != ""} {
    .bot.right.nb.$metric.txt see $curr_index
    set curr_uncov_index $curr_index
  } else {
    set curr_uncov_index 1.0
  }

  # Get previous uncovered index
  set prev_uncov_index [lindex [.bot.right.nb.$metric.txt tag prevrange $tag_name $curr_uncov_index] 0]

  # Disable/enable previous button
  if {$prev_uncov_index != ""} {
    .bot.right.nb.$metric.h.pn.prev configure -state normal
    .menubar.view entryconfigure 1 -state normal
  } else {
    .bot.right.nb.$metric.h.pn.prev configure -state disabled
    .menubar.view entryconfigure 1 -state disabled
  }

  # Get next uncovered index
  set next_uncov_index [lindex [.bot.right.nb.$metric.txt tag nextrange $tag_name "$curr_uncov_index + 1 chars"] 0]

  # Disable/enable next button
  if {$next_uncov_index != ""} {
    .bot.right.nb.$metric.h.pn.next configure -state normal
    .menubar.view entryconfigure 0 -state normal
  } else {
    .bot.right.nb.$metric.h.pn.next configure -state disabled
    .menubar.view entryconfigure 0 -state disabled
  }

}

proc update_all_windows {} {

  global curr_uncov_index

  # Update the main window
  goto_uncov $curr_uncov_index
  .menubar.view entryconfigure 2 -state disabled

  # Update the toggle window
  update_toggle

  # Update the memory window
  update_memory

  # Update the combinational logic window
  update_comb

  # Update the FSM window
  update_fsm

  # Update the assertion window
  update_assert

}

proc clear_all_windows {} {

  # Clear the main window
  clear_text

  # Clear the summary window
  clear_summary

  # Clear the toggle window
  clear_toggle

  # Clear the memory window
  clear_memory

  # Clear the combinational logic window
  clear_comb

  # Clear the FSM window
  clear_fsm

  # Clear the assertion window
  clear_assert

}

proc bgerror {msg} {

  global errorInfo

  ;# Remove the status window if it exists
  destroy .status

  ;# Display error message
  set retval [tk_messageBox -message "$msg\n$errorInfo" -title "Error" -type ok]

}

proc listbox_yset {args} {
    
  eval [linsert $args 0 .bot.left.fvb.lvb set]
  listbox_yview moveto [lindex [.bot.left.fvb.lvb get] 0]

} 
  
proc listbox_yview {args} {

  eval [linsert $args 0 .bot.left.pw.ff.l   yview]
  eval [linsert $args 0 .bot.left.pw.fhmt.l yview]
  eval [linsert $args 0 .bot.left.pw.fp.l   yview]

}

proc listbox_xset {args} {

  eval [linsert $args 0 .bot.left.lhb set]
  listbox_xview moveto [lindex [.bot.left.lhb get] 0]

}

proc listbox_xview {args} {

  eval [linsert $args 0 .bot.left.pw.ff.l   xview]
  eval [linsert $args 0 .bot.left.pw.fhmt.l xview]
  eval [linsert $args 0 .bot.left.pw.fp.l   xview]

}

proc goto_next_pane {w} {
  
  set parent [winfo parent $w]
  set panes  [$parent panes]
  
  $parent paneconfigure $w -hide true
  $parent paneconfigure [lindex $panes [expr [lsearch $panes $w] + 1]] -hide false
  
}

proc goto_prev_pane {w} {
  
  set parent [winfo parent $w]
  set panes  [$parent panes]
  
  $parent paneconfigure $w -hide true
  $parent paneconfigure [lindex $panes [expr [lsearch $panes $w] - 1]] -hide false
  
}

# Read configuration file
read_coveredrc

# Display main window
main_view

# Set the theme to the clam theme
ttk::style theme use $ttk_style

# If an input CDD(s) was specified, load them now
if {$input_cdd ne ""} {

  open_files $input_cdd

} else {

  # Display the wizard, if the configuration option is set
  if {$show_wizard} {
    create_wizard
  }

}
