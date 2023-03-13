/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:25:58 by joel              #+#    #+#             */
/*   Updated: 2023/03/13 13:25:40 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	nelements(const char *s);

char	**get_elements(int argc, char **argv)
{
	char	**elements;

	if (argc == 2)
		elements = ft_split(*(argv + 1), ' ');
	else
		elements = argv;
	return (elements);
}

int	get_stack_size(int argc, char **argv)
{
	if (argc == 2)
		return (nelements(*(argv + 1)) - 1);
	else
		return (argc - 1);
}

static int	nelements(const char *s)
{
	unsigned int	offset;
	int				n;

	offset = 0;
	n = 0;
	while (*(s + offset))
	{
		if (*(s + offset) != ' ')
			n++;
		while (*(s + offset) != ' ' && *(s + offset))
			offset++;
		while (*(s + offset) == ' ' && *(s + offset))
			offset++;
	}
	return (n + 1);
}
