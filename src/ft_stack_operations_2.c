/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:26:59 by tmasur            #+#    #+#             */
/*   Updated: 2022/09/28 08:25:59 by guy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap_first_nodes_on_stack(t_stack *st)
{
	t_node	*nd_first;
	t_node	*nd_second;

	if (st->nd_count > 1)
	{
		nd_first = ft_pop_node_from_top(st);
		nd_second = ft_pop_node_from_top(st);
		ft_add_node_on_top(st, nd_first);
		ft_add_node_on_top(st, nd_second);
		ft_putstr_fd("s", 1);
		if (st->id == 0)
			ft_putstr_fd("a\n", 1);
		else
			ft_putstr_fd("b\n", 1);
		ft_set_new_pos_for_all_nodes_on_stack(st);
	}
}

void	ft_rotate_stack(t_stack *st, int with_output)
{
	ft_add_node_on_bottom(st, ft_pop_node_from_top(st));
	ft_set_new_pos_for_all_nodes_on_stack(st);
	if (with_output)
	{
		ft_putstr_fd("r", 1);
		if (st->id == 0)
			ft_putstr_fd("a\n", 1);
		else
			ft_putstr_fd("b\n", 1);
	}
}

void	ft_rotate_both_stacks(t_stack *st_a, t_stack *st_b)
{
	ft_rotate_stack(st_a, 0);
	ft_rotate_stack(st_b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	ft_reverse_rotate_stack(t_stack *st, int with_output)
{
	ft_add_node_on_top(st, ft_pop_node_from_bottom(st));
	ft_set_new_pos_for_all_nodes_on_stack(st);
	if (with_output)
	{
		ft_putstr_fd("rr", 1);
		if (st->id == 0)
			ft_putstr_fd("a\n", 1);
		else
			ft_putstr_fd("b\n", 1);
	}
}

void	ft_reverse_rotate_both_stacks(t_stack *st_a, t_stack *st_b)
{
	ft_reverse_rotate_stack(st_a, 0);
	ft_reverse_rotate_stack(st_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
