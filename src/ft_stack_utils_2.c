/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:39:00 by guy               #+#    #+#             */
/*   Updated: 2022/09/22 19:15:20 by guy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_abs(int value);

void	ft_set_total_costs(t_stack *st)
{
	t_node	*nd;

	nd = st->first_nd;
	while (nd)
	{
		if ((nd->cost_a < 0 && nd->cost_b < 0) || \
				(nd->cost_a > 0 && nd->cost_b > 0))
		{
			if (ft_abs(nd->cost_a) > ft_abs(nd->cost_b))
				nd->total_costs = ft_abs(nd->cost_a);
			else
				nd->total_costs = ft_abs(nd->cost_b);
		}
		else
			nd->total_costs = ft_abs(nd->cost_a) + ft_abs(nd->cost_b);
		nd = nd->next;
	}
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

int	ft_is_in_asc_order(int a, int b)
{
	return (a >= b);
}

int	ft_is_in_desc_order(int a, int b)
{
	return (a <= b);
}

int	ft_is_stack_sorted(t_stack *st, int (*ft_is_in_order)(int, int))
{
	t_node	*nd;

	nd = st->first_nd;
	while (nd->next)
	{
		if (ft_is_in_order(nd->value, nd->next->value))
			return (0);
		nd = nd->next;
	}
	return (1);
}