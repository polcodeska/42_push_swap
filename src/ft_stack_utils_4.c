/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:38:41 by guy               #+#    #+#             */
/*   Updated: 2022/09/23 13:09:31 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_pos_of_highest_index_in_stack(t_stack *st)
{
	t_node	*nd_return;
	t_node	*nd_run;

	nd_return = st->first_nd;
	nd_run = st->first_nd->next;
	while (nd_run)
	{
		if (nd_run->index > nd_return->index)
			nd_return = nd_run;
		nd_run = nd_run->next;
	}
	return (nd_return->pos);
}

t_node	*ft_get_cheapest_node(t_stack *st)
{
	t_node	*nd_return;
	t_node	*nd_run;

	nd_return = st->first_nd;
	nd_run = st->first_nd->next;
	while (nd_run)
	{
		if (nd_run->total_costs < nd_return->total_costs)
			nd_return = nd_run;
		nd_run = nd_run->next;
	}
	return (nd_return);
}

void	ft_execute_rotation_both_stack(t_node *nd, t_stack *st_a, t_stack *st_b)
{
	while (nd->cost_a > 0 && nd->cost_b > 0)
	{
		ft_rotate_both_stacks(st_a, st_b);
		nd->cost_a--;
		nd->cost_b--;
	}
	while (nd->cost_a < 0 && nd->cost_b < 0)
	{
		ft_reverse_rotate_both_stacks(st_a, st_b);
		nd->cost_a++;
		nd->cost_b++;
	}
}

void	ft_execute_rotation_one_stack(t_node *nd, t_stack *st_a, t_stack *st_b)
{
	while (nd->cost_a > 0)
	{
		ft_rotate_stack(st_a, 1);
		nd->cost_a--;
	}
	while (nd->cost_a < 0)
	{
		ft_reverse_rotate_stack(st_a, 1);
		nd->cost_a++;
	}
	while (nd->cost_b > 0)
	{
		ft_rotate_stack(st_b, 1);
		nd->cost_b--;
	}
	while (nd->cost_b < 0)
	{
		ft_reverse_rotate_stack(st_b, 1);
		nd->cost_b++;
	}
}

void	ft_execute_operations(t_node *nd, t_stack *st_a, t_stack *st_b)
{
	ft_execute_rotation_both_stack(nd, st_a, st_b);
	ft_execute_rotation_one_stack(nd, st_a, st_b);
	ft_push_node_to_other_stack(st_b, st_a);
}
