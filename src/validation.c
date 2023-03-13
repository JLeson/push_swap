/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:55:56 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/13 13:37:45 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_num(char *arg);
static int	is_int32(char *arg);
static int	has_dup(char **elements, int size, int argv_offset);

int	valid(char **elements, int size, int argv_offset)
{
	int	cidx;

	cidx = argv_offset;
	while (cidx < size + argv_offset)
	{
		if (!is_num(*(elements + cidx)))
		{
			ft_putstr_fd("Argument is not a number\n", STDERR_FILENO);
			return (0);
		}
		if (!is_int32(*(elements + cidx)))
		{
			ft_putstr_fd("Argument is not a 32-bit integer\n", STDERR_FILENO);
			return (0);
		}
		cidx++;
	}
	if (has_dup(elements, size, argv_offset))
	{
		ft_putstr_fd("List has duplicates\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}

static int	is_num(char *arg)
{
	unsigned int	offset;

	offset = 0;
	if (*arg == '-')
		offset = 1;
	while (*(arg + offset))
	{
		if (!ft_isdigit(*(arg + offset)))
			return (0);
		offset++;
	}
	return (1);
}

static int	is_int32(char *arg)
{
	int		atoi;
	char	*itoa;
	int		cmpl;

	atoi = ft_atoi(arg);
	itoa = ft_itoa(atoi);
	cmpl = ft_max(ft_strlen(itoa), ft_strlen(arg));
	if (ft_strncmp(itoa, arg, cmpl))
		return (0);
	free(itoa);
	return (1);
}

static int	has_dup(char **elements, int size, int argv_offset)
{
	int	offset;
	int	sub_offset;
	int	arg;

	offset = argv_offset;
	while (offset < size + argv_offset)
	{	
		arg = ft_atoi(*(elements + offset));
		sub_offset = argv_offset;
		while (sub_offset < size + argv_offset)
		{	
			if (elements + offset == elements + sub_offset)
			{
				sub_offset++;
				continue ;
			}
			if (arg == ft_atoi(*(elements + sub_offset)))
				return (1);
			sub_offset++;
		}
		offset++;
	}
	return (0);
}
