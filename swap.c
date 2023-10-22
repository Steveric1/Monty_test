#include "monty.h"

/**
 * swapFunc - Swaps the top two elements of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The current line number being processed.
 */
void swapFunc(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if ((*stack)->next != NULL)
	{
		(*stack)->next->prev = temp;
	}

	temp->prev = *stack;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
}
