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

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		num_count;
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
	//set_stack(&a, argv, argc);
	return (0);
}
