/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:34:20 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/13 16:34:22 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	size_t			index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;


//Checkers
int check_syntax(char **argv);


//atol
int	is_space(char c);
long	ft_atol(const char *str);

//main
int	check_errors(int argc, char **argv);
void	set_stack(t_stack **a, char **argv,int argc);

//set_list.c
long	*set_list(int argc, char **argv, int *num_count);
int	process_argv(int argc, char **argv, long *list, int *num_count);
int	count_numbers(int argc, char **argv);
int	count_in_str(const char *str);
void	free_splitted(char **splitted);
int	process_splitted(char **splitted, long *list, int *index);

//sort
void	push_swap(long	*nbr_list, int	num_count, t_stack	**a,t_stack	**b);
t_stack	*create_stack(long	*nbr_list, int	num_count);
void	assign_index(t_stack *head);

//sort_two
void	sort_two(t_stack **a, t_stack **b, char flag);

//sort_three
void	sort_three(t_stack **a, t_stack **b, char flag, int num_count);

//sort_small
void	sort_small(t_stack **a, t_stack **b, int num_count);


//MOVEMENTS
void	swap(t_stack **stack, char flag); // swap a && swap b
void	swap_swap(t_stack **first, t_stack **second); // ss
void	push(t_stack **first, t_stack **second, char flag); // push a && push b
void	rotate(t_stack **stack, char flag); // rotate a && rotate b
void	rotate_rotate(t_stack **first, t_stack **second); // rr
void	reverse_roate(t_stack **stack, char flag); // reverse rotate
void	reverse_reverse(t_stack **first, t_stack **second); // rrr

#endif
