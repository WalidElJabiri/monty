#include "monty.h"
#include <string.h>

int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_stack(stack_t **stack);

/**
 * init_stack - Initializes a stack_t stack
 * @stack: A p to an unitialized stack_t stack.
 * Return: If an error occurs EXIT_FAILURE. Otherwise EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *st;

	st = malloc(sizeof(stack_t));
	if (st == NULL)
		return (malloc_error());

	st->n = STACK;
	st->prev = NULL;
	st->next = NULL;
	*stack = st;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue
 * @stack: A p to the top (stack) or bottom (queue)
 * Return: If the stack_t is in stack  - STACK 0.
 *         If the stack_t is in queue  - QUEUE 1.
 *         Otherwise  2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

/**
 * free_stack - Frees a stack_t stack
 * @stack: A p to the top or bottom of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
