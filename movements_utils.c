/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:12:14 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/14 16:28:05 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rotate(t_stack **a, t_stack **b)
{
	if ((*a)->next && (*b)->next)
	{
		rotate(a, 'n');
		rotate(b, 'n');
		ft_printf("rr\n");
	}
	else if ((*a)->next)
		rotate(a, 'a');
	else if ((*b)->next)
		rotate(b, 'b');
}

void	reverse_rotate(t_stack **stack, char flag, int print)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = get_last(*stack);
	last->prev->next = NULL;
	last->next = (*stack);
	last->prev = NULL;
	(*stack)->prev = last;
	(*stack) = last;
	if ((flag == 'a' || flag == 'b') && print == 1)
		ft_printf("rr%c\n", flag);
}

void	reverse_reverse(t_stack **a, t_stack **b)
{
	if ((*a)->next && (*b)->next)
	{
		reverse_rotate(a, 'n', 0);
		reverse_rotate(b, 'n', 0);
		ft_printf("rrr\n");
	}
	else if ((*a)->next)
		reverse_rotate(a, 'a', 1);
	else if ((*b)->next)
		reverse_rotate(b, 'b', 1);
}
