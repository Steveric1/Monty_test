#include "monty.h"

/**
 * freeStack - Frees a doubly-linked list stack.
 * @stack: A pointer to the head of the stack.
 *
 * This function frees all the nodes in a doubly-linked
 * list stack and sets the head of the stack to NULL.
 */
void freeStack(stack_t **stack)
{
	stack_t *current, *temp;

	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
