#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @head: head
 * @count: line_number
*/
void add(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, a;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	a = h->n + h->next->n;
	h->next->n = a;
	*head = h->next;
	free(h);
}
