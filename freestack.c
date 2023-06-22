#include "monty.h"
/**
* free_stack - free a doubly linked list
* @head: head
*/
void free_stack(stack_t *head)
{
	stack_t *a;

	a = head;
	while (head)
	{
		a = head->next;
		free(head);
		head = a;
	}
}
