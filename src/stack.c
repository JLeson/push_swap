/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:34:34 by joel              #+#    #+#             */
/*   Updated: 2023/03/23 20:45:34 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_stack	*new_stack(unsigned int max_size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = (int *)malloc(sizeof(int) * max_size);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->max_size = max_size;
	return (stack);
}

void	stackadd(t_stack *stack, int val)
{
	*(stack->array + stack->size) = val;
	stack->size += 1;
}

void	stackpop(t_stack *stack)
{
	stack->size -= 1;
}

void	stackset(t_stack *stack, unsigned int idx, int val)
{
	*(stack->array + idx) = val;
}

int	stackget(t_stack *stack, unsigned int idx)
{
	return (*(stack->array + idx));
}
