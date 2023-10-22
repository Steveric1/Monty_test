#include "monty.h"

/**
 * popFunc - Removes the top element from the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The current line number being processed.
 */
void popFunc(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	free(temp);
	temp = NULL;

	if (*stack != NULL)
		(*stack)->prev = NULL;
}