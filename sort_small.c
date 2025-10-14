/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:33:32 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/14 13:55:37 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **a, t_stack **b, int num_count)
{
	if (num_count == 2)
		sort_two(a, b, 'a');
	else if (num_count == 3)
		sort_three(a, b, 'a', num_count);
	else if(num_count == 7)
	{
		
	}
}
