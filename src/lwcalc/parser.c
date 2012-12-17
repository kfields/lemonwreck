
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "parser.h"

int parse_math_expr(char* s, calculator* pCalc) {
	scanner_token *token;
	scanner_state *state;

	void* pParser = ParseAlloc(malloc);
	ParseTrace(stdout, ">>");

	state = malloc(sizeof(scanner_state));

	state->cursor = s;

	for(;;) {
		token = scan(state);
		if(token == NULL) break;
		Parse(pParser, token->kind, token, pCalc);
	}
	Parse(pParser, 0, 0, pCalc);
	ParseFree(pParser, free);
	return 0;
}
