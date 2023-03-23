/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:16:50 by joel              #+#    #+#             */
/*   Updated: 2023/03/23 20:26:38 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	print_stack(t_stack *stack, unsigned int verbose)
{
	unsigned int	cidx;

	printf("[");
	cidx = 0;
	while (cidx < stack->size - 1)
	{
		printf("%i, ", stackget(stack, cidx));
		cidx++;
	}
	printf("%i]\n", stackget(stack, cidx));
	if (verbose)
	{
		printf("size: %u\n", stack->size);
		printf("max_size: %u\n", stack->max_size);
	}
}
