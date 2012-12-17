#ifndef _AST_H
#define _AST_H

#include "token.h"

enum ast_kind {
	AST_LITERAL,
	AST_BINARY
};
typedef struct _ast_node {
	enum ast_kind kind;
	scanner_token *token;
	union {
		struct {
			struct _ast_node *left;
			struct _ast_node *right;
		} binary;
	} node ;
} ast_node;

ast_node* create_literal_ast(scanner_token *token);
ast_node* create_binary_ast(scanner_token *token, ast_node* left, ast_node* right);

#endif //_AST_H