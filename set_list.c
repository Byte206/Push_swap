/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:26:28 by gamorcil          #+#    #+#             */
/*   Updated: 2025/10/13 20:44:18 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_in_str(const char *str)
{
	int	count;
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ((str[i] == '-') && ft_isdigit(str[i + 1])))
		{
			if (!flag)
			{
				count++;
				flag = 1;
			}
		}
		else if (is_space(str[i]) || !ft_isdigit(str[i]))
			flag = 0;
		i++;
	}
	return (count);
}

int	count_numbers(int argc, char **argv)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < argc)
	{
		if (argv[i])
			count += count_in_str(argv[i]);
		i++;
	}
	return (count);
}

int	process_splitted(char **splitted, long *list, int *index)
{
	int		i;
	long	num;

	i = 0;
	while (splitted[i])
	{
		num = ft_atol(splitted[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			ft_printf("Overflow error\n");
			return (1);
		}
		list[*index] = num;
		(*index)++;
		i++;
	}
	return (0);
}

int	process_argv(int argc, char **argv, long *list, int *num_count)
{
	int		i;
	int		j;
	char	**splitted;

	j = 0;
	i = 0;
	while (i < argc)
	{
		if (argv[i])
		{
			splitted = ft_split(argv[i], ' ');
			if (!splitted)
				return (1);
			if (process_splitted(splitted, list, &j))
			{
				free_splitted(splitted);
				return (1);
			}
			free_splitted(splitted);
		}
		i++;
	}
	*num_count = j;
	return (0);
}

long	*set_list(int argc, char **argv, int *num_count)
{
	int		total_numbers;
	long	*list;

	total_numbers = count_numbers(argc, argv);
	if (total_numbers == 0)
	{
		ft_printf("No numbers\n");
		return (NULL);
	}
	list = (long *)malloc(total_numbers * sizeof(long));
	if (!list)
	{
		ft_printf("Malloc fail\n");
		return (NULL);
	}
	if (process_argv(argc, argv, list, num_count))
	{
		free(list);
		return (NULL);
	}
	return (list);
}
