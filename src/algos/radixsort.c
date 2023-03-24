/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:50:11 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/24 16:02:42 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static unsigned int	maxbits(t_stack *stack)
{
	unsigned int	max;
	unsigned int	nbits;
	unsigned int	stackidx;
	unsigned int	cbit;

	max = 0;
	stackidx = 0;
	while (stackidx < stack->size)
	{
		nbits = 0;
		cbit = 0;
		while (cbit < 31)
		{
			if (stackget(stack, stackidx) & (0b1 << cbit))
				nbits = cbit;
			cbit++;
		}
		if (nbits > max)
			max = nbits;
		stackidx++;
	}
	return (max + 1);
}

static void	sortdigits(t_stack *a, t_stack *b, t_stack *normalized, int didx)
{
	int		n_iterations;

	n_iterations = a->size;
	while (n_iterations > 0)
	{
		if (stackget(normalized, normalized->size - 1) & (0b1 << didx))
		{
			exec(RA, a, b);
			rotate(normalized);
		}
		else
		{
			exec(PB, a, b);
			stackpop(normalized);
		}
		n_iterations--;
	}
}

void	ft_radixsort(t_stack *a, t_stack *b)
{
	t_stack	*normalized;
	int		cbit;
	int		maxdigits;

	cbit = 0;
	if (is_sorted(a))
		return ;
	normalized = normalize_stack(a);
	if (!normalized)
		return ;
	maxdigits = maxbits(normalized);
	while (cbit < maxdigits)
	{
		sortdigits(a, b, normalized, cbit);
		while (b->size > 0)
			exec(PA, a, b);
		free_stack(normalized);
		normalized = normalize_stack(a);
		cbit++;
	}
	free_stack(normalized);
}
