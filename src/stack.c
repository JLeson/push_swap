/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:09:21 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/15 19:49:55 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

t_stack	*new_stack(int max_size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = (int *)ft_calloc(max_size, sizeof(int));
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

int	stackset(t_stack *stack, int idx, int val)
{	
	if (idx < stack->size && idx >= 0)
		*(stack->array + idx) = val;
	else
		return (1);
	return (0);
}

int	stackget(t_stack *stack, int idx)
{
	if (idx < stack->size && idx >= 0)
		return (*(stack->array + idx));
	return (0);
}
