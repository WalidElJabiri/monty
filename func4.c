#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/**
 * rotl - Rotates the top value of a stack_t linked list
 * @stack: A p to the top mode node of a stack_t linked list.
 * @line_number: The current working line num of a Monty bytecodes file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bot;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bot = (*stack)->next;
	while (bot->next != NULL)
		bot = bot->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bot->next = top;
	top->next = NULL;
	top->prev = bot;

	(void)line_number;
}

/**
 * rotr - Rotates the bottom value of a stack_t linked list
 * @stack: A p to the top mode node of a stack_t linked list.
 * @line_number: The current working line num of a Monty bytecodes file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bot;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bot = (*stack)->next;
	while (bot->next != NULL)
		bot = bot->next;

	bot->prev->next = NULL;
	(*stack)->next = bot;
	bot->prev = *stack;
	bot->next = top;
	top->prev = bot;

	(void)line_number;
}

/**
 * stack - Converts a queue to a stack
 * @stack: A p to the top mode node of a stack_t linked list.
 * @line_number: The current working line num of a Monty bytecodes file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * queue - Converts a stack to a queue
 * @stack: A p to the top mode node of a stack_t linked list.
 * @line_number: The current working line num of a Monty bytecodes file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
