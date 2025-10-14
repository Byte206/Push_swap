/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:33:39 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/13 16:34:07 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_repeated(long *nbr_list,int	num_count)
{
	int i;
	int	j;

	i = 0;
	while (i < num_count)
	{
		j = 0;
		while (j < num_count)
		{
			if (nbr_list[i] == nbr_list[j] && i != j)
			{
				ft_printf("Repeated numbers\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}


int	is_sorted(long	*nbr_list, int num_count)
{
	int	i;

	if (check_repeated(nbr_list, num_count))
		return (1);
	i = 0;
	while (i < num_count - 1)
	{
		if (nbr_list[i] > nbr_list[i + 1])
		{
			//ft_printf("Not sorted\n");
			return (2);
		}
		i++;
	}
	//ft_printf("Already sorted\n");
	return (0);
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		num_count;
	int		sorted_status;
	long	*nbr_list;


	num_count = 0;
	nbr_list = NULL;
	if (check_errors(argc, argv))
		return (1);
	nbr_list = set_list(argc - 1, argv + 1, &num_count);
	if (!nbr_list)
		return (1);
	ft_printf("Numero de numeros:%d\n", num_count);
	for (int i = 0; i < num_count; i++)
		printf("%ld\n", nbr_list[i]);
	sorted_status = is_sorted(nbr_list, num_count);
	if (sorted_status == 2)
	{
		push_swap(nbr_list, num_count, &a, &b);
		ft_printf("Need to sort\n");
		return (0);
	}
	else if(sorted_status == 1)
	{
		free(nbr_list);
		return (1);
	}
	else 
	{
		ft_printf("Already sorted\n");
		free(nbr_list);	
		return (0);
	}
	//set_stack(&a, argv, argc);
	return (0);
}
