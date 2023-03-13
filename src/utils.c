/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:45:51 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/13 14:04:21 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	*free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
	return (NULL);
}

void	*free_elements(char **elements, unsigned int count, int argc)
{
	unsigned int	offset;

	offset = 0;
	if (argc == 2)
	{
		while (offset < count)
		{
			free(*(elements + offset));
			offset++;
		}
		free(elements);
	}
	return (NULL);
}
