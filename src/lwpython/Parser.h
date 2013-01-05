#ifndef _PARSER_H
#define _PARSER_H

#include "Ast.h"
#include "Lexer.h"
#include "ParserX.h"
#include "Compiler.h"

extern "C" {
	void *ParseAlloc(void *(*mallocProc)(size_t));
	void ParseTrace(FILE *TraceFILE, char *zTracePrompt);
	void Parse(void*, int, Token*, Compiler*);
	void ParseFree(void *p, void (*freeProc)(void*));
}
#endif