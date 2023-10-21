#include "monty.h"

/**
 * pushFunc - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number where the instruction appears.
 */
void pushFunc(stack_t **stack, unsigned int line_number)
{
	char *value;
	int n, i = 0;
	stream_t fc;

	fc.file = NULL;
	value = strtok(NULL, " \t\n$");
	if (value)
	{
		if (value[0] == '-')
			i++;
		for (; value[i] != '\0'; i++)
		{
			if (value[i] > 57 || value[i] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(fc.file);
				freeStack(stack);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(fc.file);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(value);
	add_node(stack, n);
}
