/*!
 \file     util.c
 \author   Trevor Williams  (trevorw@charter.net)
 \date     11/27/2001
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <dirent.h>

#ifdef HAVE_MPATROL
#include <mpdebug.h>
#endif

#include "defines.h"
#include "util.h"
#include "link.h"

/*!
 If set to TRUE, suppresses all non-fatal error messages from being displayed.
*/
bool output_suppressed;

/*!
 If set to TRUE, causes debug information to be spewed to screen.
*/
bool debug_mode;

/*!
 Contains the total number of bytes malloc'ed during the simulation run.  This
 information is output to the user after simulation as a performance indicator.
*/
unsigned long curr_malloc_size = 0;

/*!
 Holds the largest number of bytes in allocation at one period of time.
*/
unsigned long largest_malloc_size = 0;

/*!
 Holds some output that will be displayed via the print_output command.  This is
 created globally so that memory does not need to be reallocated for each function
 that wishes to use it.
*/
char user_msg[USER_MSG_LENGTH];


/*!
 \param value Boolean value of suppression.

 Sets the global variable output_suppressed to the specified value.
*/
void set_output_suppression( bool value ) {

  output_suppressed = value;

}

/*!
 \param value  Boolean value of debug mode.

 Sets the global debug mode to the specified value.
*/
void set_debug( bool value ) {

  debug_mode = value;

}

/*!
 \param msg   Message to display.
 \param type  Type of message to output

 Displays the specified message to standard output based on the type of message
 being output.
*/
void print_output( char* msg, int type ) {

  switch( type ) {
    case DEBUG:
      if( debug_mode ) { printf( "%s\n", msg ); }
      break;
    case NORMAL:
      if( !output_suppressed || debug_mode ) { printf( "%s\n", msg ); }
      break;
    case WARNING:
      if( !output_suppressed || debug_mode ) { fprintf( stderr, "    WARNING!  %s\n", msg ); }
      break;
    case FATAL:
      fprintf( stderr, "ERROR!  %s\n", msg );
      break;
    default:  break;
  }

}

/*!
 \param token String to check for valid variable name.
 \return Returns TRUE if the specified string is a legal variable name; otherwise,
         returns FALSE.

 If the specified string follows all of the rules for a legal program
 variable (doesn't start with a number, contains only a-zA-Z0-9_ characters),
 returns a value of TRUE; otherwise, returns a value of FALSE.
*/
bool is_variable( char* token ) {

  bool retval = TRUE;   /* Return value of this function */

  if( token != NULL ) {

    if( (token[0] >= '0') && (token[0] <= '9') ) {

      retval = FALSE;

    } else {

      while( (token[0] != '\0') && retval ) {
        if( !(((token[0] >= 'a') && (token[0] <= 'z')) ||
             ((token[0] >= 'A') && (token[0] <= 'Z')) ||
             ((token[0] >= '0') && (token[0] <= '9')) ||
              (token[0] == '_')) ) {
          retval = FALSE;
        }
        token++;
      }

    }

  } else {

    retval = FALSE;

  }

  return( retval );

}

/*!
 \param token String to check for valid pathname-ness
 \return Returns TRUE if the specified string is a legal UNIX directory;
         otherwise, returns FALSE.

 Returns TRUE if the specified string is either a legal UNIX relative
 pathname or static pathname.  If the specified string does not correlate
 to a legal UNIX pathname, a value of FALSE is returned.
*/
bool is_directory( char* token ) {

  bool retval  = TRUE;    /* Return value of this function   */
  int  periods = 0;       /* Number of periods seen in a row */

  if( token != NULL ) {

    while( (token[0] != '\0') && retval ) {
      if( token[0] == '.' ) {
        periods++;
        if( periods > 2 ) {
          retval = FALSE;
        }
      } else if( token[0] == '/' ) {
        periods = 0;
      } else if( ((token[0] >= 'a') && (token[0] <= 'z')) ||
                 ((token[0] >= 'A') && (token[0] <= 'Z')) ||
                 ((token[0] >= '0') && (token[0] <= '9')) ||
                  (token[0] == '_') ) {
        periods = 0;
      } else {
        retval = FALSE;
      }
      token++;
    }

  } else {

    retval = FALSE;

  }

  return( retval );

}

/*!
 \param dir Name of directory to check for existence.
 \return Returns TRUE if the specified directory exists; otherwise, returns FALSE.

 Checks to see if the specified directory actually exists in the file structure.
 If the directory is found to exist, returns TRUE; otherwise, returns FALSE.
*/
bool directory_exists( char* dir ) {

  bool        retval = FALSE;  /* Return value for this function    */
  struct stat filestat;        /* Statistics of specified directory */

  if( stat( dir, &filestat ) == 0 ) {

    if( S_ISDIR( filestat.st_mode ) ) {

      retval = TRUE;

    }

  }

  return( retval );

}

