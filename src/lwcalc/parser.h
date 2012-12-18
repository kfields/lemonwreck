#ifndef _PARSER_H
#define _PARSER_H

#include "ast.h"
#include "scanner.h"
#include "parserx.h"
#include "calculator.h"

void *ParseAlloc(void *(*mallocProc)(size_t));
void ParseTrace(FILE *TraceFILE, char *zTracePrompt);
void Parse(void*,int,scanner_token*, calculator*);
void ParseFree(void *p, void (*freeProc)(void*));
#endif