

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "list.h"

BST create_bst()
{
	BST temp;
	temp.root = NULL;
	return temp;
}



BSTNodePtr insert_bst_node(BSTNodePtr self, TaxRecordPtr n)
{
	if (self == NULL) {
		self = malloc(sizeof *self);
		self->data = n;
		self->left = self->right = NULL;
	}
	else if (n->tfn < self->data->tfn) {
		self->left = insert_bst_node(self->left, n);
	}
	else if (n->tfn > self->data->tfn) {
		self->right = insert_bst_node(self->right, n);
	}
	return self;
	
}
void insert_bst(BST *self, TaxRecordPtr n) {
	self->root = insert_bst_node(self->root, n);
}

BSTNodePtr find_bst_node(BSTNodePtr self, long n) {
	
	if  (n == self->data->tfn) {
		return self;
	} else if (n < self->data->tfn) {
		if (self->left == NULL)
			return NULL;
		return find_bst_node(self->left, n);
	}
	else {
		if (self->right == NULL)
			return NULL;
		return find_bst_node(self->right, n);
	}
}

BSTNodePtr find_bst(BST *self, long n) {
	return find_bst_node(self->root, n);
}

