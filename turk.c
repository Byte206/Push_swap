/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:32:30 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/15 20:46:33 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min(t_stack **a)
{
	while ((*a)->nbr != get_min(*a)->nbr)
	{
		if (get_min(*a)->above_median)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
}

int	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_everything(t_stack **a, t_stack **b, int num_count)
{
	int	len_a;

	len_a = num_count;
	if (len_a-- > 3 && !stack_sorted(*a))
		push(b, a, 'b');
	if (len_a-- > 3 && !stack_sorted(*a))
		push(b, a, 'b');
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		b_to_a(a, b);
	}
	current_index(*a);
	sort_min(a);
}
