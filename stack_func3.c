#include "monty.h"

/**
 * _rotl - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */
void _rotl(stack_t **stack, unsigned int number)
{
	stack_t *runner = *stack;

	int aux1 = 0;

	if (!number || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux1;
}

/**
 * _rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */
void _rotr(stack_t **stack, unsigned int number)
{
	stack_t *runner = *stack;

	int aux1 = 0;

	if (!number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux1;
}
