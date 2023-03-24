/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:32:25 by joel              #+#    #+#             */
/*   Updated: 2023/03/24 17:41:15 by fsarkoh          ###   ########.fr       */
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

# define SUCCES 0
# define ERROR	1

# define TRUE	1
# define FALSE	0

# define ERROR_MSG "Error\n"

typedef struct s_stack	t_stack;

typedef struct s_stack
{
	int				*array;
	unsigned int	size;
	unsigned int	max_size;
}	t_stack;

//	parse.c

char			**parse_argv(unsigned int argc, char **argv);
unsigned int	get_n_args(char *arg, char c);

//	init.c

char			**init_args(int argc, char **argv);
unsigned int	init_n_args(int argc, char **argv);
void			init_stack(t_stack *stack, char **args);

//	valid.c

unsigned int	is_valid(char **args, unsigned int size);

//	stack.c

t_stack			*new_stack(unsigned int max_size);
void			stackadd(t_stack *stack, int val);
void			stackpop(t_stack *stack);
void			stackset(t_stack *stack, unsigned int idx, int val);
int				stackget(t_stack *stack, unsigned int idx);

//	operations.c

void			push(t_stack *stack_from, t_stack *stack_to);
void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			rrotate(t_stack *stack);

//	execution.c

void			exec(unsigned int operation, t_stack *a, t_stack *b);

//	algo_util.c

int				is_sorted(t_stack *stack);
t_stack			*normalize_stack(t_stack *stack);
void			chexec(unsigned int operation, t_stack *a, t_stack *b,
					unsigned int c);
unsigned int	get_idx(t_stack	*stack, int val);

//	ALGOS

void			minisort(t_stack *a, t_stack *b);
void			smallsort(t_stack *a, t_stack *b);
void			ft_radixsort(t_stack *a, t_stack *b);

//	UTILS

//		memory.c

void			free_str_array(char **str_array, unsigned int n_args);
void			free_stack(t_stack *stack);

//	print.c

void			print_stack(t_stack *stack, unsigned int verbose);
#endif