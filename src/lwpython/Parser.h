#ifndef _PARSER_H
#define _PARSER_H

#include "ast.h"
#include "Lexer.h"
#include "parserx.h"
#include "compiler.h"

extern "C" {
	void *ParseAlloc(void *(*mallocProc)(size_t));
	void ParseTrace(FILE *TraceFILE, char *zTracePrompt);
	void Parse(void*,int,scanner_token*, compiler*);
	void ParseFree(void *p, void (*freeProc)(void*));
}
#endif