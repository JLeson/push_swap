/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:30 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/02/22 20:47:18 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	start_sort(t_stack *a, t_stack *b);
static void	init_stacks(t_stack *a, char **argv);
static int	nelements(const char *s);

int	main(int argc, char **argv)
{
	char	**elements;
	t_stack	*a;
	t_stack	*b;

	if (argc != 2)
		return (1);
	elements = ft_split(*(argv + 1), ' ');
	a = new_stack(nelements(*(argv + 1)) - 1);
	b = new_stack(a->max_size);
	if (!valid(elements, a->max_size))
	{
		ft_putstr_fd("Error!\n", STDERR_FILENO);
		return (1);
	}
	init_stacks(a, elements);
	start_sort(a, b);
	return (0);
}

static void	start_sort(t_stack *a, t_stack *b)
{	
	if (a->size == 2)
	{
		if (stackget(a, 0) < stackget(a, 1))
			exec(SA, a, b);
	}
	if (a->size > 3)
		ft_radixsort(a, b);
	else
		simplesort(a, b);
}

static void	init_stacks(t_stack *a, char **argv)
{
	int	cidx;

	cidx = a->max_size - 1;
	while (cidx >= 0)
	{
		stackadd(a, ft_atoi(*(argv + cidx)));
		cidx--;
	}
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

int	is_sorted(t_stack *a)
{
	int	cidx;
	int	comp;

	cidx = 1;
	comp = stackget(a, 0);
	while (cidx < a->size)
	{
		if (!(stackget(a, cidx) < comp))
			return (0);
		comp = stackget(a, cidx);
		cidx++;
	}
	return (1);
}
