/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:50:47 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/24 17:41:02 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	unsigned int	cidx;

	cidx = 1;
	while (cidx < stack->size)
	{
		if (stackget(stack, cidx) > stackget(stack, cidx - 1))
			return (FALSE);
		cidx++;
	}
	return (TRUE);
}

static int	get_normalized(t_stack *a, int idx)
{	
	unsigned int	cidx;
	int				val;
	int				normalized;

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

t_stack	*normalize_stack(t_stack *stack)
{
	t_stack	*normalized;

	normalized = new_stack(stack->max_size);
	if (!normalized)
		return (NULL);
	while (normalized->size < normalized->max_size)
		stackadd(normalized, get_normalized(stack, normalized->size));
	return (normalized);
}

void	chexec(unsigned int operation, t_stack *a, t_stack *b, unsigned int c)
{
	unsigned int	ccount;

	ccount = 0;
	while (ccount < c)
	{
		exec(operation, a, b);
		ccount++;
	}
}

unsigned int	get_idx(t_stack	*stack, int val)
{
	unsigned int	cidx;

	cidx = 0;
	while (cidx < stack->size)
	{
		if (stackget(stack, cidx) == val)
			return (cidx);
		cidx++;
	}
	return (0);
}
