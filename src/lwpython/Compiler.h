#ifndef _COMPILER_H
#define _COMPILER_H

#include "Ast.h"

class Compiler {
public:
	AstNode *ast;
	char* errormsg;
	//
	void clear();
	int compile_file(char* s);
	void error(char *errmsg);
} ;

#endif //_COMPILER_H
