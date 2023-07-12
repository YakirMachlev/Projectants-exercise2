#ifndef LINEAR_LINKED_LIST
	#define LINEAR_LINKED_LIST

	#include <stdio.h>
	#include <stdlib.h>

	typedef enum{FALSE, TRUE}bool;

	#define LLL_TYPE char*

	typedef struct LinearLinkedListNode
	{
		LLL_TYPE info;
		struct LinearLinkedListNode* nextAddress;
	}
	LinearLinkedListNode;

	void push_linear_linked_list(LinearLinkedListNode**);
	void insert_after_node_linear_linked_list(LinearLinkedListNode*);
	void pop_linear_linked_list(LinearLinkedListNode**);
	void delete_after_node_linear_linked_list(LinearLinkedListNode*);
	LinearLinkedListNode* search_node_linear_linked_list(LinearLinkedListNode*, int);
	void print_linear_linked_list(LinearLinkedListNode*);
	void free_linear_linked_list(LinearLinkedListNode**);
#endif