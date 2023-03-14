/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediumsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:59:58 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/14 18:27:13 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

// static void	print_stack(t_stack *stack)
// {
// 	int	cidx;

// 	cidx = 0;
// 	ft_printf("[");
// 	while (cidx < stack->size)
// 	{
// 		ft_printf("%i, ", stackget(stack, cidx));
// 		cidx++;
// 	}
// 	ft_printf("]\n");
// }

static int	get_max(t_stack *stack)
{
	int	max;
	int	cidx;

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
	int	min;
	int	cidx;

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

static void	insert(t_stack *a, t_stack *b)
{
	int	cidx;
	int	operation;
	int	n_rotations;

	cidx = 0;
	operation = RRA;
	while (stackget(a, cidx) > stackget(b, b->size - 1) && cidx < a->size)
		cidx++;
	n_rotations = cidx;
	if (cidx > a->size / 2)
	{
		n_rotations = a->size - cidx;
		operation = RA;
	}
	chexec(operation, a, b, n_rotations);
	exec(PA, a, b);
	if (operation == RRA)
		chexec(RA, a, b, n_rotations + 1);
	else
		chexec(RRA, a, b, n_rotations);
}

static void	push_back(t_stack *a, t_stack *b, int min, int max)
{
	if (stackget(b, b->size - 1) > max)
	{
		exec(PA, a, b);
		exec(RA, a, b);
	}
	else if (stackget(b, b->size - 1) < min)
		exec(PA, a, b);
	else
		insert(a, b);
}

void	mediumsort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	chexec(PB, a, b, a->size - 3);
	simplesort(a, b);
	while (b->size > 0)
		push_back(a, b, get_min(a), get_max(a));
}
