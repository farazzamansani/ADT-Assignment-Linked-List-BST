#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "list.h"

insert_at_front(List *self, int b) {
	ListNodePtr new_node = malloc(sizeof *new_node);
	new_node->data = b;
	new_node->next = self->head;
	self->head = new_node;
}


List create_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

void print_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%d \n", current->data);
		current = current->next;
	}
	printf("\n");
}

search_list(List *a, int b)
{
	ListNodePtr current = a->head;
	while (current != NULL) {
		if (current->data == b)
		{
			return 0;
		}
		current = current->next;
	}
	return 1;
}


void destroy_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free);
	}
	self->head = NULL;
}

List merge_lists(List *a, List *b) {
	List temp=create_list();
	
	ListNodePtr currenta = a->head;
	ListNodePtr currentb = b->head;
	while (currenta != NULL)
	{
		while (currentb != NULL)
		{
			if (currenta->data == currentb->data)
				insert_at_front(&temp, currenta->data);
			currentb = currentb->next;
		}
		currentb = b->head;
		currenta = currenta->next;
	}
	return temp;
}


