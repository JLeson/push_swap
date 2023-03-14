/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:48 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/03/14 16:46:41 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 0
# define SB 1
# define SS	3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_stack
{
	int	*array;
	int	size;
	int	max_size;
}		t_stack;

//	ALGORITHMS

void	ft_radixsort(t_stack *a, t_stack *b);
void	mediumsort(t_stack *a, t_stack *b);
void	simplesort(t_stack *a, t_stack *b);

//	parse_arg.c

char	**get_elements(int argc, char **argv);
int		get_stack_size(int argc, char **argv);

//	stack.c

t_stack	*new_stack(int max_size);
void	stackadd(t_stack *stack, int val);
void	stackpop(t_stack *stack);
int		stackset(t_stack *stack, int idx, int val);
int		stackget(t_stack *stack, int idx);

//	operation.c

int		swap(t_stack *stack);
void	push(t_stack *stack_from, t_stack *stack_to);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);

//	execute.c

void	exec(int operation, t_stack *a, t_stack *b);

//	validate.c

int		valid(char **elements, int size, int argv_offset);

//	algoutils.c

t_stack	*normalize_stack(t_stack *a);
int		get_idx(t_stack	*stack, int val);
void	chexec(int operation, t_stack *a, t_stack *b, int c);
int		is_sorted(t_stack *stack);

// utils.c

void	*free_stack(t_stack *stack);
void	*free_elements(char **elements, unsigned int count, int argc);

//	print.c

// void	print_stack(t_stack *stack);
// void	print_stackv(t_stack *stack);
// void	print_stacks(t_stack *stack_a, t_stack *stack_b);
// void	print_stacksv(t_stack *stack_a, t_stack *stack_b);
#endif