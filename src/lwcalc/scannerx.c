/* Generated by re2c 0.13.6.dev on Sun Dec 16 03:04:59 2012 */
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
	
		
		{
			YYCTYPE yych;

			yych = *YYCURSOR;
			switch (yych) {
			case 0x00:	goto yy20;
			case '\t':
			case '\n':
			case '\f':
			case '\r':
			case ' ':	goto yy2;
			case '(':	goto yy16;
			case ')':	goto yy18;
			case '*':	goto yy12;
			case '+':	goto yy8;
			case '-':	goto yy10;
			case '.':	goto yy6;
			case '/':	goto yy14;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy4;
			default:	goto yy22;
			}
yy2:
			++YYCURSOR;
			{ continue; }
yy4:
			yych = *(YYMARKER = ++YYCURSOR);
			goto yy29;
yy5:
			{
			return create_int_token(capture_int(state));
		}
yy6:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy23;
			default:	goto yy7;
			}
yy7:
			{ 
			printf( "Unrecognized character: %c\n", *(state->ccursor) );
			continue;
			}
yy8:
			++YYCURSOR;
			{ return create_token(TOKEN_ADD); }
yy10:
			++YYCURSOR;
			{ return create_token(TOKEN_SUB); }
yy12:
			++YYCURSOR;
			{ return create_token(TOKEN_MUL); }
yy14:
			++YYCURSOR;
			{ return create_token(TOKEN_DIV); }
yy16:
			++YYCURSOR;
			{ return create_token(TOKEN_LPAREN); }
yy18:
			++YYCURSOR;
			{ return create_token(TOKEN_RPAREN); }
yy20:
			++YYCURSOR;
			{ return NULL; }
yy22:
			yych = *++YYCURSOR;
			goto yy7;
yy23:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy23;
			default:	goto yy25;
			}
yy25:
			{
			return create_float_token(capture_float(state));
		}
yy26:
			yych = *++YYCURSOR;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy23;
			default:	goto yy27;
			}
yy27:
			YYCURSOR = YYMARKER;
			goto yy5;
yy28:
			YYMARKER = ++YYCURSOR;
			yych = *YYCURSOR;
yy29:
			switch (yych) {
			case '.':	goto yy26;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy28;
			default:	goto yy5;
			}
		}

	}
}
