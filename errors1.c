#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_error(char *filename);
int unknown_error(char *opcode, unsigned int line_number);
int no_error(unsigned int line_number);

/**
 * usage_error - Prints usage error message
 * Return: (EXIT_FAILURE)
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error message
 * Return: (EXIT_FAILURE)
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_error - Prints file opening error messages
 * @filename: Name of file failed to opens
 * Return: (EXIT_FAILURE)
 */
int f_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_error - Prints unknown error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line in Monty bytecodes file where error occured.
 * Return: (EXIT_FAILURE)
 */
int unknown_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * int_error - Prints invalid monty push argument error messages.
 * @line_number: Line in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE)
 */
int no_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
