#pragma once
#include <stdbool.h>


typedef struct listNode {
	int data;
	struct listNode *next;
} *ListNodePtr;

typedef struct list {
	ListNodePtr head;
} List;

List create_list();
void print_list(List *self);
int search_list(List *a, int b);
List merge_lists(List *a, List *b);