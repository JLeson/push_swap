/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:57:56 by joel              #+#    #+#             */
/*   Updated: 2023/03/24 14:39:37 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static char	*copy_str(char *str)
{
	char			*str_copy;
	unsigned int	cidx;

	str_copy = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!str_copy)
		return (NULL);
	cidx = 0;
	while (*(str + cidx))
	{
		*(str_copy + cidx) = *(str + cidx);
		cidx++;
	}
	*(str_copy + cidx) = '\0';
	return (str_copy);
}

char	**parse_argv(unsigned int argc, char **argv)
{
	char			**args;
	char			*str_copy;
	unsigned int	cidx;
	unsigned int	argv_idx;

	args = (char **)malloc(sizeof(char *) * argc - 1);
	if (!args)
		return (NULL);
	cidx = 0;
	argv_idx = 1;
	while (argv_idx < argc)
	{
		str_copy = copy_str(*(argv + argv_idx));
		if (!str_copy)
			return (NULL);
		*(args + cidx) = str_copy;
		if (!*(args + cidx))
			return (NULL);
		argv_idx++;
		cidx++;
	}
	return (args);
}

unsigned int	get_n_args(char *str, char c)
{
	unsigned int	cidx;
	unsigned int	n;

	cidx = 0;
	n = 0;
	while (*(str + cidx))
	{
		if (*(str + cidx) != c)
			n++;
		while (*(str + cidx) != c && *(str + cidx))
			cidx++;
		while (*(str + cidx) == c && *(str + cidx))
			cidx++;
	}
	return (n);
}
