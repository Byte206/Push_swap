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

void	rotate_rotate(t_stack **first, t_stack **second)
{
	if ((*first)->next && (*second)->next)
	{
		rotate(first, 'n');
		rotate(second, 'n');
		ft_printf("rr");
	}
	else if ((*first)->next)
		rotate(first, 'a');
	else if ((*second)->next)
		rotate(second, 'b');
}

void	reverse_rotate(t_stack **stack, char flag)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	tmp = (*stack)->next;
	if (tmp)
	{
		last = get_last(*stack);
		last->next = (*stack);
		(*stack)->prev = last;
		last->prev->next = NULL;
		(*stack) = last;
		if (flag == 'a' || flag == 'b')
			ft_printf("rr%c\n", flag);
	}
}

void	reverse_reverse(t_stack **first, t_stack **second)
{
	if ((*first)->next && (*second)->next)
	{
		reverse_rotate(first, 'n');
		reverse_rotate(second, 'n');
		ft_printf("rrr");
	}
	else if ((*first)->next)
		reverse_rotate(first, 'a');
	else if ((*second)->next)
		reverse_rotate(second, 'a');
}

t_stack	*get_max(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
