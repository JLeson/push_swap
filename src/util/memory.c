/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:47:16 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/24 14:54:45 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	free_str_array(char **str_array, unsigned int n_args)
{
	unsigned int	cidx;

	cidx = 0;
	while (cidx < n_args)
	{
		free(*(str_array + cidx));
		cidx++;
	}
	free(str_array);
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}
