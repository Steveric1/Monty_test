#include "monty.h"

/**
 * processMonty - Process Monty bytecode instructions from a stream.
 * @file: A stream_t structure representing the input stream.
 *
 * This function processes Monty bytecode instructions from the given input
 * stream. It reads each line, tokenizes the input, and performs corresponding
 * operations based on recognized opcodes. It handles error reporting and
 * memory cleanup as needed.
 */
void processMonty(stream_t file)
{
	stack_t *stack = NULL;
	char *opcodes, *line = NULL;
	int line_number, found;
	size_t i, j, num_token = 0, num_opcodes = 0, len = 0;
	instruction_t instruction[] = {
		{"push", pushFunc}, {"pall", pallFunc}
	};
	num_opcodes = sizeof(instruction) / sizeof(instruction[0]);
	line_number = 1;
	found = 0;

	while (getline(&line, &len, file.file) != -1)
	{
		opcodes = strtok(line, " \t\n$");
		if (opcodes == NULL || strlen(opcodes) == 0)
			continue;

		for (j  = 0; j < num_opcodes; j++)
		{
			if (strcmp(opcodes, instruction[j].opcode) == 0)
			{
				instruction[j].f(&stack, line_number);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcodes);
			fclose(file.file);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	freeStack(&stack);
}
