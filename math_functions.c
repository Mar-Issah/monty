#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to lists for monty stack
 * @number: num of line opcode occurs
 */

void _add(stack_t **stack, unsigned int number)
{
	stack_t *temp = *stack;
	int sum = 0, idx = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		idx++;
	}

	if (stack == NULL || (*stack)->next == NULL || idx <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, number);

	(*stack)->n = sum;
}

/**
 * _sub - sub top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */
void _sub(stack_t **stack, unsigned int number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	int sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, number);

	(*stack)->n = sub;
}

/**
 * _mul - mul top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */
void _mul(stack_t **stack, unsigned int number)
{
	int auxiliary;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", number);
		handleError()
	}
	else
	{
		auxiliary = (*stack)->n;
		_pop(stack, number);
		(*stack)->n *= auxiliary;
	}
}

/**
 * _div - div top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */
void _div(stack_t **stack, unsigned int number)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", number);
		handleError()
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		handleError()
	}
	else
	{
		div = (*stack)->n;
		_pop(stack, number);
		(*stack)->n /= div;
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