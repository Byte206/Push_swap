/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:42:16 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/14 13:58:38 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_stack **b, char flag)
{
	if (flag == 'a')
	{
		if ((*a)->value > (*a)->next->value)
			rotate(a, 'a');
	}
	else
	{
		if ((*b)->value < (*b)->next->value)
			rotate(b, 'b');
		push(b, a, 'a');
		push(b, a, 'a');
	}
}
