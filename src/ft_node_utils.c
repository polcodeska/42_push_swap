#include "../include/push_swap.h"

void ft_init_nd(t_node *nd, int value, int pos)
{
	ft_set_nd_value(nd, value);
	ft_set_nd_pos(nd, pos);
}

void ft_set_nd_value(t_node *nd, int value)
{
	nd->value = value;
}

void ft_set_nd_index(t_node *nd, int index)
{
	nd->index= index;
}

void ft_set_nd_pos(t_node *nd, int pos)
{
	nd->pos = pos;
}

void ft_set_nd_target(t_node *nd, int target_pos)
{
	nd->target_pos = target_pos;
}

void ft_set_nd_cost_a(t_node *nd, int cost_a)
{
	nd->cost_a = cost_a;
}

void ft_set_nd_cost_b(t_node *nd, int cost_b)
{
	nd->cost_b = cost_b;
}

void ft_set_nd_next(t_node *nd, t_node *next)
{
	nd->next = next;
}

void ft_set_nd_prev(t_node *nd, t_node *prev)
{
	nd->prev = prev;
}

int ft_get_nd_value(t_node *nd)
{
	return (nd->value);
}

int ft_get_nd_index(t_node *nd)
{
	return (nd->index);
}

int ft_get_nd_pos(t_node *nd)
{
	return (nd->pos);
}

int ft_get_nd_target_pos(t_node *nd)
{
	return (nd->target_pos);
}

int ft_get_nd_cost_a(t_node *nd)
{
	return (nd->cost_a);
}

int ft_get_nd_cost_b(t_node *nd)
{
	return (nd->cost_b);
}

t_node *ft_get_nd_next(t_node *nd)
{
	return (nd->next);
}

t_node *ft_get_nd_prev(t_node *nd)
{
	return (nd->prev);
}
