/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:28:47 by tmasur            #+#    #+#             */
/*   Updated: 2022/09/26 14:28:52 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_arguments_valid(char **clean_argv)
{
	if (!ft_are_all_arguments_numbers(clean_argv) || \
			!ft_are_all_arguments_integer(clean_argv) || \
			ft_are_dublicates_found(clean_argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	ft_count_values(char **clean_argv)
{
	char	**tmp_arr;

	tmp_arr = clean_argv;
	while (*clean_argv)
		clean_argv++;
	return (clean_argv - tmp_arr);
}

int	*ft_parse_argv_to_int_array(char **clean_argv)
{
	int	*int_arr;
	int	*tmp_arr;

	int_arr = malloc(sizeof(*int_arr) * ft_count_values(clean_argv));
	tmp_arr = int_arr;
	while (*clean_argv)
		*tmp_arr++ = ft_atoi(*clean_argv++);
	return (int_arr);
}

int	ft_are_dublicates_found(char **clean_argv)
{
	int	*int_arr;
	int	value_count;
	int	i;
	int	j;

	int_arr = ft_parse_argv_to_int_array(clean_argv);
	value_count = ft_count_values(clean_argv);
	i = 0;
	while (i < value_count)
	{
		j = i + 1;
		while (j < value_count)
		{
			if (*(int_arr + i) == *(int_arr + j++))
			{
				free(int_arr);
				return (1);
			}
		}
		i++;
	}
	free(int_arr);
	return (0);
}
