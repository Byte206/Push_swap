/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:08:37 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/16 10:53:47 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_push(t_stack **stack, t_stack *top_node, char flag)
{
	while (*stack != top_node)
	{
		if (flag == 'a')
		{
			if (top_node->above_median)
				rotate(stack, 'a');
			else
				reverse_rotate(stack, 'a');
		}
		else if (flag == 'b')
		{
			if (top_node->above_median)
				rotate(stack, 'b');
			else 
				reverse_rotate(stack, 'b');
		}
	}
}


void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
	{
		rotate_rotate(a, b);
	}
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
	{
		reverse_reverse(a, b);
	}
	prep_push(a, cheapest_node, 'a');
	prep_push(b, cheapest_node->target_node, 'b');
	push(b, a, 'b');
}

void	b_to_a(t_stack **a, t_stack **b)
{
	prep_push(a, (*b)->target_node, 'a');
	push(a, b, 'a');
}
