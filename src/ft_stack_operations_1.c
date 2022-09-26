/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:26:42 by tmasur            #+#    #+#             */
/*   Updated: 2022/09/26 14:26:44 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_add_node_on_top(t_stack *st, t_node *nd)
{
	if (!nd)
		return ;
	if (!st->first_nd && !st->last_nd)
	{
		st->first_nd = nd;
		st->last_nd = nd;
	}
	else
	{
		nd->next = st->first_nd;
		st->first_nd->prev = nd;
		st->first_nd = nd;
	}
	st->nd_count++;
}

void	ft_add_node_on_bottom(t_stack *st, t_node *nd)
{
	if (!nd)
		return ;
	if (!st->first_nd && !st->last_nd)
	{
		st->first_nd = nd;
		st->last_nd = nd;
	}
	else
	{
		nd->prev = st->last_nd;
		st->last_nd->next = nd;
		st->last_nd = nd;
	}
	st->nd_count++;
}

t_node	*ft_pop_node_from_top(t_stack *st)
{
	t_node	*nd;

	st->nd_count--;
	if (!st->first_nd)
		return (NULL);
	else if (!st->first_nd->next)
	{
		nd = st->first_nd;
		st->first_nd = NULL;
		st->last_nd = NULL;
		return (nd);
	}
	else
	{
		nd = st->first_nd;
		st->first_nd = nd->next;
		st->first_nd->prev = NULL;
		nd->next = NULL;
		return (nd);
	}
}

t_node	*ft_pop_node_from_bottom(t_stack *st)
{
	t_node	*nd;

	st->nd_count--;
	if (!st->last_nd)
		return (NULL);
	else if (!st->last_nd->prev)
	{
		nd = st->last_nd;
		st->first_nd = NULL;
		st->last_nd = NULL;
		return (nd);
	}
	else
	{
		nd = st->last_nd;
		st->last_nd = nd->prev;
		st->last_nd->next = NULL;
		nd->prev = NULL;
		return (nd);
	}
}

void	ft_push_node_to_other_stack(t_stack *st_a, t_stack *st_b)
{
	ft_add_node_on_top(st_b, ft_pop_node_from_top(st_a));
	ft_set_new_pos_for_all_nodes_on_stack(st_a);
	ft_set_new_pos_for_all_nodes_on_stack(st_b);
	ft_putstr_fd("p", 1);
	if (st_a->id == 1)
		ft_putstr_fd("a\n", 1);
	else
		ft_putstr_fd("b\n", 1);
}
