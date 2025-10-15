/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:11:08 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/14 10:19:12 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack **stack, int num)
{
	t_stack *node;
	t_stack *last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = num;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	*create_stack(long *nbr_list, int num_count)
{
	t_stack	*stack;
	int		i;

	if (!nbr_list || num_count <= 0)
		return (NULL);
	stack = NULL;
	i = 0;
	while (i < num_count)
	{
		append_node(&stack, (int)nbr_list[i]);
		i++;
	}
	return (stack);
}

void	push_swap(long	*nbr_list, int	num_count, t_stack	**a,t_stack	**b)
{
	*a = create_stack(nbr_list, num_count);
	*b = NULL;

	if (!*a)
	{
		ft_printf("Error creating stack\n");
		return ;
	}
	if (num_count == 2)
	{
		swap(a, 'a');
	}
	else if (num_count == 3)
	{
		sort_three(a);
	}
	else
		sort_everything(a, b, num_count);
	free_stack(a);
	return ;
}
