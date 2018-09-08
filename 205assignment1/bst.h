
#include <stdbool.h>
#include "list.h"

typedef struct taxRecord {
	long tfn;
	char *name;
	List welfare;
	List tax;
} *TaxRecordPtr;

typedef struct bstNode {
	TaxRecordPtr data;
	struct bstNode *left;
	struct bstNode *right;
} *BSTNodePtr;

typedef struct bst {
	BSTNodePtr root;
} BST;

BST create_bst();
BSTNodePtr insert_bst_node(BSTNodePtr self, TaxRecordPtr n);
void insert_bst(BST *self, TaxRecordPtr n);
BSTNodePtr find_bst_node(BSTNodePtr self, long n);
BSTNodePtr find_bst(BST *self, long n);
