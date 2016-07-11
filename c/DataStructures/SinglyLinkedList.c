#include <stdlib.h>

#include "SinglyLinkedList.h"

struct sllnode *createSLList(int value) {
	struct sllnode *rtn = malloc(sizeof(struct sllnode));
	rtn->value = value;
	rtn->next = NULL;

	return rtn;
}

void deleteSLList(struct sllnode *head) {
	struct sllnode *curr = head;
	struct sllnode *next = NULL;

	while (curr != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void appendSLList(struct sllnode **head, int value) {
	struct sllnode *newNode = createSLList(value);
	struct sllnode *curr = *head;

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	while (curr != NULL) {
		if (curr->next == NULL) {
			curr->next = newNode;
			break;
		}
		curr = curr->next;
	}
}

void foreachSLL(struct sllnode *head, visitSLL visitor) {
	struct sllnode *next = head;
	while (next != NULL) {
		visitor(next->value);
		next = next->next;
	}
}

//TODO create sort
//TODO create find
