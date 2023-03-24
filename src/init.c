/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:29:14 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/24 15:35:04 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

unsigned int	init_n_args(int argc, char **argv)
{
	if (argc == 2)
		return (get_n_args(*(argv + 1), ' '));
	return ((unsigned int)argc - 1);
}

char	**init_args(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(*(argv + 1), ' '));
	return (parse_argv((unsigned int)argc, argv));
}

void	init_stack(t_stack *stack, char **args)
{
	unsigned int	cidx;

	cidx = stack->max_size - 1;
	while (cidx > 0)
	{
		stackadd(stack, ft_atoi(*(args + cidx)));
		cidx--;
	}
	stackadd(stack, ft_atoi(*(args + cidx)));
}
