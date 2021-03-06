bin_PROGRAMS = covered
covered_SOURCES = arc.c \
                  assertion.c \
                  attr.c \
                  parser.c \
                  gen_parser.c \
                  static_parser.c \
		  binding.c \
                  cli.c \
		  codegen.c \
		  comb.c \
		  db.c \
                  enumerate.c \
                  exclude.c \
		  expr.c \
                  fastlz.c \
		  fsm.c \
                  fsm_arg.c \
		  fsm_var.c \
                  fst.c \
                  func_iter.c \
		  func_unit.c \
                  genprof.c \
                  gen_item.c \
                  generator.new.c \
		  info.c \
		  instance.c \
		  keywords_1995.c \
		  keywords_2001.c \
		  keywords_sv.c \
                  keywords_sys_1995.c \
                  keywords_sys_2001.c \
                  keywords_sys_sv.c \
                  gen_keywords_1995.c \
                  gen_keywords_2001.c \
                  gen_keywords_sv.c \
                  gen_keywords_sys_1995.c \
                  gen_keywords_sys_2001.c \
                  gen_keywords_sys_sv.c \
                  pplexer.c \
		  lexer.c \
                  gen_lexer.c \
		  line.c \
                  link.c \
		  lxt.c \
		  lxt2_read.c \
		  main.c \
                  memory.c \
		  merge.c \
                  obfuscate.c \
                  ovl.c \
		  param.c \
		  parse.c \
                  parser_func.c \
		  parser_misc.c \
		  perf.c \
                  profiler.c \
                  race.c \
                  rank.c \
                  reentrant.c \
		  report.c \
		  scope.c \
		  score.c \
		  search.c \
		  sim.c \
		  stat.c \
                  static.c \
                  static_lexer.c \
		  statement.c \
		  stmt_blk.c \
                  struct_union.c \
		  symtable.c \
                  sys_tasks.c \
		  tcl_funcs.c \
		  toggle.c \
                  tree.c \
                  util.c \
                  vcd.new.c \
		  vcd_keywords.c \
		  vector.c \
		  vsignal.c

covered_LDADD = $(TCLTK_LIBS)

INCLUDES=	-I..
AM_CPPFLAGS=-DINSTALL_DIR=\"@datadir@/covered\" $(TCLTK_CPPFLAGS) $(DEBUGDEF) $(PROFILEDEF) $(TESTMODEDEF)

parser.h parser.c: $(srcdir)/parser.y
	bison --verbose -t -p VL -d -o parser.c $(srcdir)/parser.y

gen_parser.h gen_parser.c: $(srcdir)/gen_parser.y
	bison --verbose -t -p GEN -d -o gen_parser.c $(srcdir)/gen_parser.y

static_parser.h static_parser.c: $(srcdir)/static_parser.y
	bison --verbose -t -p SE -d -o static_parser.c $(srcdir)/static_parser.y
	
pplexer.c: $(srcdir)/pplexer.l
	flex -PPPVL -opplexer.c $(srcdir)/pplexer.l

lexer.c:  $(srcdir)/lexer.l
	flex -PVL -olexer.c $(srcdir)/lexer.l

gen_lexer.c:  $(srcdir)/lexer.l
	echo "#define GENERATOR" > gen_lexer.c
	flex -PGEN -ogen_lexer.c.tmp $(srcdir)/lexer.l
	cat gen_lexer.c.tmp >> gen_lexer.c
	rm -f gen_lexer.c.tmp

static_lexer.c: $(srcdir)/static_lexer.l
	flex -PSE -ostatic_lexer.c $(srcdir)/static_lexer.l

keywords_1995.c:  keywords_1995.gperf
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_1995 -N vl_check_identifier_1995 -t $(srcdir)/keywords_1995.gperf > keywords_1995.c || (rm -f keywords_1995.c ; false)

gen_keywords_1995.c:  keywords_1995.gperf
	echo "#define GENERATOR" > gen_keywords_1995.c
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_1995 -N gen_check_identifier_1995 -t $(srcdir)/keywords_1995.gperf >> gen_keywords_1995.c || (rm -f gen_keywords_1995.c ; false)

