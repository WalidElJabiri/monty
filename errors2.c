#include "monty.h"

int short_error(unsigned int line_number, char *op);
int print_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int di_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *msg);

/**
 * pop_error - Prints pop error message
 * @line_number: Line number in script where error occured
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * print_error - Prints pint error message
 * @line_number: Line number in Monty file where error occurred
 * Return: (EXIT_FAILURE)
 */
int print_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_error - Prints monty math function error message
 * @line_number: Line number in Monty file where error occurred.
 * @op: Operation where the error occurred
 * Return: (EXIT_FAILURE)
 */
int short_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * di_error - Prints division error message
 * @line_number: Line number in Monry file where error occurred.
 * Return: (EXIT_FAILURE)
 */
int di_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error message
 * @line_number: Line number in Monty bytecodes file where error occurred
 * @msg: The corresponding error message
 * Return: (EXIT_FAILURE)
 */
int pchar_error(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	return (EXIT_FAILURE);
}