/*!
 \param dir        Name of directory to read files from.
 \param ext_head   Pointer to extension list.
 \param file_head  Pointer to head element of filename string list.
 \param file_tail  Pointer to tail element of filename string list.

 \bug Need to order files according to extension first instead of filename.

 Opens the specified directory for reading and loads (in order) all files that
 contain the specified extensions (if ext_head is NULL, load only *.v files).
 Stores all string filenames to the specified string list.
*/
void directory_load( char* dir, str_link* ext_head, str_link** file_head, str_link** file_tail ) {

  DIR*           dir_handle;  /* Pointer to opened directory                                 */
  struct dirent* dirp;        /* Pointer to current directory entry                          */
  str_link*      curr_ext;    /* Pointer to current extension string                         */
  char*          ptr;         /* Pointer to current character in filename                    */
  int            tmpchars;    /* Number of characters needed to store full pathname for file */
  char*          tmpfile;     /* Temporary string holder for full pathname of file           */

  if( (dir_handle = opendir( dir )) == NULL ) {

    snprintf( user_msg, USER_MSG_LENGTH, "Unable to read directory %s", dir );
    print_output( user_msg, FATAL );
    exit( 1 );

  } else {

    while( (dirp = readdir( dir_handle )) != NULL ) {
      ptr = dirp->d_name + strlen( dirp->d_name ) - 1;
      /* Work backwards until a dot is encountered */
      while( (ptr >= dirp->d_name) && (*ptr != '.') ) {
        ptr--;
      }
      if( *ptr == '.' ) {
        ptr++;
        curr_ext = ext_head;
        while( (curr_ext != NULL) && (strcmp( ptr, curr_ext->str ) != 0) ) {
          curr_ext = curr_ext->next;
        }
        if( curr_ext != NULL ) {
          /* Found valid extension, add to list */
          tmpchars = strlen( dirp->d_name ) + strlen( dir ) + 2;
          tmpfile  = (char*)malloc_safe( tmpchars );
          snprintf( tmpfile, tmpchars, "%s/%s", dir, dirp->d_name );
          if( str_link_find( tmpfile, *file_head ) == NULL ) {
            str_link_add( tmpfile, file_head, file_tail );
          }
        }
      }
    }

  }

}

/*!
 \param file Name of file to check for existence.
 \return Returns TRUE if the specified file exists; otherwise, returns FALSE.

 Checks to see if the specified file actually exists in the file structure.
 If the file is found to exist, returns TRUE; otherwise, returns FALSE.
*/
bool file_exists( char* file ) {

  bool        retval = FALSE;  /* Return value for this function    */
  struct stat filestat;        /* Statistics of specified directory */

  if( stat( file, &filestat ) == 0 ) {

    if( S_ISREG( filestat.st_mode ) ) {

      retval = TRUE;

    }

  }

  return( retval );

}

/*!
 \param file  File to read next line from.
 \param line  Pointer to string which will contain read line minus newline character.
 
 \return Returns FALSE if feof is encountered; otherwise, returns TRUE.

 Reads in a single line of information from the specified file and returns a string
 containing the read line to the calling function.
*/
bool readline( FILE* file, char** line ) {

  char  c;                 /* Character recently read from file */
  int   i         = 0;     /* Current index of line             */
  int   line_size = 128;   /* Size of current line              */

  *line = (char*)malloc_safe( line_size );

  while( !feof( file ) && ((c = (char)fgetc( file )) != '\n') ) {

    if( i == (line_size - 1) ) {
      line_size = line_size * 2;
      *line     = (char*)realloc( *line, line_size );
    }

    (*line)[i] = c;
    i++;

  }

  if( !feof( file ) ) {
    (*line)[i] = '\0';
  } else {
    free_safe( *line );
    *line = NULL;
  }

  return( !feof( file ) );

}

/*!
 \param scope   Full scope to extract from.
 \param front   Highest level of hierarchy extracted.
 \param rest    Hierarchy left after extraction.
 
 Extracts the highest level of hierarchy from the specified scope,
 returning that instance name to the value of front and the the
 rest of the hierarchy in the value of rest.
*/
void scope_extract_front( char* scope, char* front, char* rest ) {
  
  char* ptr;   /* Pointer to current character */
  
  ptr = scope;
  
  while( (*ptr != '\0') && (*ptr != '.') ) {
    ptr++;
  }
  
  strncpy( front, scope, (ptr - scope) );
  front[ (ptr - scope) ] = '\0';
  
  if( *ptr == '.' ) {
    ptr++;
    strncpy( rest, ptr, (strlen( scope ) - (ptr - scope)) );
    rest[ (strlen( scope ) - (ptr - scope)) ] = '\0';
  } else {
    rest[0] = '\0';
  }
  
}

/*!
 \param scope  Full scope to extract from.
 \param back   Lowest level of hierarchy extracted.
 \param rest   Hierarchy left after extraction.
 
 Extracts the lowest level of hierarchy from the specified scope,
 returning that instance name to the value of back and the the
 rest of the hierarchy in the value of rest.
*/
void scope_extract_back( char* scope, char* back, char* rest ) {

  char* ptr;    /* Pointer to current character */

  ptr = scope + strlen( scope ) - 1;

  while( (ptr > scope) && (*ptr != '.') ) {
    ptr--;
  }

  strncpy( rest, scope, (ptr - scope) );
  rest[ (ptr - scope) ] = '\0';

  if( *ptr == '.' ) {
    ptr++;
  }

  strncpy( back, ptr, ((strlen( scope ) + scope) - ptr) );
  back[ ((strlen( scope ) + scope) - ptr) ] = '\0';
  
}

