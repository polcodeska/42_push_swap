/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:37:13 by tmasur            #+#    #+#             */
/*   Updated: 2022/09/22 19:39:41 by guy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_run_algo_for_three_values(t_stack *st)
{
	t_node	*nd_a;
	t_node	*nd_b;
	t_node	*nd_c;

	while (!ft_is_stack_sorted(st, ft_is_in_asc_order))
	{
		nd_a = st->first_nd;
		nd_b = st->first_nd->next;
		nd_c = st->last_nd;
		if (nd_a->index > nd_b->index && \
				nd_a->index > nd_c->index)
			ft_rotate_stack(st, 1);
		else if (nd_b->index > nd_a->index && \
				nd_b->index > nd_c->index)
			ft_reverse_rotate_stack(st, 1);
		else if (nd_a->index > nd_b->index)
			ft_swap_first_nodes_on_stack(st);
	}
}

void	ft_run_algo_for_more_than_three_values(t_stack *st_a, t_stack *st_b)
{
	t_node	*nd;

	while (st_a->nd_count > 3)
		ft_push_node_to_other_stack(st_a, st_b);
	ft_run_algo_for_three_values(st_a);
	while (st_b->nd_count > 0)
	{
		ft_set_target_pos_for_nodes(st_a, st_b);
		ft_set_costs(st_a, st_b);
		nd = ft_get_cheapest_node(st_b);
		ft_execute_operations(nd, st_a, st_b);
	}
	while (st_a->first_nd->index < ((st_a->nd_count / 2) + 1) && \
			!ft_is_stack_sorted(st_a, ft_is_in_asc_order))
		ft_reverse_rotate_stack(st_a, 1);
	while (!ft_is_stack_sorted(st_a, ft_is_in_asc_order))
		ft_rotate_stack(st_a, 1);
}
