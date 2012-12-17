%include {
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "parser.h"
#include "calculator.h"
}

%parse_accept {
	printf("parsing complete!\n");
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
%default_type {scanner_token*}
%type expr {scanner_token*}
%type INTEGER {scanner_token*}
%type FLOAT {scanner_token*}
%left ADD SUB.
%left MUL DIV.
%syntax_error {printf("syntax error\n");}

//in ::= expr(A). {printf("result = %d\n", A->data.n);}
in ::= expr.

expr(A) ::= INTEGER(B). { A = set_int(pCalc, B); }
expr(A) ::= FLOAT(B). { A = set_float(pCalc, B); }

expr(A) ::= expr(B) ADD expr(C). {A = add(pCalc, B, C);}
expr(A) ::= expr(B) SUB expr(C). {A = subtract(pCalc, B, C);}
expr(A) ::= expr(B) MUL expr(C). {A = multiply(pCalc, B, C);}
expr(A) ::= expr(B) DIV expr(C). {A = divide(pCalc, B, C);}

expr(A) ::= LPAREN expr(B) RPAREN. { A = B; }