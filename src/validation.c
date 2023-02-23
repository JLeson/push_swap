/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:55:56 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/15 15:00:29 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_num(char *arg);
static int	is_int32(char *arg);
static int	has_dup(char **elements, int size);

int	valid(char **elements, int size)
{
	int	cidx;

	cidx = 0;
	while (cidx < size)
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
	if (has_dup(elements, size))
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
	int	atoi;
	int	cmpl;

	atoi = ft_atoi(arg);
	cmpl = ft_max(ft_strlen(ft_itoa(atoi)), ft_strlen(arg));
	if (ft_strncmp(ft_itoa(atoi), arg, cmpl))
		return (0);
	return (1);
}

static int	has_dup(char **elements, int size)
{
	int	offset;
	int	sub_offset;
	int	arg;

	offset = 0;
	while (offset < size)
	{	
		arg = ft_atoi(*(elements + offset));
		sub_offset = 0;
		while (sub_offset < size)
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
