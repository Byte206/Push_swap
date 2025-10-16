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
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

//Errors.c
int	check_syntax(char **argv);
int	check_errors(int argc, char **argv);

//Free_memory.c
void	free_splitted(char **splitted);
void	free_stack(t_stack **stack);

//ft_atol.c
int	is_space(char c);
long	ft_atol(const char *str);

//main.c
int	check_repeated(long *nbr_list,int	num_count);
int	is_sorted(long	*nbr_list, int num_count);

//move_stacks.c
void	a_to_b(t_stack **a, t_stack **b);
void	prep_push(t_stack **stack, t_stack *top_node, char flag);
void	b_to_a(t_stack **a, t_stack **b);

//movements_utils.c
void	rotate_rotate(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack, char flag);
void	reverse_reverse(t_stack **a, t_stack **b);

//movements.c
void	push(t_stack **dst, t_stack **src, char flag);
t_stack	*get_last(t_stack *stack);
void	rotate(t_stack **stack, char flag);
void	swap(t_stack **stack, char flag);
void	swap_swap(t_stack **a, t_stack **b);

//set_list.c
int	count_in_str(const char *str);
int	count_numbers(int argc, char **argv);
int	process_splitted(char **splitted, long *list, int *index);
int	process_argv(int argc, char **argv, long *list, int *num_count);
long	*set_list(int argc, char **argv, int *num_count);

//sort_nodes_a.c
void	set_target_a(t_stack *a, t_stack *b);
void	get_cost_a(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);

//sort_nodes_b.c
void	set_target_b(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);

//short_three.c
void	sort_three(t_stack **a);

//sort.c
void	append_node(t_stack **stack, int num);
t_stack	*create_stack(long *nbr_list, int num_count);
void	push_swap(long	*nbr_list, int	num_count, t_stack	**a,t_stack	**b);


//stack_utils.c
int	get_stack_len(t_stack *stack);
t_stack	*get_max(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
t_stack	*get_min(t_stack *a);

//turk.c
int	stack_sorted(t_stack *stack);
void	sort_everything(t_stack **a, t_stack **b, int num_count);


#endif
