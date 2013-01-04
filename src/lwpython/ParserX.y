%include {
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "parser.h"
}

%parse_accept {
	//printf("Parsing complete!\n");
}
%syntax_error {
	fprintf(stderr, "Syntax error\n");
}
%parse_failure {
	fprintf(stderr,"Giving up.  Parser is hopelessly lost...\n");
}
%stack_overflow {
	fprintf(stderr,"Giving up.  Parser stack overflow\n");
}
%extra_argument { compiler *pComp}
%token_prefix TOKEN_
%token_type {scanner_token*}
%default_type {ast_node*}
%type expr {ast_node*}

%type INTEGER {scanner_token*}
%type FLOAT {scanner_token*}
%left ADD SUB.
%left MUL DIV.

//file_input ::= (NEWLINE | stmt)* ENDMARKER.
//file_input ::= NEWLINE.
file_input ::= stmt.
stmt ::= simple_stmt.
stmt ::= compound_stmt.
simple_stmt ::= small_stmt.
//simple_stmt ::= small_stmt (';' small_stmt)* [';'] NEWLINE
//small_stmt: (expr_stmt | print_stmt  | del_stmt | pass_stmt | flow_stmt | import_stmt | global_stmt | exec_stmt | assert_stmt)
small_stmt ::= pass_stmt.
pass_stmt ::= PASS.

//
//compound_stmt: if_stmt | while_stmt | for_stmt | try_stmt | with_stmt | funcdef | classdef | decorated
compound_stmt ::= funcdef.
funcdef ::= DEF NAME parameters COLON suite.
parameters ::= LPAREN varargslist RPAREN.
parameters ::= LPAREN RPAREN.

/*varargslist: ((fpdef ['=' test] ',')*
              ('*' NAME [',' '**' NAME] | '**' NAME) |
              fpdef ['=' test] (',' fpdef ['=' test])* [','])
fpdef: NAME | '(' fplist ')'
fplist: fpdef (',' fpdef)* [',']*/

varargslist ::= fpdef.
fpdef ::= NAME.
fpdef ::= LPAREN fplist RPAREN.
fplist ::= fpdef.
fplist ::= fpdef COMMA fpdef.

suite ::= simple_stmt.
//suite ::= NEWLINE INDENT stmt+ DEDENT.
suite ::= NEWLINE INDENT stmt DEDENT.