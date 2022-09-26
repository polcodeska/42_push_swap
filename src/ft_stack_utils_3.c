/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:28:10 by tmasur            #+#    #+#             */
/*   Updated: 2022/09/26 14:28:12 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_set_new_pos_for_all_nodes_on_stack(t_stack *st)
{
	int		i;
	t_node	*nd;

	i = 0;
	nd = st->first_nd;
	if (st->nd_count > 0)
	{
		while (nd->next)
		{
			nd->pos = i++;
			nd = nd->next;
		}
		nd->pos = i;
	}
}

void	ft_set_indexes_for_all_nodes_on_stack(t_stack *st, int *int_arr)
{
	int		i;
	int		j;
	t_node	*nd;

	ft_merge_sort(int_arr, 0, st->nd_count - 1);
	nd = st->first_nd;
	i = 0;
	while (i < st->nd_count)
	{
		j = 0;
		while (j < st->nd_count)
		{
			if (nd->value == *(int_arr + j))
			{
				nd->index = j + 1;
				break ;
			}
			j++;
		}
		nd = nd->next;
		i++;
	}
}

void	ft_set_target_pos_for_nodes(t_stack *st_a, t_stack *st_b)
{
	t_node	*nd_a;
	t_node	*nd_b;
	int		smallest_diff;

	nd_b = st_b->first_nd;
	while (nd_b)
	{
		smallest_diff = INT_MAX;
		nd_a = st_a->first_nd;
		nd_b->target_pos = ft_get_pos_of_highest_index_in_stack(st_a) + 1;
		while (nd_a)
		{
			if (nd_b->target_pos == st_a->nd_count)
				nd_b->target_pos = 0;
			if (nd_b->index < nd_a->index && \
					((nd_a->index - nd_b->index) < smallest_diff))
			{
				smallest_diff = nd_a->index - nd_b->index;
				nd_b->target_pos = nd_a->pos;
			}
			nd_a = nd_a->next;
		}
		nd_b = nd_b->next;
	}
}

void	ft_set_costs(t_stack *st_a, t_stack *st_b)
{
	t_node	*nd;

	nd = st_b->first_nd;
	while (nd)
	{
		nd->cost_b = nd->pos;
		if (nd->pos > st_b->nd_count / 2)
			nd->cost_b = nd->cost_b - st_b->nd_count;
		nd->cost_a = nd->target_pos;
		if (nd->target_pos > st_a->nd_count / 2)
			nd->cost_a = nd->cost_a - st_a->nd_count;
		nd = nd->next;
	}
	ft_set_total_costs(st_b);
}

void	ft_free_all_nodes_in_stack(t_stack *st)
{
	t_node	*nd;

	if (st->last_nd)
	{
		while (st->last_nd->prev)
		{
			nd = st->last_nd->prev;
			free(st->last_nd);
			st->last_nd = nd;
		}
	}
	free(st->last_nd);
}
