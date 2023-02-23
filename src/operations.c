/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:50:51 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/15 15:00:14 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	swap(t_stack *stack)
{
	int	tmp;
	int	tmp_idx;
	int	top_idx;

	top_idx = stack->size - 1;
	tmp_idx = stack->size - 2;
	tmp = stackget(stack, tmp_idx);
	if (stackset(stack, tmp_idx, stackget(stack, top_idx)))
		return (1);
	return (stackset(stack, top_idx, tmp));
}

void	push(t_stack *stack_from, t_stack *stack_to)
{
	stackadd(stack_to, stackget(stack_from, stack_from->size - 1));
	stackpop(stack_from);
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
	int	idx;
	int	lastval;

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
