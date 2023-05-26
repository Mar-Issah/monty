#include "monty.h"

/**
 * _pstr - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */
void _pstr(stack_t **stack, unsigned int number)
{
	stack_t *temp = *stack;
	int c = 0;

	(void)number;


	while (temp)
	{
		c = temp->n;
		if (c == 0 || _isalphabet(c) == 0)
			break;
		putchar(c);
		temp = temp->next;
	}
	putchar('\n');
}

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
