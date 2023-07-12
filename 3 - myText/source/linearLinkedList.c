#include "linearLinkedList.h"

void push_linear_linked_list(LinearLinkedListNode** manager)
{
	LinearLinkedListNode* newNode;
	newNode = (LinearLinkedListNode*)malloc(sizeof(LinearLinkedListNode));
	newNode->nextAddress = *manager;
	*manager = newNode;
}

void insert_after_node_linear_linked_list(LinearLinkedListNode* node)
{
	LinearLinkedListNode* newNode;
	newNode = (LinearLinkedListNode*)malloc(sizeof(LinearLinkedListNode));
	newNode->nextAddress = node->nextAddress;
	node->nextAddress = newNode;
}

void pop_linear_linked_list(LinearLinkedListNode** manager)
{
	LinearLinkedListNode* tempNode;
	tempNode = *manager;
	*manager = (*manager)->nextAddress;
	free(tempNode);
}

void delete_after_node_linear_linked_list(LinearLinkedListNode* node)
{
	LinearLinkedListNode* tempNode;
	tempNode = node->nextAddress;
	node->nextAddress = tempNode->nextAddress;
	free(tempNode);
}

LinearLinkedListNode* search_node_linear_linked_list(LinearLinkedListNode* manager, int num)
{
	LinearLinkedListNode* currentNode;
	int offset;
	currentNode = manager;

	for (offset = 1; offset < num; offset++)
		currentNode = currentNode->nextAddress;

	return currentNode;
}

void print_linear_linked_list(LinearLinkedListNode* manager)
{
	LinearLinkedListNode* currentNode;
	currentNode = manager;

	while (currentNode)
	{
		printf("%s\n", currentNode->info);
		currentNode = currentNode->nextAddress;
	}
	printf("\n");
}

void free_linear_linked_list(LinearLinkedListNode** manager)
{
	LinearLinkedListNode** start;
	start = manager;

	while (*start)
	{
		pop_linear_linked_list(start);
	}
}