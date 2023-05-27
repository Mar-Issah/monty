#include "monty.h"
/**
 * _mod - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */
void _mod(stack_t **stack, unsigned int number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", number);
		handleError();
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		handleError();
	}
	else
	{
		int mod = (*stack)->n;
		_pop(stack, number);
		(*stack)->n %= mod;
	}
}

/**
 * handleError - handles error
 */
void handleError()
{
	free(global.buffer);
	fclose(global.file);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
