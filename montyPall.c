#include "monty.h"

/**
 * pallFunc - Prints all the values on the stack, starting from the top.
 * @stack: A pointer to the stack.
 * @line_number: The line number where the instruction appears.
 */
void pallFunc(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
