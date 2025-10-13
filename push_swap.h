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

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack;	

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

#endif
