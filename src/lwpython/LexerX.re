#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lexer.h"

Token *Lexer::scan() {

#define YYCTYPE char
#define YYCURSOR (this->cursor)
#define YYLIMIT (this->lim)
#define YYMARKER (this->marker)
#define	YYFILL(n) {fill();}

	for(;;) {
		capture_begin();
	
		/*!re2c
		NAME = [a-zA-Z]+;
		D = [0-9];
		INTEGER = D+;
		FLOAT = D* "." D+;		        
        WS = [ \t\f];
        NEWLINE = [\r\n];
        ANY = [^];

		"def" { return create_token(TOKEN_DEF); }
		
		"pass" { return create_token(TOKEN_PASS); }

		NAME { return create_name_token(capture_string()); }

		INTEGER { return create_int_token(capture_int()); }
        
		FLOAT { return create_float_token(capture_float()); }
		
		"," { return create_token(TOKEN_COMMA); }
		
		":" { return create_token(TOKEN_COLON); }
				
		"+" { return create_token(TOKEN_ADD); }

		"-" { return create_token(TOKEN_SUB); }

		"*" { return create_token(TOKEN_MUL); }

		"/" { return create_token(TOKEN_DIV); }

		"(" { return create_token(TOKEN_LPAREN); }

		")" { return create_token(TOKEN_RPAREN); }
		
		"\000" { return create_token(TOKEN_EOF); }
		
		NEWLINE { return emit_newline(); }
		
        WS { continue; }

		ANY { 
			printf( "Unrecognized character: %c\n", *(this->ccursor) );
			continue;
		}
		*/
	}
}
