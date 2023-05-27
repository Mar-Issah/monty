#include "monty.h"
/**
 * _add - add top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */

void _add(stack_t **stack, unsigned int number)
{
	stack_t *temp = *stack;
	int sum = 0, i = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, number);

	(*stack)->n = sum;
}

/**
 * _isalphabet - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalphabet(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
