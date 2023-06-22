#include "monty.h"

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_monty(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/**
 * add - Adds the top two values of a stack_t linked list.
 * @stack: A p to the top mode node of a stack_t linked list.
 * @line_number: The current working line num of a Monty bytecodes file
 * Description: The result is stored in the second value node
 */
void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * sub - Subtracts the second value
 * @stack: A p to the top mode node of a stack_t linked list.
 * @line_number: The current working line num of a Monty bytecodes file.
 * Description: The result is stored in the second value node
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * div - Divides the second value
 * @stack: A p to the top mode node of a stack_t linked list.
 * @line_number: The current working line num of a Monty bytecodes file.
 * Description: The result stored in the second value node
 */
void div_monty(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_error(di_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * mul - Multiplies the second value
 * @stack: A p to the top mode node of a stack_t linked list.
 * @line_number: The current working line nu of a Monty bytecodes file.
 * Description: The result is stored in the second value nod
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * mod - Computes the modulus of the second value
 * @stack: A p to the top mode node of a stack_t linked list.
 * @line_number: The current working lin of a Monty bytecodes file.
 * Description: The result is stored in the second value node
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_error(di_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}
