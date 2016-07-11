#include "BinaryTree.h"
#include "SinglyLinkedList.h"

#include <stdio.h>

void printInt(int value) {
	printf("%d ", value);
}

void testBTree() {
	printf("BTree Test\n");
	printf("----------\n");

	struct btree *t = createBTree(10);
	insertBTree(&t, 5);
	insertBTree(&t, 15);

	insertBTree(&t, 4);
	insertBTree(&t, 6);

	insertBTree(&t, 14);
	insertBTree(&t, 16);

	printf("Preorder: ");
	preorderBTree(t, &printInt);
	printf("\n");

	printf("Inorder: ");
	inorderBTree(t, &printInt);
	printf("\n");

	printf("Postorder: ");
	postorderBTree(t, &printInt);
	printf("\n");

	deleteBTree(t);
}

void testSinglyLinkedList() {
	printf("Singly LinkedList Test\n");
	printf("----------------------\n");

	struct sllnode *head = NULL;
	appendSLList(&head, 10);
	appendSLList(&head, 5);
	appendSLList(&head, 1);

	foreachSLL(head, printInt);

	deleteSLList(head);
}

int main(int argc, const char * argv[]) {

	testBTree();
	printf("\n");

	testSinglyLinkedList();
	printf("\n");

	return 0;
}