/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:31:54 by joel              #+#    #+#             */
/*   Updated: 2023/03/23 22:33:55 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks -q push_swap");
}


int	main(int argc, char **argv)
{
	char			**args;
	unsigned int	arg_count;

	atexit(check_leaks);
	args = NULL;
	if (argc < 2)
		return (ERROR);
	if (argc == 2)
	{
		args = ft_split(*(argv + 1), ' ');
		arg_count = n_args(*(argv + 1), ' ');
	}
	else
	{
		args = parse_argv((unsigned int)argc, argv);
		arg_count = (unsigned int)argc - 1;
	}
	if (!is_valid(args, arg_count))
		return (ERROR);
	return (SUCCES);
}
