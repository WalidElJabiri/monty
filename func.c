#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * add_element_at_top - Adds a new element at the top
 * @top_element: Double ptr to the top elemen
 * @n: Value to be stored at the new element.
 * Return: Pointer to the new element
*/
stack_t *add_element_at_top(stack_t **top_element, int n)
{
	stack_t *new_element;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint(*top_element);
		exit(EXIT_FAILURE);
	}
	new_element->n = n;
	if (*top_element == NULL)
	{
		new_element->next = NULL;
		new_element->prev = NULL;
		*top_element = new_element;
		return (new_element);
	}
	new_element->next = NULL;
	new_element->prev = *top_element;
	(*top_element)->next = new_element;
	*top_element = new_element;
	return (new_element);
}

/**
 * free_dlistint - Free the doubly linked list.
 * @current: Ptr to the current node in the doubly linked list.
 * Description: Frees the memory allocated for a doubly linked list.
 */
void free_dlistint(stack_t *current)
{
	stack_t *next, *head;

	if (current != NULL)
	{
		head = current;
		while (head->prev != NULL)
		{
			head = head->prev;
		}
		while (head->next != NULL)
		{
			next = head->next;
			free(head);
			head = next;
		}
		free(head);
	}
}
