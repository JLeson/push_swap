/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:44:45 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/24 17:11:26 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	execp(unsigned int operation, t_stack *a, t_stack *b)
{
	if (operation == PA)
	{
		ft_printf("pa\n");
		push(b, a);
	}
	if (operation == PB)
	{
		ft_printf("pb\n");
		push(a, b);
	}
}

static void	execs(unsigned int operation, t_stack *a, t_stack *b)
{
	if (operation == SA)
	{
		ft_printf("sa\n");
		swap(a);
	}
	else if (operation == SB)
	{
		ft_printf("sb\n");
		swap(b);
	}
	else if (operation == SS)
	{
		ft_printf("ss\n");
		swap(a);
		swap(b);
	}
}

static void	execr(unsigned int operation, t_stack *a, t_stack *b)
{
	if (operation == RA)
	{
		ft_printf("ra\n");
		rotate(a);
	}
	else if (operation == RB)
	{
		ft_printf("rb\n");
		rotate(b);
	}
	else if (operation == RR)
	{
		ft_printf("rr\n");
		rotate(a);
		rotate(b);
	}
}

static void	execrr(unsigned int operation, t_stack *a, t_stack *b)
{
	if (operation == RRA)
	{
		ft_printf("rra\n");
		rrotate(a);
	}
	else if (operation == RRB)
	{
		ft_printf("rrb\n");
		rrotate(b);
	}
	else if (operation == RRR)
	{
		ft_printf("rrr\n");
		rrotate(a);
		rrotate(b);
	}
}

void	exec(unsigned int operation, t_stack *a, t_stack *b)
{
	if (operation == PA || operation == PB)
		execp(operation, a, b);
	else if (operation == SA || operation == SB || operation == SS)
		execs(operation, a, b);
	else if (operation == RA || operation == RB || operation == RR)
		execr(operation, a, b);
	else if (operation == RRA || operation == RRB || operation == RRR)
		execrr(operation, a, b);
}
