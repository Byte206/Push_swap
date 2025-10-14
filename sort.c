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

t_node	*create_stack(long	*nbr_list, int	num_count)
{
	t_node	*head;
	t_node	*prev;
	t_node	*curr;
	int		i;
	
	head = NULL;
	prev = NULL;
	curr = NULL;
	i = 0;
	while (i < num_count)
	{
		curr = malloc(sizeof(t_node));
		if (!curr)
		{
			while (head)
			{
				t_node *tmp;
				tmp = head;
				head = head->next;
				free(tmp);
			}
			return (NULL);
		}
		curr->value = nbr_list[i];
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

void	push_swap(long	*nbr_list, int	num_count, t_node	**a,t_node	**b)
{
	*a = create_stack(nbr_list, num_count);
	*b = NULL;

	if (!*a)
	{
		ft_printf("Error creating stack\n");
		return ;
	}
}
