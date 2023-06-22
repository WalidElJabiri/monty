#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - the entry point
 * @argc: the count of arguments
 * @argv: pointer to an array
 * Return: (EXIT_SUCCESS) on success otherwise (EXIT_FAILURE)
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_error(argv[1]));
	exit_code = run(script_fd);
	fclose(script_fd);
	return (exit_code);
}
