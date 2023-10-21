#include "monty.h"

/**
 * processInstruction - Process a single Monty bytecode instruction.
 * @line: The input line containing the Monty instruction.
 * @line_number: The line number of the instruction in the source.
 * @stack: A pointer to the stack to be modified.
 */
void processInstruction(char *line, unsigned int line_number, stack_t **stack)
{
	int found;
	size_t j, num_opcodes;
	char *opcodes;

	instruction_t instruction[] = {
		{"push", pushFunc}, {"pall", pallFunc}
	};
	num_opcodes = sizeof(instruction) / sizeof(instruction[0]);
	opcodes = strtok(line, " \t\n$");

	if (opcodes == NULL || strlen(opcodes) == 0)
		return;
	for (j = 0; j < num_opcodes; j++)
	{
		if (strcmp(opcodes, instruction[j].opcode) == 0)
		{
			instruction[j].f(stack, line_number);
			found = 1;
			break;
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcodes);
		exit(EXIT_FAILURE);
	}
}
