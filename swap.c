#include "monty.h"
/**
 * swap - add the top two elements of the stack.
 * @head: head
 * @count: line number
*/
void swap(stack_t **head, unsigned int count)
{
	stack_t *h;
	int i = 0, a;

	h = *head;
	while (h)
	{
		h = h->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	a = h->n;
	h->n = h->next->n;
	h->next->n = a;
}
