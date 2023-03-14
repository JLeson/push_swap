/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:30 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/14 16:46:43 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static void	start_sort(t_stack *a, t_stack *b);
static void	init_stacks(t_stack *a, char **argv, int argv_offset);
static void	free_stacks(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	char	**elements;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	elements = get_elements(argc, argv);
	if (!elements)
		return (1);
	if (!valid(elements, get_stack_size(argc, argv), argc > 2))
		return ((int)free_elements(elements,
				get_stack_size(argc, argv), argc) + 1);
	a = new_stack(get_stack_size(argc, argv));
	if (!a)
		return (1);
	b = new_stack(a->max_size);
	if (!b)
		return ((int)free_stack(a) + 1);
	init_stacks(a, elements, argc > 2);
	start_sort(a, b);
	free_elements(elements, a->max_size, argc);
	free_stacks(a, b);
	return (0);
}

static void	start_sort(t_stack *a, t_stack *b)
{	
	if (a->max_size == 1)
		return ;
	if (a->max_size == 2)
	{
		if (stackget(a, 0) < stackget(a, 1))
			exec(SA, a, b);
	}
	else if (a->max_size == 3)
		simplesort(a, b);
	else if (a->max_size > 5)
		ft_radixsort(a, b);
	else
		mediumsort(a, b);
}

static void	init_stacks(t_stack *a, char **argv, int argv_offset)
{
	int	cidx;

	cidx = a->max_size - 1 + argv_offset;
	while (cidx >= argv_offset)
	{
		stackadd(a, ft_atoi(*(argv + cidx)));
		cidx--;
	}
}

static void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}
