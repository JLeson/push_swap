/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:31:03 by joel              #+#    #+#             */
/*   Updated: 2023/03/23 20:50:13 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	stackadd(stack_to, stackget(stack_from, stack_from->size - 1));
	stackpop(stack_from);
}

void	swap(t_stack *stack)
{
	int	top;
	int	next_top;

	top = stackget(stack, stack->size - 1);
	next_top = stackget(stack, stack->size - 2);
	stackpop(stack);
	stackpop(stack);
	stackadd(stack, top);
	stackadd(stack, next_top);
}

void	rotate(t_stack *stack)
{
	int	idx;
	int	lastval;

	idx = stack->size - 1;
	lastval = stackget(stack, stack->size - 1);
	while (idx >= 0)
	{	
		if (idx > 0)
			stackset(stack, idx, stackget(stack, idx - 1));
		else
			stackset(stack, idx, lastval);
		idx--;
	}
}

void	rrotate(t_stack *stack)
{
	unsigned int	idx;
	int				lastval;

	idx = 0;
	lastval = stackget(stack, 0);
	while (idx < stack->size)
	{	
		if (idx < stack->size - 1)
			stackset(stack, idx, stackget(stack, idx + 1));
		else
			stackset(stack, idx, lastval);
		idx++;
	}
}
