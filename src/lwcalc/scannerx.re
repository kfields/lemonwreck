#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"

scanner_token *scan(scanner_state *state) {

#define YYCTYPE char
#define YYCURSOR (state->cursor)
#define YYLIMIT (state->limit)
#define YYMARKER (state->marker)

	capture_begin(state);

	for(;;) {
	
		/*!re2c
		
		re2c:indent:top = 2;
		re2c:yyfill:enable = 0;
		
		D = [0-9];
		INTEGER = D+;
		FLOAT = D* "." D+;		        
        WS = [ \r\n\t\f];
        ANY = [^];

		INTEGER { return create_int_token(capture_int(state)); }
        
		FLOAT { return create_float_token(capture_float(state)); }
		
		"+" { return create_token(TOKEN_ADD); }

		"-" { return create_token(TOKEN_SUB); }

		"*" { return create_token(TOKEN_MUL); }

		"/" { return create_token(TOKEN_DIV); }

		"(" { return create_token(TOKEN_LPAREN); }

		")" { return create_token(TOKEN_RPAREN); }
		
		"\000" { return NULL; }

        WS { continue; }

		ANY { 
			printf( "Unrecognized character: %c\n", *(state->ccursor) );
			continue;
			}
		*/
	}
}
