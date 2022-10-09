/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:29:20 by tmasur            #+#    #+#             */
/*   Updated: 2022/10/09 14:43:24 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**clean_argv;
	t_stack	st_a;
	t_stack	st_b;

	if (argc < 2)
		return (0);
	else if (argc < 3)
	{
		clean_argv = ft_split(argv[1], ' ');
		ft_push_swap(clean_argv, &st_a, &st_b, 1);
	}
	else
	{
		clean_argv = &argv[1];
		ft_push_swap(clean_argv, &st_a, &st_b, 0);
	}
	return (0);
}

void	ft_push_swap(char **clean_argv, t_stack *st_a, t_stack *st_b,
		int is_arg_str)
{
	if (ft_arguments_valid(clean_argv))
	{
		ft_init_stacks(st_a, st_b);
		ft_fill_stack_on_start(st_a, clean_argv, is_arg_str);
		if (ft_is_stack_sorted(st_a, ft_is_in_asc_order))
		{
			ft_free_all_nodes_in_stack(st_a);
			if (is_arg_str)
				free(clean_argv);
			return ;
		}
		if (st_a->nd_count == 2)
			ft_swap_first_nodes_on_stack(st_a);
		else if (st_a->nd_count == 3)
			ft_run_algo_for_three_values(st_a);
		else
			ft_run_algo_for_more_than_three_values(st_a, st_b);
		ft_free_all_nodes_in_stack(st_a);
		if (is_arg_str)
			free(clean_argv);
	}
}