/*
 \param scope  Scope of some signal.

 \return Returns TRUE if specified scope is local to this module (no hierarchy given);
         otherwise, returns FALSE.

 Parses specified scope for '.' character.  If one is found, returns FALSE; otherwise,
 returns TRUE.
*/
bool scope_local( char* scope ) {

  char* ptr;    /* Pointer to current character */

  assert( scope != NULL );

  ptr = scope;
  while( (*ptr != '\0') && (*ptr != '.') ) {
    ptr++;
  }

  return( *ptr == '\0' );

}

/*!
 \param size  Number of bytes to allocate.

 \return Pointer to allocated memory.

 Allocated memory like a malloc() call but performs some pre-allocation and
 post-allocation checks to be sure that the malloc call works properly.
*/
void* malloc_safe( int size ) {

  void* obj;      /* Object getting malloc address */

  if( size > 10000 ) {
    print_output( "Allocating memory chunk larger than 10000 bytes.  Possible error.", WARNING );
    // printf( "  Memory block size request: %d bytes\n", size );
    assert( size <= 10000 );
  } else if( size <= 0 ) {
    print_output( "Internal:  Attempting to allocate memory of size <= 0", FATAL );
    assert( size > 0 );
  }

  curr_malloc_size += size;

  if( curr_malloc_size > largest_malloc_size ) {
    largest_malloc_size = curr_malloc_size;
  }

  // printf( "Malloc size: %d, curr: %ld, largest: %ld\n", size, curr_malloc_size, largest_malloc_size );

  obj = malloc( size );
  
  // printf( "Allocated memory 0x%lx\n", obj );

  if( obj == NULL ) {
    print_output( "Out of heap memory", FATAL );
    exit( 1 );
  }

  return( obj );

}

/*!
 \param ptr  Pointer to object to deallocate.

 Safely performs a free function of heap memory.  Also keeps track
 of current memory usage for output information at end of program
 life.
*/
void free_safe( void* ptr ) {

  curr_malloc_size -= sizeof( *ptr );

  // printf( "Freeing memory, addr: 0x%lx\n", ptr );

  free( ptr );

}

/*!
 \param spaces  Pointer to string to places spaces into.
 \param num_spaces  Number of spaces to place in string.
 
 Creates a string that contains num_spaces number of space characters,
 adding a NULL character at the end of the string to allow for correct
 usage by the strlen and other string functions.
*/
void gen_space( char* spaces, int num_spaces ) {

  int i;     /* Loop iterator */

  for( i=0; i<num_spaces; i++ ) {
    spaces[i] = ' ';
  }

  spaces[i] = '\0';
  
}

/* $Log$
/* Revision 1.13  2002/10/11 05:23:21  phase1geo
/* Removing local user message allocation and replacing with global to help
/* with memory efficiency.
/*
/* Revision 1.12  2002/10/11 04:24:02  phase1geo
/* This checkin represents some major code renovation in the score command to
/* fully accommodate parameter support.  All parameter support is in at this
/* point and the most commonly used parameter usages have been verified.  Some
/* bugs were fixed in handling default values of constants and expression tree
/* resizing has been optimized to its fullest.  Full regression has been
/* updated and passes.  Adding new diagnostics to test suite.  Fixed a few
/* problems in report outputting.
/*
/* Revision 1.11  2002/09/25 05:36:08  phase1geo
/* Initial version of parameter support is now in place.  Parameters work on a
/* basic level.  param1.v tests this basic functionality and param1.cdd contains
/* the correct CDD output from handling parameters in this file.  Yeah!
/*
/* Revision 1.10  2002/07/20 22:22:52  phase1geo
/* Added ability to create implicit signals for local signals.  Added implicit1.v
/* diagnostic to test for correctness.  Full regression passes.  Other tweaks to
/* output information.
/*
/* Revision 1.9  2002/07/20 20:48:09  phase1geo
/* Fixing a bug that caused the same file to be added to the use_files list
/* more than once.  A filename will only appear once in this list now.  Updates
/* to the TODO list.
/*
/* Revision 1.8  2002/07/18 22:02:35  phase1geo
/* In the middle of making improvements/fixes to the expression/signal
/* binding phase.
/*
/* Revision 1.7  2002/07/09 04:46:26  phase1geo
/* Adding -D and -Q options to covered for outputting debug information or
/* suppressing normal output entirely.  Updated generated documentation and
/* modified Verilog diagnostic Makefile to use these new options.
/*
/* Revision 1.6  2002/07/08 12:35:31  phase1geo
/* Added initial support for library searching.  Code seems to be broken at the
/* moment.
/*
/* Revision 1.5  2002/07/03 03:31:11  phase1geo
/* Adding RCS Log strings in files that were missing them so that file version
/* information is contained in every source and header file.  Reordering src
/* Makefile to be alphabetical.  Adding mult1.v diagnostic to regression suite.
/* */
