#ifndef _LEMON_PARSER_H
#define _LEMON_PARSER_H

#include "scanner.h"
#include "parserx.h"
#include "calculator.h"

int parse_math_expr(char* s, calculator* pCalc);

void *ParseAlloc(void *(*mallocProc)(size_t));
void ParseTrace(FILE *TraceFILE, char *zTracePrompt);
void Parse(void*,int,scanner_token*, calculator*);
void ParseFree(void *p, void (*freeProc)(void*));
#endif