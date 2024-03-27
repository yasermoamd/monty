#include "monty.h"

/**
 * execute - executes the command at a given line of a file.
 * @line: the command to execute
 * @stack: stack head
 * @count: line_number
 * Return: nothing
 */

int execute(char *line, stack_t **stack, unsigned int count)
{
	/*char *command, *arg;*/
	instruction_t func[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"sub", sub}, {"div", _div},
		{"mul", mul}, {"mod", mod},
		{"nop", nop}, {"pchar",  pchar},
		{"pstr", pstr}, {"stack", _stack},
		{"queue", queue}, {"rotl", rotl},
		{"rotr", rotr}, {NULL, NULL},
	};
	char *command = strtok(line, " \n\t");
	char *arg;
	int i = 0;

	if (command && command[0] == '#')
		return (0);
	arg = strtok(NULL, " \n\t");
	bus.arg = arg;
	while (func[i].opcode && command)
	{
		if (strcmp(func[i].opcode, command) == 0)
		{
			func[i].f(stack, count);
			return (0);
		}
		i++;
	}

	if (command && func[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, command);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}
	return (1);
}

