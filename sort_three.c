/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:10:31 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/14 14:11:29 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = get_max(*a);
	if (biggest_node == *a)
		rotate(a, 'a');
	else if ((*a)->next == biggest_node)
		reverse_rotate(a, 'a');
	if ((*a)->nbr > (*a)->next->nbr)
		swap(a, 'a');
}
