/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:31:54 by joel              #+#    #+#             */
/*   Updated: 2023/03/24 15:38:19 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	succes_exit(t_stack *a, t_stack *b, char **args,
	unsigned int n_args)
{
	free_str_array(args, n_args);
	free_stack(a);
	free_stack(b);
}

static int	error_exit(char *err_msg, char **args, unsigned int n_args)
{
	free_str_array(args, n_args);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	return (ERROR);
}

int	main(int argc, char **argv)
{
	char			**args;
	unsigned int	n_args;
	t_stack			*a;
	t_stack			*b;

	if (argc < 2)
		return (ERROR);
	args = init_args(argc, argv);
	if (!args)
		return (ERROR);
	n_args = init_n_args(argc, argv);
	if (!is_valid(args, n_args))
		return (error_exit(ERROR_MSG, args, n_args));
	a = new_stack(n_args);
	if (!a)
		return (ERROR);
	b = new_stack(a->max_size);
	if (!b)
	{
		free_stack(a);
		return (error_exit(ERROR_MSG, args, n_args));
	}
	init_stack(a, args);
	succes_exit(a, b, args, n_args);
	return (SUCCES);
}
