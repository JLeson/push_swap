/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:57:56 by joel              #+#    #+#             */
/*   Updated: 2023/03/23 22:22:22 by joel             ###   ########.fr       */
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
	return (str);
}

char	**parse_argv(unsigned int argc, char **argv)
{
	char			**args;
	unsigned int	cidx;
	unsigned int	argv_idx;

	args = (char **)malloc(sizeof(char *) * argc - 1);
	if (!args)
		return (NULL);
	cidx = 0;
	argv_idx = 1;
	while (argv_idx < argc)
	{
		*(args + cidx) = copy_str(*(argv + argv_idx));
		argv_idx++;
		cidx++;
	}
	return (args);
}

unsigned int	n_args(char *arg, char c)
{
	unsigned int	cidx;
	unsigned int	n;

	cidx = 0;
	n = 0;
	while (*(arg + cidx))
	{
		if (*(arg + cidx) != c)
			n++;
		while (*(arg + cidx) != c && *(arg + cidx))
			cidx++;
		while (*(arg + cidx) == c && *(arg + cidx))
			cidx++;
	}
	return (n);
}
