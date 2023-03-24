/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:32:25 by joel              #+#    #+#             */
/*   Updated: 2023/03/24 15:34:48 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

//	init.c

char			**init_args(int argc, char **argv);
unsigned int	init_n_args(int argc, char **argv);
void			init_stack(t_stack *stack, char **args);

//	stack.c

t_stack			*new_stack(unsigned int max_size);
void			stackadd(t_stack *stack, int val);
void			stackpop(t_stack *stack);
void			stackset(t_stack *stack, unsigned int idx, int val);
int				stackget(t_stack *stack, unsigned int idx);

//	print.c

void			print_stack(t_stack *stack, unsigned int verbose);

//	operations.c

void			push(t_stack *stack_from, t_stack *stack_to);
void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			rrotate(t_stack *stack);

//	parse.c

char			**parse_argv(unsigned int argc, char **argv);
unsigned int	get_n_args(char *arg, char c);

//	valid.c

unsigned int	is_valid(char **args, unsigned int size);

//	UTILS

//		memory.c

void			free_str_array(char **str_array, unsigned int n_args);
void			free_stack(t_stack *stack);
#endif