/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:52:27 by joel              #+#    #+#             */
/*   Updated: 2023/03/23 22:02:21 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static unsigned int	is_num(char *arg)
{
	unsigned int	cidx;

	cidx = 0;
	if (*arg == '-')
		cidx = 1;
	while (*(arg + cidx))
	{
		if (!ft_isdigit(*(arg + cidx)))
			return (FALSE);
		cidx++;
	}
	return (TRUE);
}

static unsigned int	is_int32(char *arg)
{
	int		atoi;
	char	*itoa;
	int		cmpl;

	atoi = ft_atoi(arg);
	itoa = ft_itoa(atoi);
	cmpl = ft_max(ft_strlen(itoa), ft_strlen(arg));
	if (ft_strncmp(itoa, arg, cmpl))
	{
		free(itoa);
		return (FALSE);
	}
	free(itoa);
	return (TRUE);
}

static unsigned int	is_unique(char **args, unsigned int idx, unsigned int size)
{
	unsigned int	cidx;
	char			*str_cmp_comparison;
	char			*current_str;
	unsigned int	str_cmp_len;

	str_cmp_comparison = *(args + idx);
	str_cmp_len = ft_strlen(str_cmp_comparison);
	cidx = 0;
	while (cidx < size)
	{
		current_str = *(args + cidx);
		if (cidx == idx)
		{
			cidx++;
			continue ;
		}
		if (!ft_strncmp(current_str, str_cmp_comparison,
				ft_max(str_cmp_len, ft_strlen(current_str))))
			return (FALSE);
		cidx++;
	}
	return (TRUE);
}

unsigned int	is_valid(char **args, unsigned int size)
{
	unsigned int	cidx;
	char			*current_arg;

	cidx = 0;
	while (cidx < size)
	{
		current_arg = *(args + cidx);
		if (!is_num(current_arg))
			return (FALSE);
		if (!is_int32(current_arg))
			return (FALSE);
		if (!is_unique(args, cidx, size))
			return (FALSE);
		cidx++;
	}
	return (TRUE);
}
