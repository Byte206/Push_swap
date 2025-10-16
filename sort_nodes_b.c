/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:23:12 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/16 10:29:16 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack *current_a;
	t_stack *target_node;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr
				&& current_a->nbr < best_index)
			{
				best_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = get_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}


void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
