#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * f_mod - Computes the modulus of the second top element by the top
 * @stack: A double ptr to the top
 * @line_number: The line number
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	result = (temp->n % (*stack)->n);
	f_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * f_pchar - Prints the character corresponding to the top element
 * @stack: Double pointer to the top
 * @line_number: Line number
 * Description: Prints the character value of the top element in the stack.
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
	char a_char;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	a_char = (*stack)->n;
	printf("%c\n", a_char);
}

/**
 * f_pstr - Prints the string
 * @stack: Double ptr to the top
 * @line_number: Line number
 * Description: Prints the string formed by the ASCII values in the stack.
 */
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	char a_char;
	int i;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
	}
	else
	{
		temp = *stack;
		for (i = 0; temp != NULL; i++)
		{
			if (temp->n <= 0 || temp->n > 127)
			{
				break;
			}
			a_char = temp->n;
			printf("%c", a_char);
			temp = temp->prev;
		}
		printf("\n");
	}
}

/**
 * f_rotl - Rotates the stack to the left
 * @stack: Double ptr to the top
 * @line_number: Line number
 * Description: Rotates the stack by moving the top element to the bottom.
 */
void f_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *head;

	(void)line_number;
	temp = *stack;
	head = *stack;
	if (temp != NULL && temp->prev != NULL)
	{
		while (head->prev != NULL)
		{
			head = head->prev;
		}
		(temp->prev)->next = NULL;
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		while ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
		}
	}
}

/**
 * f_rotr - Rotates the stack to the right
 * @stack: Double pointer to the top
 * @line_number: Line number
 * Description: Rotates the stack by moving the bottom element to the top.
 */
void f_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *head;

	(void)line_number;
	head = *stack;
	if (head != NULL && head->prev != NULL)
	{
		while (head->prev != NULL)
		{
			head = head->prev;
		}
		temp = head->next;
		temp->prev = NULL;
		head->next = NULL;
		head->prev = *stack;
		(*stack)->next = head;
		*stack = head;
	}
}
