#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_len(void);
int is_line(char *line, char *delims);
void (*get_func(char *opcode))(stack_t**, unsigned int);
int run(FILE *script_fd);

/**
 * free_tokens - Frees the global op_toks array
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * token_len - Gets the len of current op_toks
 * Return: Len of current op_toks (as int).
 */
unsigned int token_len(void)
{
	unsigned int len = 0;

	while (op_toks[len])
		len++;
	return (len);
}

/**
 * is_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 * Return: If the line only contains delimiters - 1 Otherwise 0.
 */
int is_line(char *line, char *delims)
{
	int i, n;

	for (i = 0; line[i]; i++)
	{
		for (n = 0; delims[n]; n++)
		{
			if (line[i] == delims[n])
				break;
		}
		if (delims[n] == '\0')
		return (0);
	}

	return (1);
}

/**
 * get_func - Matches an opcode with its corresponding func
 * @opcode: The opcode to match.
 * Return: A pointer to the corresponding funct
 */
void (*get_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", print},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_monty},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run - Primary func to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success
 */
int run(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_error(op_toks[0], line_number);
			free_tokens();
			break;
		}
		prev_len = token_len();
		op_func(&stack, line_number);
		if (token_len() != prev_len)
		{
			if (op_toks && op_toks[prev_len])
				exit_status = atoi(op_toks[prev_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
