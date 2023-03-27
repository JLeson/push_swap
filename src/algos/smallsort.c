/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:49:14 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/27 15:43:02 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static int	get_max(t_stack *stack)
{
	int				max;
	unsigned int	cidx;

	max = INT32_MIN;
	cidx = 0;
	while (cidx < stack->size)
	{
		if (stackget(stack, cidx) > max)
			max = stackget(stack, cidx);
		cidx++;
	}
	return (max);
}

static int	get_min(t_stack *stack)
{
	int				min;
	unsigned int	cidx;

	min = INT32_MAX;
	cidx = 0;
	while (cidx < stack->size)
	{
		if (stackget(stack, cidx) < min)
			min = stackget(stack, cidx);
		cidx++;
	}
	return (min);
}

static void	rotate_to_idx(t_stack *a, t_stack *b, unsigned int idx)
{
	unsigned int	operation;
	unsigned int	n_rotations;

	if (idx <= a->size / 2)
	{
		n_rotations = idx;
		operation = RRA;
	}
	else
	{
		n_rotations = a->size - idx;
		operation = RA;
	}
	chexec(operation, a, b, n_rotations);
}

static void	insert(t_stack *a, t_stack *b)
{
	unsigned int	inidx;

	inidx = get_idx(a, get_max(a));
	if (stackget(b, b->size - 1) < get_min(a))
		inidx = get_idx(a, get_max(a));
	else
	{
		while (stackget(a, inidx) > stackget(b, b->size - 1) && inidx < a->size)
			inidx = (inidx + 1) % a->size;
	}
	rotate_to_idx(a, b, inidx);
	exec(PA, a, b);
}

void	smallsort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	chexec(PB, a, b, a->size - 3);
	minisort(a, b);
	while (b->size > 0)
		insert(a, b);
	rotate_to_idx(a, b, get_idx(a, get_max(a)));
}
