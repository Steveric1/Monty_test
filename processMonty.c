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
	char *line = NULL;
	int line_number;
	size_t len = 0;

	line = malloc(1024);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(0);
	}

	len = sizeof(line);
	line_number = 1;

	while ((fgets(line, len, file.file)) != NULL)
	{
		processInstruction(line, line_number, &stack);
		line_number++;
	}

	free(line);
	freeStack(&stack);
}
