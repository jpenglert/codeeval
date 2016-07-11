#pragma once

// A simple binary tree.
// Modify value type as needed.

struct btree {
	int value;
	struct btree *left;
	struct btree *right;
};

struct btree *createBTree(int value);
void deleteBTree(struct btree *node);

void insertBTree(struct btree **node, int value);

struct btree *findBTree(struct btree *node, int value);

typedef void(*visitBTree)(int);

void preorderBTree(struct btree *node, visitBTree visitor);
void inorderBTree(struct btree *node, visitBTree visitor);
void postorderBTree(struct btree *node, visitBTree visitor);

