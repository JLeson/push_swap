/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:16:50 by joel              #+#    #+#             */
/*   Updated: 2023/03/24 17:25:47 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stack(t_stack *stack, unsigned int verbose)
{
	unsigned int	cidx;

	if (stack->size == 0)
	{
		ft_printf("[]");
		return ;
	}
	cidx = 0;
	ft_printf("[");
	while (cidx < stack->size - 1)
	{
		ft_printf("%i, ", stackget(stack, cidx));
		cidx++;
	}
	ft_printf("%i]\n", stackget(stack, cidx));
	if (verbose)
	{
		ft_printf("size: %u\n", stack->size);
		ft_printf("max_size: %u\n", stack->max_size);
	}
}
