#include "monty.h"
/**
 * pall - print the stack
 * @head: stack head
 * @count: counter
*/
void pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
