#pragma once

#include <stdlib.h>

struct sllnode {
	int value;
	struct sllnode *next;
};

struct sllnode *createSLList(int value);
void deleteSLList(struct sllnode *head);

void appendSLList(struct sllnode **head, int value);

typedef void(*visitSLL)(int);

void foreachSLL(struct sllnode *head, visitSLL visitor);

//TODO create sort
//TODO create find

