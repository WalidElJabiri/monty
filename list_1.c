#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * f_pall - prints all elements in a stack
 * @top_element: the top element
 * @line_number: the line number
 * Return: void
 */
void f_pall(stack_t **top_element, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *top_element;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}

/**
 * f_push - add an int to the top
 * @stack: a ptr to the stack
 * @line_number: the line number
 * Description: reads the next integer from the input file
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	char *element_n;
	int i;

	element_n = strtok(NULL, " \n");
	if (element_n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	for (i = 0; element_n[i] != '\0'; i++)
	{
		if (isdigit(element_n[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_dlistint(*stack);
			exit(EXIT_FAILURE);
		}
	}
	add_element_at_top(stack, atoi(element_n));
}

/**
 * f_pint - Print the value at the top
 * @stack: A double pointer to the top
 * @line_number: The line number
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		printf("L%d: can't pint, stack empty\n", line_number);
	}
}

/**
 * f_pop - Removes the top element
 * @stack: A double ptr to the top
 * @line_number: The line number
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->prev;
	if (temp == NULL)
	{
		free(*stack);
		*stack = temp;
	}
	else
	{
		temp->next = NULL;
		free(*stack);
		*stack = temp;
	}
}

/**
 * f_swap - Swaps the top two elements
 * @stack: A double ptr to the top
 * @line_number: The line number
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int swapp;

	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	swapp = temp->n;
	temp->n = (*stack)->n;
	(*stack)->n = swapp;
}
