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

t_stack	*create_stack(long *nbr_list, int num_count)
{
	t_stack	*head;
	t_stack	*prev;
	t_stack	*curr;
	int		i;

	head = NULL;
	prev = NULL;
	i = 0;
	while (i < num_count)
	{
		curr = malloc(sizeof(t_stack));
		if (!curr)
			return (NULL);
		curr->value = (int)nbr_list[i];
		curr->index = 0;
		curr->next = NULL;
		curr->prev = prev;
		if (prev)
			prev->next = curr;
		else
			head = curr;
		prev = curr;
		i++;
	}
	return (head);
}

void	assign_index(t_stack *head)
{
	t_stack	*aux;
	t_stack	*run;
	size_t	idx;

	aux = head;
	while (aux)
	{
		idx = 0;
		run = head;
		while (run)
		{
			if (run->value < aux->value)
				idx++;
			run = run->next;
		}
		aux->index = idx;
		aux = aux->next;
	}
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
	assign_index(*a);
	if (num_count < 8)
	{
		sort_small(a, b, num_count);
	}
	else if (num_count > 7)
	{

	}
}
