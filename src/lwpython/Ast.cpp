#include "Ast.h"
#include "malloc.h"

AstNode* create_literal_ast(Token *token)
{
	AstNode* node = new AstNode();
	node->kind = AST_LITERAL;
	node->token = token;
	return node;
}
AstNode* create_binary_ast(Token *token, AstNode* left, AstNode* right)
{
	AstNode* node = new AstNode();
	node->kind = AST_BINARY;
	node->token = token;
	node->node.binary.left = left;
	node->node.binary.right = right;
	return node;
}