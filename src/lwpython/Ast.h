#ifndef _AST_H
#define _AST_H

#include "Token.h"

enum AstKind {
	AST_LITERAL,
	AST_BINARY
};

struct AstNode {
	enum AstKind kind;
	Token *token;
	union {
		struct {
			AstNode *left;
			AstNode *right;
		} binary;
	} node ;
};

AstNode* create_literal_ast(Token *token);
AstNode* create_binary_ast(Token *token, AstNode* left, AstNode* right);

#endif //_AST_H