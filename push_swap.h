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
void	set_stack(&a, char **argv,int argc);

#endif
