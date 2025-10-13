/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:12:04 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/13 17:56:05 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_syntax(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (1);
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (!argv[i][j])
				break;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
			while (ft_isdigit(argv[i][j]))
				j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Missing numbers\n");
		return (1);
	}
	if (check_syntax(argv))
	{
		ft_printf("Syntax Error\n");
		return (1);
	}
	ft_printf("Nice arguments\n");
	return (0);
}

