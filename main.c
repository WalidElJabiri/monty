#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

instruction_t instruction_cmd[] = {
	{"push", f_push},
	{"pall", f_pall},
	{"pint", f_pint},
	{"pop", f_pop},
	{"swap", f_swap},
	{"add", f_add},
	{"nop", f_nop},
	{"sub", f_sub},
	{"div", f_div},
	{"mul", f_mul},
	{"mod", f_mod},
	{"pchar", f_pchar},
	{"pstr", f_pstr},
	{"rotl", f_rotl},
	{"rotr", f_rotr}
};

/**
 * main - Entry point
 * @argc: The num of command line args
 * @argv: An array of strings containing the command line args
 * Return: EXIT_SUCCESS if succes, EXIT_FAILURE otherwise.
 */
int main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		FILE *file;
		char buff_line[1024], *token;
		int cmd_num;
		unsigned int i;
		stack_t *top_element;

		top_element = NULL;
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			return (EXIT_FAILURE);
		}
		for (i = 1; fgets(buff_line, sizeof(buff_line), file) != NULL; i++)
		{
			if (l_checker(buff_line) == 0)
			{
				cmd_num = sizeof(instruction_cmd) / sizeof(instruction_cmd[0]);
				token = strtok(buff_line, " \n");
				if (finder(token, cmd_num, &top_element, i) == 1)
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", i, token);
					exit(EXIT_FAILURE);
				}
			}
		}
		fclose(file);
		free_dlistint(top_element);
		return (EXIT_SUCCESS);
	}
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
