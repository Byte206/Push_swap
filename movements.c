/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:04:49 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/14 15:36:27 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src, char flag)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	tmp->prev = NULL;
	*dst = tmp;
	if (flag == 'a' || flag == 'b')
		ft_printf("p%c\n", flag);
}

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void rotate(t_stack **stack, char flag)
{
    t_stack *first;
    t_stack *last;
    
    if (!stack || !*stack || !(*stack)->next)
        return ;
    
    first = *stack;
    last = get_last(*stack);
    
    // El primer nodo se convierte en el último
    *stack = first->next;        // El segundo nodo es ahora el primero
    (*stack)->prev = NULL;       // El nuevo primero no tiene prev
    
    first->next = NULL;          // El antiguo primero ahora es último
    first->prev = last;          // Su prev apunta al antiguo último
    last->next = first;          // El antiguo último apunta al nuevo último
    
    if (flag == 'a' || flag == 'b')
        ft_printf("r%c\n", flag);
}

void	swap(t_stack **stack, char flag)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if ((*stack)->next)
	{
		tmp = (*stack)->next;
		if (tmp->next)
		{
			(*stack)->next = tmp->next;
			tmp->next->prev = *stack;
		}
		else
			(*stack)->next = NULL;
		tmp->next = (*stack);
		tmp->prev = NULL;
		(*stack)->prev = tmp;
		(*stack) = tmp;
		if (flag == 'a' || flag == 'b')
			ft_printf("s%c\n", flag);
	}
}

void	swap_swap(t_stack **a, t_stack **b)
{
	if ((*a)->next && (*b)->next)
	{
		swap(a, 'n');
		swap(b, 'n');
		ft_printf("ss\n");
	}
	else if ((*a)->next)
		swap(a, 'a');
	else if ((*b)->next)
		swap(b, 'b');
}
