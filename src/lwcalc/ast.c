#include "ast.h"
#include "malloc.h"

ast_node* create_literal_ast(scanner_token *token){
	ast_node* node = malloc(sizeof(ast_node));
	node->kind = AST_LITERAL;
	node->token = token;
	return node;
}
ast_node* create_binary_ast(scanner_token *token, ast_node* left, ast_node* right){
	ast_node* node = malloc(sizeof(ast_node));
	node->kind = AST_BINARY;
	node->token = token;
	node->node.binary.left = left;
	node->node.binary.right = right;
	return node;
}