#include <stdlib.h>

#include "BinaryTree.h"

struct btree *createBTree(int value) {
	struct btree *rtn = malloc(sizeof(struct btree));
	rtn->value = value;
	rtn->left = NULL;
	rtn->right = NULL;

	return rtn;
}

void deleteBTree(struct btree *node) {
	if (node != NULL) {
		deleteBTree(node->left);
		deleteBTree(node->right);
		free(node);
	}
}

void insertBTree(struct btree **node, int value) {
	if (*node == NULL) {
		*node = createBTree(value);
		return;
	}

	if (value < (*node)->value) {
		insertBTree(&(*node)->left, value);
	}
	else {
		insertBTree(&(*node)->right, value);
	}
}

struct btree *findBTree(struct btree *node, int value) {
	if (node == NULL) {
		return NULL;
	}

	if (node->value == value) {
		return node;
	}
	else if (value < node->value) {
		return findBTree(node->left, value);
	}
	
	return findBTree(node->right, value);
}

void preorderBTree(struct btree *node, visitBTree visitor) {
	if (node == NULL) {
		return;
	}

	visitor(node->value);
	preorderBTree(node->left, visitor);
	preorderBTree(node->right, visitor);
}

void inorderBTree(struct btree *node, visitBTree visitor) {
	if (node == NULL) {
		return;
	}

	inorderBTree(node->left, visitor);
	visitor(node->value);
	inorderBTree(node->right, visitor);
}

void postorderBTree(struct btree *node, visitBTree visitor) {
	if (node == NULL) {
		return;
	}

	postorderBTree(node->left, visitor);
	postorderBTree(node->right, visitor);
	visitor(node->value);
}
