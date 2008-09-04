#ifndef __GENPROF_H__
#define __GENPROF_H__

/*
 Copyright (c) 2006 Trevor Williams

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by the Free Software
 Foundation; either version 2 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with this program;
 if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/*!
 \file    genprof.h
 \author  Trevor Williams  (phase1geo@gmail.com)
 \date    12/10/2007
*/

#include "defines.h"

#define NUM_PROFILES 989

#ifdef DEBUG
#define UNREGISTERED 0
#define FSM_ARG_PARSE_STATE 1
#define FSM_ARG_PARSE 2
#define FSM_ARG_PARSE_VALUE 3
#define FSM_ARG_PARSE_TRANS 4
#define FSM_ARG_PARSE_ATTR 5
#define SYM_VALUE_STORE 6
#define ADD_SYM_VALUES_TO_SIM 7
#define COVERED_VALUE_CHANGE 8
#define COVERED_END_OF_SIM 9
#define COVERED_CB_ERROR_HANDLER 10
#define GEN_NEXT_SYMBOL 11
#define COVERED_CREATE_VALUE_CHANGE_CB 12
#define COVERED_PARSE_TASK_FUNC 13
#define COVERED_PARSE_SIGNALS 14
#define COVERED_PARSE_INSTANCE 15
#define COVERED_SIM_CALLTF 16
#define COVERED_REGISTER 17
#define LEXER_KEYWORD_SV_CODE 18
#define VSIGNAL_INIT 19
#define VSIGNAL_CREATE 20
#define VSIGNAL_CREATE_VEC 21
#define VSIGNAL_DUPLICATE 22
#define VSIGNAL_DB_WRITE 23
#define VSIGNAL_DB_READ 24
#define VSIGNAL_DB_MERGE 25
#define VSIGNAL_MERGE 26
#define VSIGNAL_PROPAGATE 27
#define VSIGNAL_VCD_ASSIGN 28
#define VSIGNAL_ADD_EXPRESSION 29
#define VSIGNAL_FROM_STRING 30
#define VSIGNAL_CALC_WIDTH_FOR_EXPR 31
#define VSIGNAL_CALC_LSB_FOR_EXPR 32
#define VSIGNAL_DEALLOC 33
#define LEXER_KEYWORD_1995_CODE 34
#define STMT_ITER_RESET 35
#define STMT_ITER_COPY 36
#define STMT_ITER_NEXT 37
#define STMT_ITER_REVERSE 38
#define STMT_ITER_FIND_HEAD 39
#define STMT_ITER_GET_NEXT_IN_ORDER 40
#define STMT_ITER_GET_LINE_BEFORE 41
#define LEXER_CSTRING_A 42
#define LEXER_KEYWORD_A 43
#define LEXER_ESCAPED_NAME 44
#define LEXER_SYSTEM_CALL 45
#define LINE_DIRECTIVE 46
#define LINE_DIRECTIVE2 47
#define PROCESS_TIMESCALE_TOKEN 48
#define PROCESS_TIMESCALE 49
#define LEXER_YYWRAP 50
#define RESET_LEXER 51
#define CHECK_FOR_PRAGMA 52
#define STATEMENT_CREATE 53
#define STATEMENT_QUEUE_ADD 54
#define STATEMENT_QUEUE_COMPARE 55
#define STATEMENT_SIZE_ELEMENTS 56
#define STATEMENT_DB_WRITE 57
#define STATEMENT_DB_WRITE_TREE 58
#define STATEMENT_DB_WRITE_EXPR_TREE 59
#define STATEMENT_DB_READ 60
#define STATEMENT_ASSIGN_EXPR_IDS 61
#define STATEMENT_CONNECT 62
#define STATEMENT_GET_LAST_LINE_HELPER 63
#define STATEMENT_GET_LAST_LINE 64
#define STATEMENT_FIND_RHS_SIGS 65
#define STATEMENT_FIND_HEAD_STATEMENT 66
#define STATEMENT_FIND_STATEMENT 67
#define STATEMENT_CONTAINS_EXPR_CALLING_STMT 68
#define STATEMENT_DEALLOC_RECURSIVE 69
#define STATEMENT_DEALLOC 70
#define ENUMERATE_ADD_ITEM 71
#define ENUMERATE_END_LIST 72
#define ENUMERATE_RESOLVE 73
#define ENUMERATE_DEALLOC 74
#define ENUMERATE_DEALLOC_LIST 75
#define PARSER_PORT_DECLARATION_A 76
#define PARSER_PORT_DECLARATION_B 77
#define PARSER_PORT_DECLARATION_C 78
#define PARSER_STATIC_EXPR_PRIMARY_A 79
#define PARSER_STATIC_EXPR_PRIMARY_B 80
#define PARSER_EXPRESSION_LIST_A 81
#define PARSER_EXPRESSION_LIST_B 82
#define PARSER_EXPRESSION_LIST_C 83
#define PARSER_EXPRESSION_LIST_D 84
#define PARSER_IDENTIFIER_A 85
#define PARSER_GENERATE_CASE_ITEM_A 86
#define PARSER_GENERATE_CASE_ITEM_B 87
#define PARSER_GENERATE_CASE_ITEM_C 88
#define PARSER_STATEMENT_BEGIN_A 89
#define PARSER_STATEMENT_FORK_A 90
#define PARSER_STATEMENT_FOR_A 91
#define PARSER_CASE_ITEM_A 92
#define PARSER_CASE_ITEM_B 93
#define PARSER_CASE_ITEM_C 94
#define PARSER_DELAY_VALUE_A 95
#define PARSER_DELAY_VALUE_B 96
#define PARSER_PARAMETER_VALUE_BYNAME_A 97
#define PARSER_GATE_INSTANCE_A 98
#define PARSER_GATE_INSTANCE_B 99
#define PARSER_GATE_INSTANCE_C 100
#define PARSER_GATE_INSTANCE_D 101
#define PARSER_LIST_OF_NAMES_A 102
#define PARSER_LIST_OF_NAMES_B 103
#define ATTRIBUTE_CREATE 104
#define ATTRIBUTE_PARSE 105
#define ATTRIBUTE_DEALLOC 106
#define SEARCH_INIT 107
#define SEARCH_ADD_INCLUDE_PATH 108
#define SEARCH_ADD_DIRECTORY_PATH 109
#define SEARCH_ADD_FILE 110
#define SEARCH_ADD_NO_SCORE_FUNIT 111
#define SEARCH_ADD_EXTENSIONS 112
#define SEARCH_FREE_LISTS 113
#define RANK_CREATE_COMP_CDD_COV 114
#define RANK_DEALLOC_COMP_CDD_COV 115
#define RANK_CHECK_INDEX 116
#define RANK_GATHER_SIGNAL_COV 117
#define RANK_GATHER_COMB_COV 118
#define RANK_GATHER_EXPRESSION_COV 119
#define RANK_GATHER_FSM_COV 120
#define RANK_CALC_NUM_CPS 121
#define RANK_GATHER_COMP_CDD_COV 122
#define RANK_READ_CDD 123
#define RANK_SELECTED_CDD_COV 124
#define RANK_PERFORM_WEIGHTED_SELECTION 125
#define RANK_PERFORM_GREEDY_SORT 126
#define RANK_COUNT_CPS 127
#define RANK_PERFORM 128
#define RANK_OUTPUT 129
#define COMMAND_RANK 130
#define SIM_CURRENT_THREAD 131
#define SIM_THREAD_POP_HEAD 132
#define SIM_THREAD_INSERT_INTO_DELAY_QUEUE 133
#define SIM_THREAD_PUSH 134
#define SIM_EXPR_CHANGED 135
#define SIM_CREATE_THREAD 136
#define SIM_ADD_THREAD 137
#define SIM_KILL_THREAD 138
#define SIM_KILL_THREAD_WITH_FUNIT 139
#define SIM_ADD_STATICS 140
#define SIM_EXPRESSION 141
#define SIM_THREAD 142
#define SIM_SIMULATE 143
#define SIM_INITIALIZE 144
#define SIM_STOP 145
#define SIM_FINISH 146
#define SIM_DEALLOC 147
#define SCOPE_FIND_FUNIT_FROM_SCOPE 148
#define SCOPE_FIND_PARAM 149
#define SCOPE_FIND_SIGNAL 150
#define SCOPE_FIND_TASK_FUNCTION_NAMEDBLOCK 151
#define SCOPE_GET_PARENT_FUNIT 152
#define SCOPE_GET_PARENT_MODULE 153
#define REPORT_PARSE_METRICS 154
#define REPORT_PARSE_ARGS 155
#define REPORT_GATHER_INSTANCE_STATS 156
#define REPORT_GATHER_FUNIT_STATS 157
#define REPORT_PRINT_HEADER 158
#define REPORT_GENERATE 159
#define REPORT_READ_CDD_AND_READY 160
#define REPORT_CLOSE_CDD 161
#define REPORT_SAVE_CDD 162
#define REPORT_FORMAT_EXCLUSION_REASON 163
#define REPORT_OUTPUT_EXCLUSION_REASON 164
#define COMMAND_REPORT 165
#define CHECK_OPTION_VALUE 166
#define IS_VARIABLE 167
#define IS_FUNC_UNIT 168
#define IS_LEGAL_FILENAME 169
#define GET_BASENAME 170
#define GET_DIRNAME 171
#define DIRECTORY_EXISTS 172
#define DIRECTORY_LOAD 173
#define FILE_EXISTS 174
#define UTIL_READLINE 175
#define GET_QUOTED_STRING 176
#define SUBSTITUTE_ENV_VARS 177
#define SCOPE_EXTRACT_FRONT 178
#define SCOPE_EXTRACT_BACK 179
#define SCOPE_EXTRACT_SCOPE 180
#define SCOPE_GEN_PRINTABLE 181
#define SCOPE_COMPARE 182
#define SCOPE_LOCAL 183
#define CONVERT_FILE_TO_MODULE 184
#define GET_NEXT_VFILE 185
#define GEN_SPACE 186
#define GET_FUNIT_TYPE 187
#define CALC_MISS_PERCENT 188
#define READ_COMMAND_FILE 189
#define OVL_IS_ASSERTION_NAME 190
#define OVL_IS_ASSERTION_MODULE 191
#define OVL_IS_COVERAGE_POINT 192
#define OVL_ADD_ASSERTIONS_TO_NO_SCORE_LIST 193
#define OVL_GET_FUNIT_STATS 194
#define OVL_GET_COVERAGE_POINT 195
#define OVL_DISPLAY_VERBOSE 196
#define OVL_COLLECT 197
#define OVL_GET_COVERAGE 198
#define COMBINATION_CALC_DEPTH 199
#define COMBINATION_DOES_MULTI_EXP_NEED_UL 200
#define COMBINATION_MULTI_EXPR_CALC 201
#define COMBINATION_IS_EXPR_MULTI_NODE 202
#define COMBINATION_GET_TREE_STATS 203
#define COMBINATION_RESET_COUNTED_EXPRS 204
#define COMBINATION_RESET_COUNTED_EXPR_TREE 205
#define COMBINATION_GET_STATS 206
#define COMBINATION_GET_FUNIT_SUMMARY 207
#define COMBINATION_GET_INST_SUMMARY 208
#define COMBINATION_DISPLAY_INSTANCE_SUMMARY 209
#define COMBINATION_INSTANCE_SUMMARY 210
#define COMBINATION_DISPLAY_FUNIT_SUMMARY 211
#define COMBINATION_FUNIT_SUMMARY 212
#define COMBINATION_DRAW_LINE 213
#define COMBINATION_DRAW_CENTERED_LINE 214
#define COMBINATION_UNDERLINE_TREE 215
#define COMBINATION_PREP_LINE 216
#define COMBINATION_UNDERLINE 217
#define COMBINATION_UNARY 218
#define COMBINATION_EVENT 219
#define COMBINATION_TWO_VARS 220
#define COMBINATION_MULTI_VAR_EXPRS 221
#define COMBINATION_MULTI_EXPR_OUTPUT_LENGTH 222
#define COMBINATION_MULTI_EXPR_OUTPUT 223
#define COMBINATION_MULTI_VARS 224
#define COMBINATION_GET_MISSED_EXPR 225
#define COMBINATION_LIST_MISSED 226
#define COMBINATION_OUTPUT_EXPR 227
#define COMBINATION_DISPLAY_VERBOSE 228
#define COMBINATION_INSTANCE_VERBOSE 229
#define COMBINATION_FUNIT_VERBOSE 230
#define COMBINATION_COLLECT 231
#define COMBINATION_GET_EXCLUDE_LIST 232
#define COMBINATION_GET_EXPRESSION 233
#define COMBINATION_GET_COVERAGE 234
#define COMBINATION_REPORT 235
#define VCD_PARSE_DEF_IGNORE 236
#define VCD_PARSE_DEF_VAR 237
#define VCD_PARSE_DEF_SCOPE 238
#define VCD_PARSE_DEF 239
#define VCD_PARSE_SIM_VECTOR 240
#define VCD_PARSE_SIM_IGNORE 241
#define VCD_PARSE_SIM 242
#define VCD_PARSE 243
#define STR_LINK_ADD 244
#define STMT_LINK_ADD_HEAD 245
#define STMT_LINK_ADD_TAIL 246
#define STMT_LINK_MERGE 247
#define EXP_LINK_ADD 248
#define SIG_LINK_ADD 249
#define FSM_LINK_ADD 250
#define FUNIT_LINK_ADD 251
#define GITEM_LINK_ADD 252
#define INST_LINK_ADD 253
#define STR_LINK_FIND 254
#define STMT_LINK_FIND 255
#define EXP_LINK_FIND 256
#define SIG_LINK_FIND 257
#define FSM_LINK_FIND 258
#define FUNIT_LINK_FIND 259
#define GITEM_LINK_FIND 260
#define INST_LINK_FIND_BY_SCOPE 261
#define INST_LINK_FIND_BY_FUNIT 262
#define STR_LINK_REMOVE 263
#define EXP_LINK_REMOVE 264
#define GITEM_LINK_REMOVE 265
#define FUNIT_LINK_REMOVE 266
#define INST_LINK_FLATTEN 267
#define STR_LINK_DELETE_LIST 268
#define STMT_LINK_UNLINK 269
#define STMT_LINK_DELETE_LIST 270
#define EXP_LINK_DELETE_LIST 271
#define SIG_LINK_DELETE_LIST 272
#define FSM_LINK_DELETE_LIST 273
#define FUNIT_LINK_DELETE_LIST 274
#define GITEM_LINK_DELETE_LIST 275
#define INST_LINK_DELETE_LIST 276
#define SCORE_GENERATE_TOP_VPI_MODULE 277
#define SCORE_GENERATE_PLI_TAB_FILE 278
#define SCORE_PARSE_DEFINE 279
#define SCORE_ADD_ARG 280
#define SCORE_PARSE_ARGS 281
#define COMMAND_SCORE 282
#define MEMORY_GET_STAT 283
#define MEMORY_GET_STATS 284
#define MEMORY_GET_FUNIT_SUMMARY 285
#define MEMORY_GET_INST_SUMMARY 286
#define MEMORY_CREATE_PDIM_BIT_ARRAY 287
#define MEMORY_GET_MEM_COVERAGE 288
#define MEMORY_GET_COVERAGE 289
#define MEMORY_COLLECT 290
#define MEMORY_DISPLAY_TOGGLE_INSTANCE_SUMMARY 291
#define MEMORY_TOGGLE_INSTANCE_SUMMARY 292
#define MEMORY_DISPLAY_AE_INSTANCE_SUMMARY 293
#define MEMORY_AE_INSTANCE_SUMMARY 294
#define MEMORY_DISPLAY_TOGGLE_FUNIT_SUMMARY 295
#define MEMORY_TOGGLE_FUNIT_SUMMARY 296
#define MEMORY_DISPLAY_AE_FUNIT_SUMMARY 297
#define MEMORY_AE_FUNIT_SUMMARY 298
#define MEMORY_DISPLAY_MEMORY 299
#define MEMORY_DISPLAY_VERBOSE 300
#define MEMORY_INSTANCE_VERBOSE 301
#define MEMORY_FUNIT_VERBOSE 302
#define MEMORY_REPORT 303
#define DB_CREATE 304
#define DB_CLOSE 305
#define DB_CHECK_FOR_TOP_MODULE 306
#define DB_WRITE 307
#define DB_READ 308
#define DB_MERGE_FUNITS 309
#define DB_SCALE_TO_PRECISION 310
#define DB_CREATE_UNNAMED_SCOPE 311
#define DB_IS_UNNAMED_SCOPE 312
#define DB_SET_TIMESCALE 313
#define DB_GET_CURR_FUNIT 314
#define DB_GET_EXCLUSION_ID_SIZE 315
#define DB_GEN_EXCLUSION_ID 316
#define DB_ADD_INSTANCE 317
#define DB_ADD_MODULE 318
#define DB_END_MODULE 319
#define DB_ADD_FUNCTION_TASK_NAMEDBLOCK 320
#define DB_END_FUNCTION_TASK_NAMEDBLOCK 321
#define DB_ADD_DECLARED_PARAM 322
#define DB_ADD_OVERRIDE_PARAM 323
#define DB_ADD_VECTOR_PARAM 324
#define DB_ADD_DEFPARAM 325
#define DB_ADD_SIGNAL 326
#define DB_ADD_ENUM 327
#define DB_END_ENUM_LIST 328
#define DB_ADD_TYPEDEF 329
#define DB_FIND_SIGNAL 330
#define DB_ADD_GEN_ITEM_BLOCK 331
#define DB_FIND_GEN_ITEM 332
#define DB_FIND_TYPEDEF 333
#define DB_GET_CURR_GEN_BLOCK 334
#define DB_CURR_SIGNAL_COUNT 335
#define DB_CREATE_EXPRESSION 336
#define DB_BIND_EXPR_TREE 337
#define DB_CREATE_EXPR_FROM_STATIC 338
#define DB_ADD_EXPRESSION 339
#define DB_CREATE_SENSITIVITY_LIST 340
#define DB_PARALLELIZE_STATEMENT 341
#define DB_CREATE_STATEMENT 342
#define DB_ADD_STATEMENT 343
#define DB_REMOVE_STATEMENT_FROM_CURRENT_FUNIT 344
#define DB_REMOVE_STATEMENT 345
#define DB_CONNECT_STATEMENT_TRUE 346
#define DB_CONNECT_STATEMENT_FALSE 347
#define DB_GEN_ITEM_CONNECT_TRUE 348
#define DB_GEN_ITEM_CONNECT_FALSE 349
#define DB_GEN_ITEM_CONNECT 350
#define DB_STATEMENT_CONNECT 351
#define DB_CREATE_ATTR_PARAM 352
#define DB_PARSE_ATTRIBUTE 353
#define DB_REMOVE_STMT_BLKS_CALLING_STATEMENT 354
#define DB_GEN_CURR_INST_SCOPE 355
#define DB_SYNC_CURR_INSTANCE 356
#define DB_SET_VCD_SCOPE 357
#define DB_VCD_UPSCOPE 358
#define DB_ASSIGN_SYMBOL 359
#define DB_SET_SYMBOL_CHAR 360
#define DB_SET_SYMBOL_STRING 361
#define DB_DO_TIMESTEP 362
#define FSM_CREATE 363
#define FSM_ADD_ARC 364
#define FSM_CREATE_TABLES 365
#define FSM_DB_WRITE 366
#define FSM_DB_READ 367
#define FSM_DB_MERGE 368
#define FSM_MERGE 369
#define FSM_TABLE_SET 370
#define FSM_GET_STATS 371
#define FSM_GET_FUNIT_SUMMARY 372
#define FSM_GET_INST_SUMMARY 373
#define FSM_GATHER_SIGNALS 374
#define FSM_COLLECT 375
#define FSM_GET_COVERAGE 376
#define FSM_DISPLAY_INSTANCE_SUMMARY 377
#define FSM_INSTANCE_SUMMARY 378
#define FSM_DISPLAY_FUNIT_SUMMARY 379
#define FSM_FUNIT_SUMMARY 380
#define FSM_DISPLAY_STATE_VERBOSE 381
#define FSM_DISPLAY_ARC_VERBOSE 382
#define FSM_DISPLAY_VERBOSE 383
#define FSM_INSTANCE_VERBOSE 384
#define FSM_FUNIT_VERBOSE 385
#define FSM_REPORT 386
#define FSM_DEALLOC 387
#define CODEGEN_CREATE_EXPR_HELPER 388
#define CODEGEN_CREATE_EXPR 389
#define CODEGEN_GEN_EXPR 390
#define TOGGLE_GET_STATS 391
#define TOGGLE_COLLECT 392
#define TOGGLE_GET_COVERAGE 393
#define TOGGLE_GET_FUNIT_SUMMARY 394
#define TOGGLE_GET_INST_SUMMARY 395
#define TOGGLE_DISPLAY_INSTANCE_SUMMARY 396
#define TOGGLE_INSTANCE_SUMMARY 397
#define TOGGLE_DISPLAY_FUNIT_SUMMARY 398
#define TOGGLE_FUNIT_SUMMARY 399
#define TOGGLE_DISPLAY_VERBOSE 400
#define TOGGLE_INSTANCE_VERBOSE 401
#define TOGGLE_FUNIT_VERBOSE 402
#define TOGGLE_REPORT 403
#define VLERROR 404
#define VLWARN 405
#define PARSER_DEALLOC_SIG_RANGE 406
#define PARSER_COPY_CURR_RANGE 407
#define PARSER_COPY_RANGE_TO_CURR_RANGE 408
#define PARSER_EXPLICITLY_SET_CURR_RANGE 409
#define PARSER_IMPLICITLY_SET_CURR_RANGE 410
#define PARSER_CHECK_GENERATION 411
#define LEXER_KEYWORD_2001_CODE 412
#define STRUCT_UNION_LENGTH 413
#define STRUCT_UNION_ADD_MEMBER 414
#define STRUCT_UNION_ADD_MEMBER_VOID 415
#define STRUCT_UNION_ADD_MEMBER_SIG 416
#define STRUCT_UNION_ADD_MEMBER_TYPEDEF 417
#define STRUCT_UNION_ADD_MEMBER_ENUM 418
#define STRUCT_UNION_ADD_MEMBER_STRUCT_UNION 419
#define STRUCT_UNION_CREATE 420
#define STRUCT_UNION_MEMBER_DEALLOC 421
#define STRUCT_UNION_DEALLOC 422
#define STRUCT_UNION_DEALLOC_LIST 423
#define BIND_ADD 424
#define BIND_APPEND_FSM_EXPR 425
#define BIND_REMOVE 426
#define BIND_FIND_SIG_NAME 427
#define BIND_PARAM 428
#define BIND_SIGNAL 429
#define BIND_TASK_FUNCTION_PORTS 430
#define BIND_TASK_FUNCTION_NAMEDBLOCK 431
#define BIND_PERFORM 432
#define BIND_DEALLOC 433
#define PERF_GEN_STATS 434
#define PERF_OUTPUT_MOD_STATS 435
#define PERF_OUTPUT_INST_REPORT_HELPER 436
#define PERF_OUTPUT_INST_REPORT 437
#define MOD_PARM_FIND 438
#define MOD_PARM_FIND_EXPR_AND_REMOVE 439
#define MOD_PARM_ADD 440
#define INST_PARM_FIND 441
#define INST_PARM_ADD 442
#define INST_PARM_ADD_GENVAR 443
#define INST_PARM_BIND 444
#define DEFPARAM_ADD 445
#define DEFPARAM_DEALLOC 446
#define PARAM_FIND_AND_SET_EXPR_VALUE 447
#define PARAM_SET_SIG_SIZE 448
#define PARAM_SIZE_FUNCTION 449
#define PARAM_EXPR_EVAL 450
#define PARAM_HAS_OVERRIDE 451
#define PARAM_HAS_DEFPARAM 452
#define PARAM_RESOLVE_DECLARED 453
#define PARAM_RESOLVE_OVERRIDE 454
#define PARAM_RESOLVE 455
#define PARAM_DB_WRITE 456
#define MOD_PARM_DEALLOC 457
#define INST_PARM_DEALLOC 458
#define DEF_LOOKUP 459
#define IS_DEFINED 460
#define DEF_MATCH 461
#define DEF_START 462
#define DEFINE_MACRO 463
#define DO_DEFINE 464
#define DEF_IS_DONE 465
#define DEF_FINISH 466
#define DEF_UNDEFINE 467
#define INCLUDE_FILENAME 468
#define DO_INCLUDE 469
#define YYWRAP 470
#define RESET_PPLEXER 471
#define REENTRANT_COUNT_AFU_BITS 472
#define REENTRANT_STORE_DATA_BITS 473
#define REENTRANT_RESTORE_DATA_BITS 474
#define REENTRANT_CREATE 475
#define REENTRANT_DEALLOC 476
#define PARSE_READLINE 477
#define PARSE_DESIGN 478
#define PARSE_AND_SCORE_DUMPFILE 479
#define OBFUSCATE_SET_MODE 480
#define OBFUSCATE_NAME 481
#define OBFUSCATE_DEALLOC 482
#define INFO_SET_VECTOR_ELEM_SIZE 483
#define INFO_DB_WRITE 484
#define INFO_DB_READ 485
#define ARGS_DB_READ 486
#define MESSAGE_DB_READ 487
#define MERGED_CDD_DB_READ 488
#define INFO_DEALLOC 489
#define ASSERTION_PARSE 490
#define ASSERTION_PARSE_ATTR 491
#define ASSERTION_GET_STATS 492
#define ASSERTION_DISPLAY_INSTANCE_SUMMARY 493
#define ASSERTION_INSTANCE_SUMMARY 494
#define ASSERTION_DISPLAY_FUNIT_SUMMARY 495
#define ASSERTION_FUNIT_SUMMARY 496
#define ASSERTION_DISPLAY_VERBOSE 497
#define ASSERTION_INSTANCE_VERBOSE 498
#define ASSERTION_FUNIT_VERBOSE 499
#define ASSERTION_REPORT 500
#define ASSERTION_GET_FUNIT_SUMMARY 501
#define ASSERTION_COLLECT 502
#define ASSERTION_GET_COVERAGE 503
#define LXT2_RD_EXPAND_INTEGER_TO_BITS 504
#define LXT2_RD_EXPAND_BITS_TO_INTEGER 505
#define LXT2_RD_ITER_RADIX 506
#define LXT2_RD_ITER_RADIX0 507
#define LXT2_RD_BUILD_RADIX 508
#define LXT2_RD_REGENERATE_PROCESS_MASK 509
#define LXT2_RD_PROCESS_BLOCK 510
#define LXT2_RD_INIT 511
#define LXT2_RD_CLOSE 512
#define LXT2_RD_GET_FACNAME 513
#define LXT2_RD_ITER_BLOCKS 514
#define LXT2_RD_LIMIT_TIME_RANGE 515
#define LXT2_RD_UNLIMIT_TIME_RANGE 516
#define TREE_ADD 517
#define TREE_FIND 518
#define TREE_REMOVE 519
#define TREE_DEALLOC 520
#define EXPRESSION_CREATE_TMP_VECS 521
#define EXPRESSION_CREATE_VALUE 522
#define EXPRESSION_CREATE 523
#define EXPRESSION_SET_VALUE 524
#define EXPRESSION_SET_SIGNED 525
#define EXPRESSION_RESIZE 526
#define EXPRESSION_GET_ID 527
#define EXPRESSION_GET_FIRST_LINE_EXPR 528
#define EXPRESSION_GET_LAST_LINE_EXPR 529
#define EXPRESSION_GET_CURR_DIMENSION 530
#define EXPRESSION_FIND_RHS_SIGS 531
#define EXPRESSION_FIND_PARAMS 532
#define EXPRESSION_FIND_ULINE_ID 533
#define EXPRESSION_FIND_EXPR 534
#define EXPRESSION_CONTAINS_EXPR_CALLING_STMT 535
#define EXPRESSION_GET_ROOT_STATEMENT 536
#define EXPRESSION_ASSIGN_EXPR_IDS 537
#define EXPRESSION_DB_WRITE 538
#define EXPRESSION_DB_WRITE_TREE 539
#define EXPRESSION_DB_READ 540
#define EXPRESSION_DB_MERGE 541
#define EXPRESSION_MERGE 542
#define EXPRESSION_STRING_OP 543
#define EXPRESSION_STRING 544
#define EXPRESSION_OP_FUNC__XOR 545
#define EXPRESSION_OP_FUNC__XOR_A 546
#define EXPRESSION_OP_FUNC__MULTIPLY 547
#define EXPRESSION_OP_FUNC__MULTIPLY_A 548
#define EXPRESSION_OP_FUNC__DIVIDE 549
#define EXPRESSION_OP_FUNC__DIVIDE_A 550
#define EXPRESSION_OP_FUNC__MOD 551
#define EXPRESSION_OP_FUNC__MOD_A 552
#define EXPRESSION_OP_FUNC__ADD 553
#define EXPRESSION_OP_FUNC__ADD_A 554
#define EXPRESSION_OP_FUNC__SUBTRACT 555
#define EXPRESSION_OP_FUNC__SUB_A 556
#define EXPRESSION_OP_FUNC__AND 557
#define EXPRESSION_OP_FUNC__AND_A 558
#define EXPRESSION_OP_FUNC__OR 559
#define EXPRESSION_OP_FUNC__OR_A 560
#define EXPRESSION_OP_FUNC__NAND 561
#define EXPRESSION_OP_FUNC__NOR 562
#define EXPRESSION_OP_FUNC__NXOR 563
#define EXPRESSION_OP_FUNC__LT 564
#define EXPRESSION_OP_FUNC__GT 565
#define EXPRESSION_OP_FUNC__LSHIFT 566
#define EXPRESSION_OP_FUNC__LSHIFT_A 567
#define EXPRESSION_OP_FUNC__RSHIFT 568
#define EXPRESSION_OP_FUNC__RSHIFT_A 569
#define EXPRESSION_OP_FUNC__ARSHIFT 570
#define EXPRESSION_OP_FUNC__ARSHIFT_A 571
#define EXPRESSION_OP_FUNC__EQ 572
#define EXPRESSION_OP_FUNC__CEQ 573
#define EXPRESSION_OP_FUNC__LE 574
#define EXPRESSION_OP_FUNC__GE 575
#define EXPRESSION_OP_FUNC__NE 576
#define EXPRESSION_OP_FUNC__CNE 577
#define EXPRESSION_OP_FUNC__LOR 578
#define EXPRESSION_OP_FUNC__LAND 579
#define EXPRESSION_OP_FUNC__COND 580
#define EXPRESSION_OP_FUNC__COND_SEL 581
#define EXPRESSION_OP_FUNC__UINV 582
#define EXPRESSION_OP_FUNC__UAND 583
#define EXPRESSION_OP_FUNC__UNOT 584
#define EXPRESSION_OP_FUNC__UOR 585
#define EXPRESSION_OP_FUNC__UXOR 586
#define EXPRESSION_OP_FUNC__UNAND 587
#define EXPRESSION_OP_FUNC__UNOR 588
#define EXPRESSION_OP_FUNC__UNXOR 589
#define EXPRESSION_OP_FUNC__NULL 590
#define EXPRESSION_OP_FUNC__SIG 591
#define EXPRESSION_OP_FUNC__SBIT 592
#define EXPRESSION_OP_FUNC__MBIT 593
#define EXPRESSION_OP_FUNC__EXPAND 594
#define EXPRESSION_OP_FUNC__LIST 595
#define EXPRESSION_OP_FUNC__CONCAT 596
#define EXPRESSION_OP_FUNC__PEDGE 597
#define EXPRESSION_OP_FUNC__NEDGE 598
#define EXPRESSION_OP_FUNC__AEDGE 599
#define EXPRESSION_OP_FUNC__EOR 600
#define EXPRESSION_OP_FUNC__SLIST 601
#define EXPRESSION_OP_FUNC__DELAY 602
#define EXPRESSION_OP_FUNC__TRIGGER 603
#define EXPRESSION_OP_FUNC__CASE 604
#define EXPRESSION_OP_FUNC__CASEX 605
#define EXPRESSION_OP_FUNC__CASEZ 606
#define EXPRESSION_OP_FUNC__DEFAULT 607
#define EXPRESSION_OP_FUNC__BASSIGN 608
#define EXPRESSION_OP_FUNC__FUNC_CALL 609
#define EXPRESSION_OP_FUNC__TASK_CALL 610
#define EXPRESSION_OP_FUNC__NB_CALL 611
#define EXPRESSION_OP_FUNC__FORK 612
#define EXPRESSION_OP_FUNC__JOIN 613
#define EXPRESSION_OP_FUNC__DISABLE 614
#define EXPRESSION_OP_FUNC__REPEAT 615
#define EXPRESSION_OP_FUNC__EXPONENT 616
#define EXPRESSION_OP_FUNC__PASSIGN 617
#define EXPRESSION_OP_FUNC__MBIT_POS 618
#define EXPRESSION_OP_FUNC__MBIT_NEG 619
#define EXPRESSION_OP_FUNC__NEGATE 620
#define EXPRESSION_OP_FUNC__IINC 621
#define EXPRESSION_OP_FUNC__PINC 622
#define EXPRESSION_OP_FUNC__IDEC 623
#define EXPRESSION_OP_FUNC__PDEC 624
#define EXPRESSION_OP_FUNC__DLY_ASSIGN 625
#define EXPRESSION_OP_FUNC__DLY_OP 626
#define EXPRESSION_OP_FUNC__REPEAT_DLY 627
#define EXPRESSION_OP_FUNC__DIM 628
#define EXPRESSION_OP_FUNC__WAIT 629
#define EXPRESSION_OP_FUNC__FINISH 630
#define EXPRESSION_OP_FUNC__STOP 631
#define EXPRESSION_OPERATE 632
#define EXPRESSION_OPERATE_RECURSIVELY 633
#define EXPRESSION_IS_STATIC_ONLY 634
#define EXPRESSION_IS_ASSIGNED 635
#define EXPRESSION_IS_BIT_SELECT 636
#define EXPRESSION_IS_LAST_SELECT 637
#define EXPRESSION_IS_IN_RASSIGN 638
#define EXPRESSION_SET_ASSIGNED 639
#define EXPRESSION_SET_CHANGED 640
#define EXPRESSION_ASSIGN 641
#define EXPRESSION_DEALLOC 642
#define GEN_ITEM_STRINGIFY 643
#define GEN_ITEM_DISPLAY 644
#define GEN_ITEM_DISPLAY_BLOCK_HELPER 645
#define GEN_ITEM_DISPLAY_BLOCK 646
#define GEN_ITEM_COMPARE 647
#define GEN_ITEM_FIND 648
#define GEN_ITEM_REMOVE_IF_CONTAINS_EXPR_CALLING_STMT 649
#define GEN_ITEM_GET_GENVAR 650
#define GEN_ITEM_VARNAME_CONTAINS_GENVAR 651
#define GEN_ITEM_CALC_SIGNAL_NAME 652
#define GEN_ITEM_CREATE_EXPR 653
#define GEN_ITEM_CREATE_SIG 654
#define GEN_ITEM_CREATE_STMT 655
#define GEN_ITEM_CREATE_INST 656
#define GEN_ITEM_CREATE_TFN 657
#define GEN_ITEM_CREATE_BIND 658
#define GEN_ITEM_RESIZE_STMTS_AND_SIGS 659
#define GEN_ITEM_ASSIGN_IDS 660
#define GEN_ITEM_DB_WRITE 661
#define GEN_ITEM_DB_WRITE_EXPR_TREE 662
#define GEN_ITEM_CONNECT 663
#define GEN_ITEM_RESOLVE 664
#define GEN_ITEM_BIND 665
#define GENERATE_RESOLVE 666
#define GENERATE_REMOVE_STMT_HELPER 667
#define GENERATE_REMOVE_STMT 668
#define GEN_ITEM_DEALLOC 669
#define FSM_VAR_ADD 670
#define FSM_VAR_IS_OUTPUT_STATE 671
#define FSM_VAR_BIND_EXPR 672
#define FSM_VAR_ADD_EXPR 673
#define FSM_VAR_BIND_STMT 674
#define FSM_VAR_BIND_ADD 675
#define FSM_VAR_STMT_ADD 676
#define FSM_VAR_BIND 677
#define FSM_VAR_DEALLOC 678
#define FSM_VAR_REMOVE 679
#define FSM_VAR_CLEANUP 680
#define INSTANCE_DISPLAY_TREE_HELPER 681
#define INSTANCE_DISPLAY_TREE 682
#define INSTANCE_CREATE 683
#define INSTANCE_GEN_SCOPE 684
#define INSTANCE_COMPARE 685
#define INSTANCE_FIND_SCOPE 686
#define INSTANCE_FIND_BY_FUNIT 687
#define INSTANCE_FIND_SIGNAL_BY_EXCLUSION_ID 688
#define INSTANCE_FIND_EXPRESSION_BY_EXCLUSION_ID 689
#define INSTANCE_FIND_FSM_ARC_INDEX_BY_EXCLUSION_ID 690
#define INSTANCE_ADD_CHILD 691
#define INSTANCE_COPY 692
#define INSTANCE_ATTACH_CHILD 693
#define INSTANCE_PARSE_ADD 694
#define INSTANCE_RESOLVE_INST 695
#define INSTANCE_RESOLVE_HELPER 696
#define INSTANCE_RESOLVE 697
#define INSTANCE_READ_ADD 698
#define INSTANCE_DB_WRITE 699
#define INSTANCE_FLATTEN_HELPER 700
#define INSTANCE_FLATTEN 701
#define INSTANCE_REMOVE_STMT_BLKS_CALLING_STMT 702
#define INSTANCE_REMOVE_PARMS_WITH_EXPR 703
#define INSTANCE_DEALLOC_SINGLE 704
#define INSTANCE_DEALLOC_TREE 705
#define INSTANCE_DEALLOC 706
#define VECTOR_INIT 707
#define VECTOR_CREATE 708
#define VECTOR_COPY 709
#define VECTOR_COPY_RANGE 710
#define VECTOR_CLONE 711
#define VECTOR_DB_WRITE 712
#define VECTOR_DB_READ 713
#define VECTOR_DB_MERGE 714
#define VECTOR_MERGE 715
#define VECTOR_GET_EVAL_A 716
#define VECTOR_GET_EVAL_B 717
#define VECTOR_GET_EVAL_C 718
#define VECTOR_GET_EVAL_D 719
#define VECTOR_GET_EVAL_AB_COUNT 720
#define VECTOR_GET_EVAL_ABC_COUNT 721
#define VECTOR_GET_EVAL_ABCD_COUNT 722
#define VECTOR_GET_TOGGLE01_ULONG 723
#define VECTOR_GET_TOGGLE10_ULONG 724
#define VECTOR_DISPLAY_TOGGLE01_ULONG 725
#define VECTOR_DISPLAY_TOGGLE10_ULONG 726
#define VECTOR_TOGGLE_COUNT 727
#define VECTOR_MEM_RW_COUNT 728
#define VECTOR_SET_ASSIGNED 729
#define VECTOR_SET_COVERAGE_AND_ASSIGN 730
#define VECTOR_GET_SIGN_EXTEND_VECTOR_ULONG 731
#define VECTOR_SIGN_EXTEND_ULONG 732
#define VECTOR_LSHIFT_ULONG 733
#define VECTOR_RSHIFT_ULONG 734
#define VECTOR_SET_VALUE 735
#define VECTOR_PART_SELECT_PULL 736
#define VECTOR_PART_SELECT_PUSH 737
#define VECTOR_SET_UNARY_EVALS 738
#define VECTOR_SET_AND_COMB_EVALS 739
#define VECTOR_SET_OR_COMB_EVALS 740
#define VECTOR_SET_OTHER_COMB_EVALS 741
#define VECTOR_IS_UKNOWN 742
#define VECTOR_IS_NOT_ZERO 743
#define VECTOR_SET_TO_X 744
#define VECTOR_TO_INT 745
#define VECTOR_TO_UINT64 746
#define VECTOR_TO_SIM_TIME 747
#define VECTOR_FROM_INT 748
#define VECTOR_FROM_UINT64 749
#define VECTOR_SET_STATIC 750
#define VECTOR_TO_STRING 751
#define VECTOR_FROM_STRING 752
#define VECTOR_VCD_ASSIGN 753
#define VECTOR_BITWISE_AND_OP 754
#define VECTOR_BITWISE_NAND_OP 755
#define VECTOR_BITWISE_OR_OP 756
#define VECTOR_BITWISE_NOR_OP 757
#define VECTOR_BITWISE_XOR_OP 758
#define VECTOR_BITWISE_NXOR_OP 759
#define VECTOR_OP_LT 760
#define VECTOR_OP_LE 761
#define VECTOR_OP_GT 762
#define VECTOR_OP_GE 763
#define VECTOR_OP_EQ 764
#define VECTOR_CEQ_ULONG 765
#define VECTOR_OP_CEQ 766
#define VECTOR_OP_CXEQ 767
#define VECTOR_OP_CZEQ 768
#define VECTOR_OP_NE 769
#define VECTOR_OP_CNE 770
#define VECTOR_OP_LOR 771
#define VECTOR_OP_LAND 772
#define VECTOR_OP_LSHIFT 773
#define VECTOR_OP_RSHIFT 774
#define VECTOR_OP_ARSHIFT 775
#define VECTOR_OP_ADD 776
#define VECTOR_OP_NEGATE 777
#define VECTOR_OP_SUBTRACT 778
#define VECTOR_OP_MULTIPLY 779
#define VECTOR_OP_DIVIDE 780
#define VECTOR_OP_MODULUS 781
#define VECTOR_OP_INC 782
#define VECTOR_OP_DEC 783
#define VECTOR_UNARY_INV 784
#define VECTOR_UNARY_AND 785
#define VECTOR_UNARY_NAND 786
#define VECTOR_UNARY_OR 787
#define VECTOR_UNARY_NOR 788
#define VECTOR_UNARY_XOR 789
#define VECTOR_UNARY_NXOR 790
#define VECTOR_UNARY_NOT 791
#define VECTOR_OP_EXPAND 792
#define VECTOR_OP_LIST 793
#define VECTOR_DEALLOC_VALUE 794
#define VECTOR_DEALLOC 795
#define SYMTABLE_ADD_SYM_SIG 796
#define SYMTABLE_INIT 797
#define SYMTABLE_CREATE 798
#define SYMTABLE_ADD 799
#define SYMTABLE_SET_VALUE 800
#define SYMTABLE_ASSIGN 801
#define SYMTABLE_DEALLOC 802
#define FUNIT_INIT 803
#define FUNIT_CREATE 804
#define FUNIT_GET_CURR_MODULE 805
#define FUNIT_GET_CURR_MODULE_SAFE 806
#define FUNIT_GET_CURR_FUNCTION 807
#define FUNIT_GET_CURR_TASK 808
#define FUNIT_GET_PORT_COUNT 809
#define FUNIT_FIND_PARAM 810
#define FUNIT_FIND_SIGNAL 811
#define FUNIT_REMOVE_STMT_BLKS_CALLING_STMT 812
#define FUNIT_GEN_TASK_FUNCTION_NAMEDBLOCK_NAME 813
#define FUNIT_SIZE_ELEMENTS 814
#define FUNIT_DB_WRITE 815
#define FUNIT_DB_READ 816
#define FUNIT_DB_MERGE 817
#define FUNIT_MERGE 818
#define FUNIT_FLATTEN_NAME 819
#define FUNIT_FIND_BY_ID 820
#define FUNIT_IS_TOP_MODULE 821
#define FUNIT_IS_UNNAMED 822
#define FUNIT_IS_UNNAMED_CHILD_OF 823
#define FUNIT_IS_CHILD_OF 824
#define FUNIT_DISPLAY_SIGNALS 825
#define FUNIT_DISPLAY_EXPRESSIONS 826
#define STATEMENT_ADD_THREAD 827
#define FUNIT_PUSH_THREADS 828
#define STATEMENT_DELETE_THREAD 829
#define FUNIT_CLEAN 830
#define FUNIT_DEALLOC 831
#define ARC_FIND_FROM_STATE 832
#define ARC_FIND_TO_STATE 833
#define ARC_FIND_ARC 834
#define ARC_FIND_ARC_BY_EXCLUSION_ID 835
#define ARC_CREATE 836
#define ARC_ADD 837
#define ARC_STATE_HITS 838
#define ARC_TRANSITION_HITS 839
#define ARC_TRANSITION_EXCLUDED 840
#define ARC_GET_STATS 841
#define ARC_DB_WRITE 842
#define ARC_DB_READ 843
#define ARC_DB_MERGE 844
#define ARC_MERGE 845
#define ARC_GET_STATES 846
#define ARC_GET_TRANSITIONS 847
#define ARC_ARE_ANY_EXCLUDED 848
#define ARC_DEALLOC 849
#define FUNC_ITER_DISPLAY 850
#define FUNC_ITER_SORT 851
#define FUNC_ITER_COUNT_STMT_ITERS 852
#define FUNC_ITER_ADD_STMT_ITERS 853
#define FUNC_ITER_ADD_SIG_LINKS 854
#define FUNC_ITER_INIT 855
#define FUNC_ITER_GET_NEXT_STATEMENT 856
#define FUNC_ITER_GET_NEXT_SIGNAL 857
#define FUNC_ITER_DEALLOC 858
#define EXCLUDE_EXPR_ASSIGN_AND_RECALC 859
#define EXCLUDE_SIG_ASSIGN_AND_RECALC 860
#define EXCLUDE_ARC_ASSIGN_AND_RECALC 861
#define EXCLUDE_ADD_EXCLUDE_REASON 862
#define EXCLUDE_REMOVE_EXCLUDE_REASON 863
#define EXCLUDE_IS_LINE_EXCLUDED 864
#define EXCLUDE_SET_LINE_EXCLUDE 865
#define EXCLUDE_IS_TOGGLE_EXCLUDED 866
#define EXCLUDE_SET_TOGGLE_EXCLUDE 867
#define EXCLUDE_IS_COMB_EXCLUDED 868
#define EXCLUDE_SET_COMB_EXCLUDE 869
#define EXCLUDE_IS_FSM_EXCLUDED 870
#define EXCLUDE_SET_FSM_EXCLUDE 871
#define EXCLUDE_IS_ASSERT_EXCLUDED 872
#define EXCLUDE_SET_ASSERT_EXCLUDE 873
#define EXCLUDE_FIND_EXCLUDE_REASON 874
#define EXCLUDE_DB_WRITE 875
#define EXCLUDE_DB_READ 876
#define EXCLUDE_FIND_SIGNAL 877
#define EXCLUDE_FIND_EXPRESSION 878
#define EXCLUDE_FIND_FSM_ARC 879
#define EXCLUDE_FORMAT_REASON 880
#define EXCLUDED_GET_MESSAGE 881
#define EXCLUDE_HANDLE_EXCLUDE_REASON 882
#define EXCLUDE_PRINT_EXCLUSION 883
#define EXCLUDE_LINE_FROM_ID 884
#define EXCLUDE_TOGGLE_FROM_ID 885
#define EXCLUDE_MEMORY_FROM_ID 886
#define EXCLUDE_EXPR_FROM_ID 887
#define EXCLUDE_FSM_FROM_ID 888
#define EXCLUDE_ASSERT_FROM_ID 889
#define EXCLUDE_APPLY_EXCLUSIONS 890
#define COMMAND_EXCLUDE 891
#define RACE_BLK_CREATE 892
#define RACE_FIND_HEAD_STATEMENT_CONTAINING_STATEMENT_HELPER 893
#define RACE_FIND_HEAD_STATEMENT_CONTAINING_STATEMENT 894
#define RACE_GET_HEAD_STATEMENT 895
#define RACE_FIND_HEAD_STATEMENT 896
#define RACE_CALC_STMT_BLK_TYPE 897
#define RACE_CALC_EXPR_ASSIGNMENT 898
#define RACE_CALC_ASSIGNMENTS 899
#define RACE_HANDLE_RACE_CONDITION 900
#define RACE_CHECK_ASSIGNMENT_TYPES 901
#define RACE_CHECK_ONE_BLOCK_ASSIGNMENT 902
#define RACE_CHECK_RACE_COUNT 903
#define RACE_CHECK_MODULES 904
#define RACE_DB_WRITE 905
#define RACE_DB_READ 906
#define RACE_GET_STATS 907
#define RACE_REPORT_SUMMARY 908
#define RACE_REPORT_VERBOSE 909
#define RACE_REPORT 910
#define RACE_COLLECT_LINES 911
#define RACE_BLK_DELETE_LIST 912
#define STATISTIC_CREATE 913
#define STATISTIC_IS_EMPTY 914
#define STATISTIC_DEALLOC 915
#define TCL_FUNC_GET_RACE_REASON_MSGS 916
#define TCL_FUNC_GET_FUNIT_LIST 917
#define TCL_FUNC_GET_INSTANCES 918
#define TCL_FUNC_GET_INSTANCE_LIST 919
#define TCL_FUNC_IS_FUNIT 920
#define TCL_FUNC_GET_FUNIT 921
#define TCL_FUNC_GET_INST 922
#define TCL_FUNC_GET_FUNIT_NAME 923
#define TCL_FUNC_GET_FILENAME 924
#define TCL_FUNC_INST_SCOPE 925
#define TCL_FUNC_GET_FUNIT_START_AND_END 926
#define TCL_FUNC_COLLECT_UNCOVERED_LINES 927
#define TCL_FUNC_COLLECT_COVERED_LINES 928
#define TCL_FUNC_COLLECT_RACE_LINES 929
#define TCL_FUNC_COLLECT_UNCOVERED_TOGGLES 930
#define TCL_FUNC_COLLECT_COVERED_TOGGLES 931
#define TCL_FUNC_COLLECT_UNCOVERED_MEMORIES 932
#define TCL_FUNC_COLLECT_COVERED_MEMORIES 933
#define TCL_FUNC_GET_TOGGLE_COVERAGE 934
#define TCL_FUNC_GET_MEMORY_COVERAGE 935
#define TCL_FUNC_COLLECT_UNCOVERED_COMBS 936
#define TCL_FUNC_COLLECT_COVERED_COMBS 937
#define TCL_FUNC_GET_COMB_EXPRESSION 938
#define TCL_FUNC_GET_COMB_COVERAGE 939
#define TCL_FUNC_COLLECT_UNCOVERED_FSMS 940
#define TCL_FUNC_COLLECT_COVERED_FSMS 941
#define TCL_FUNC_GET_FSM_COVERAGE 942
#define TCL_FUNC_COLLECT_UNCOVERED_ASSERTIONS 943
#define TCL_FUNC_COLLECT_COVERED_ASSERTIONS 944
#define TCL_FUNC_GET_ASSERT_COVERAGE 945
#define TCL_FUNC_OPEN_CDD 946
#define TCL_FUNC_CLOSE_CDD 947
#define TCL_FUNC_SAVE_CDD 948
#define TCL_FUNC_MERGE_CDD 949
#define TCL_FUNC_GET_LINE_SUMMARY 950
#define TCL_FUNC_GET_TOGGLE_SUMMARY 951
#define TCL_FUNC_GET_MEMORY_SUMMARY 952
#define TCL_FUNC_GET_COMB_SUMMARY 953
#define TCL_FUNC_GET_FSM_SUMMARY 954
#define TCL_FUNC_GET_ASSERT_SUMMARY 955
#define TCL_FUNC_PREPROCESS_VERILOG 956
#define TCL_FUNC_GET_SCORE_PATH 957
#define TCL_FUNC_GET_INCLUDE_PATHNAME 958
#define TCL_FUNC_GET_GENERATION 959
#define TCL_FUNC_SET_LINE_EXCLUDE 960
#define TCL_FUNC_SET_TOGGLE_EXCLUDE 961
#define TCL_FUNC_SET_MEMORY_EXCLUDE 962
#define TCL_FUNC_SET_COMB_EXCLUDE 963
#define TCL_FUNC_FSM_EXCLUDE 964
#define TCL_FUNC_SET_ASSERT_EXCLUDE 965
#define TCL_FUNC_GENERATE_REPORT 966
#define TCL_FUNC_INITIALIZE 967
#define STATIC_EXPR_GEN_UNARY 968
#define STATIC_EXPR_GEN 969
#define STATIC_EXPR_CALC_LSB_AND_WIDTH_PRE 970
#define STATIC_EXPR_CALC_LSB_AND_WIDTH_POST 971
#define STATIC_EXPR_DEALLOC 972
#define VCDID 973
#define VCD_CALLBACK 974
#define LXT_PARSE 975
#define COMMAND_MERGE 976
#define LINE_GET_STATS 977
#define LINE_COLLECT 978
#define LINE_GET_FUNIT_SUMMARY 979
#define LINE_GET_INST_SUMMARY 980
#define LINE_DISPLAY_INSTANCE_SUMMARY 981
#define LINE_INSTANCE_SUMMARY 982
#define LINE_DISPLAY_FUNIT_SUMMARY 983
#define LINE_FUNIT_SUMMARY 984
#define LINE_DISPLAY_VERBOSE 985
#define LINE_INSTANCE_VERBOSE 986
#define LINE_FUNIT_VERBOSE 987
#define LINE_REPORT 988

extern profiler profiles[NUM_PROFILES];
#endif

extern unsigned int profile_index;

#endif

