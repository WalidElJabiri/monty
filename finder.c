#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * finder - Find and executes a command
 * @tok: The token representing the command
 * @num: The number of elements
 * @top: A double pointer to the top element
 * @line: The line number
 * Return: 0 if succes, 1 otherwise.
 */
int finder(char *tok, int num, stack_t **top, unsigned int line)
{
	int i;

	for (i = 0; i < num; i++)
	{
		if (strcmp(instruction_cmd[i].opcode, tok) == 0)
		{
			instruction_cmd[i].f(top, line);
			return (0);
		}
	}
	return (1);
}

/**
 * l_checker - Checks if a str is empty
 * @buffer: A pointer to str to check.
 * Return: 1 if the string is empty or contains whitespace
 * or a comment, 0 otherwise
 */
int l_checker(char *buff)
{
	int i;

	if (buff[0] == '#')
	{
		return (1);
	}
	if (strcmp("\n", buff) == 0)
	{
		return (1);
	}
	for (i = 0; buff[i] != '\n'; i++)
	{
		if (buff[i] != ' ')
		{
			return (0);
		}
	}
	return (1);
}
