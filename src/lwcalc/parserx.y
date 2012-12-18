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
%extra_argument { calculator *pCalc}
%token_prefix TOKEN_
%token_type {scanner_token*}
%default_type {ast_node*}
%type expr {ast_node*}
%type INTEGER {scanner_token*}
%type FLOAT {scanner_token*}
%left ADD SUB.
%left MUL DIV.

in ::= expr(A). {pCalc->ast = A;}

expr(A) ::= INTEGER(B). { A = create_literal_ast(B); }
expr(A) ::= FLOAT(B). { A = create_literal_ast(B); }

expr(A) ::= expr(B) ADD(T) expr(C). {A = create_binary_ast(T, B, C);}
expr(A) ::= expr(B) SUB(T) expr(C). {A = create_binary_ast(T, B, C);}
expr(A) ::= expr(B) MUL(T) expr(C). {A = create_binary_ast(T, B, C);}
expr(A) ::= expr(B) DIV(T) expr(C). {A = create_binary_ast(T, B, C);}

expr(A) ::= LPAREN expr(B) RPAREN. { A = B; }