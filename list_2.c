#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * f_add - Adds the top two elements
 * @stack: A double ptr to the top
 * @line_number: The line number
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	sum = temp->n;
	sum += (*stack)->n;
	f_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * f_nop - nothing.
 * @stack: A double ptr to the top
 * @line_number: The line number
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * f_sub - Subtracts the top element from the second top element
 * @stack: A double ptr to the top
 * @line_number: The line number
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	result = (temp->n - (*stack)->n);
	f_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * f_div - Divides the second top element by the top element
 * @stack: A double ptr to the top
 * @line_number: The line number
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	result = (temp->n / (*stack)->n);
	f_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * f_mul - Multiplies the second top element with the top element
 * @stack: A double ptr to the top
 * @line_number: The line number
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	result = (temp->n * (*stack)->n);
	f_pop(stack, line_number);
	(*stack)->n = result;
}