keywords_sys_1995.c:  keywords_sys_1995.gperf
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_sys_1995 -N check_identifier_sys_1995 -t $(srcdir)/keywords_sys_1995.gperf > keywords_sys_1995.c || (rm -f keywords_sys_1995.c ; false)

gen_keywords_sys_1995.c:  keywords_sys_1995.gperf
	echo "#define GENERATOR" > gen_keywords_sys_1995.c
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_sys_1995 -N gen_check_identifier_sys_1995 -t $(srcdir)/keywords_sys_1995.gperf >> gen_keywords_sys_1995.c || (rm -f gen_keywords_sys_1995.c ; false)

keywords_2001.c:  keywords_2001.gperf
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_2001 -N check_identifier_2001 -t $(srcdir)/keywords_2001.gperf > keywords_2001.c || (rm -f keywords_2001.c ; false)

gen_keywords_2001.c:  keywords_2001.gperf
	echo "#define GENERATOR" > gen_keywords_2001.c
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_2001 -N gen_check_identifier_2001 -t $(srcdir)/keywords_2001.gperf >> gen_keywords_2001.c || (rm -f gen_keywords_2001.c ; false)

keywords_sys_2001.c:  keywords_sys_2001.gperf
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_sys_2001 -N check_identifier_sys_2001 -t $(srcdir)/keywords_sys_2001.gperf > keywords_sys_2001.c || (rm -f keywords_sys_2001.c ; false)

gen_keywords_sys_2001.c:  keywords_sys_2001.gperf
	echo "#define GENERATOR" > gen_keywords_sys_2001.c
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_sys_2001 -N gen_check_identifier_sys_2001 -t $(srcdir)/keywords_sys_2001.gperf >> gen_keywords_sys_2001.c || (rm -f gen_keywords_sys_2001.c ; false)

keywords_sv.c:  keywords_sv.gperf
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -D -H keyword_hash_sv -N check_identifier_sv -t $(srcdir)/keywords_sv.gperf > keywords_sv.c || (rm -f keywords_sv.c ; false)

gen_keywords_sv.c:  keywords_sv.gperf
	echo "#define GENERATOR" > gen_keywords_sv.c
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -D -H keyword_hash_sv -N gen_check_identifier_sv -t $(srcdir)/keywords_sv.gperf >> gen_keywords_sv.c || (rm -f gen_keywords_sv.c ; false)

keywords_sys_sv.c:  keywords_sys_sv.gperf
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_sys_sv -N check_identifier_sys_sv -t $(srcdir)/keywords_sys_sv.gperf > keywords_sys_sv.c || (rm -f keywords_sys_sv.c ; false)

gen_keywords_sys_sv.c:  keywords_sys_sv.gperf
	echo "#define GENERATOR" > gen_keywords_sys_sv.c
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H keyword_hash_sys_sv -N gen_check_identifier_sys_sv -t $(srcdir)/keywords_sys_sv.gperf >> gen_keywords_sys_sv.c || (rm -f gen_keywords_sys_sv.c ; false)

vcd_keywords.c:  vcd_keywords.gperf
	gperf -o -i 7 -C -k 1-3,$$ -L ANSI-C -H vcd_keyword_hash -N vcd_check_identifier -t $(srcdir)/vcd_keywords.gperf > vcd_keywords.c || (rm -f vcd_keywords.c ; false)

CLEANFILES = pplexer.c \
             lexer.c \
             gen_lexer.c \
             static_lexer.c \
             keywords_1995.c \
             keywords_sys_1995.c \
             keywords_2001.c \
             keywords_sys_2001.c \
             keywords_sv.c \
             keywords_sys_sv.c \
             gen_keywords_1995.c \
             gen_keywords_sys_1995.c \
             gen_keywords_2001.c \
             gen_keywords_sys_2001.c \
             gen_keywords_sv.c \
             gen_keywords_sys_sv.c \
             parser.c \
             parser.h \
             gen_parser.c \
             gen_parser.h \
             parser.output \
             static_parser.c \
             static_parser.h \
             static_parser.output \
             vcd_keywords.c
