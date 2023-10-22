#include "monty.h"

/**
 * swapFunc - Swaps the top two elements of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The current line number being processed.
 */
void swapFunc(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int node_count, t;

	node_count = 0;
	temp = *stack;

	while (temp != NULL)
	{
		temp = temp->next;
		node_count++;
	}

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	t = temp->n;
	temp->n = temp->next->n;
	temp->next->n = t;
}
