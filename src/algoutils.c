/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:58:23 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/13 17:09:52 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_normalized(t_stack *a, int idx);

int	is_sorted(t_stack *stack)
{
	int	cidx;

	cidx = 1;
	while (cidx < stack->size)
	{
		if (stackget(stack, cidx) > stackget(stack, cidx - 1))
			return (0);
		cidx++;
	}
	return (1);
}

t_stack	*normalize_stack(t_stack *a)
{
	t_stack	*normalized;

	normalized = new_stack(a->max_size);
	while (normalized->size < normalized->max_size)
		stackadd(normalized, get_normalized(a, normalized->size));
	return (normalized);
}

static int	get_normalized(t_stack *a, int idx)
{	
	int	cidx;
	int	val;
	int	normalized;

	cidx = 0;
	normalized = 0;
	val = stackget(a, idx);
	while (cidx < a->max_size)
	{
		if (stackget(a, cidx) < val)
			normalized++;
		cidx++;
	}
	return (normalized);
}

int	get_idx(t_stack	*stack, int val)
{
	int	cidx;

	cidx = 0;
	while (cidx < stack->size)
	{
		if (stackget(stack, cidx) == val)
			return (cidx);
		cidx++;
	}
	return (-1);
}

void	chexec(int operation, t_stack *a, t_stack *b, int c)
{
	int	ccount;

	ccount = 0;
	while (ccount < c)
	{
		exec(operation, a, b);
		ccount++;
	}
}
