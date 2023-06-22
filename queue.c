#include "monty.h"
/**
 * queue - print the top
 * @head: head
 * @count: line number
*/
void queue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail of the stack
 * @n: new value
 * @head: head
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *a;

	a = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (a)
	{
		while (a->next)
			a = a->next;
	}
	if (!a)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		a->next = new_node;
		new_node->prev = a;
	}
}
