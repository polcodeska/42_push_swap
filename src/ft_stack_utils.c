#include "../include/push_swap.h"

void ft_init_stacks(t_stack *st_a, t_stack *st_b)
{
    st_a->id = 0;
	st_a->nd_count = 0;
	st_a->first_nd = NULL;
	st_a->last_nd = NULL;
	st_b->id = 1;
	st_b->nd_count = 0;
	st_b->first_nd = NULL;
	st_b->last_nd = NULL;
}

void ft_set_new_pos_for_all_nodes_on_stack(t_stack *st)
{
	int i;
	t_node *nd;

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

void ft_fill_stack_on_start(t_stack *st, char **clean_argv)
{
	int *int_arr;
	int i;
	t_node *nd;

	int_arr = ft_parse_argv_to_int_array(clean_argv);
	i = 0;
	while (clean_argv[i])
	{
		nd = malloc(sizeof *nd);
		ft_init_nd(nd, int_arr[i], i);
		ft_add_node_on_bottom(st, nd);
		i++;
	}
}

void ft_add_node_on_top(t_stack *st, t_node *nd)
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

void ft_add_node_on_bottom(t_stack *st, t_node *nd)
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

t_node *ft_pop_node_from_top(t_stack *st)
{
	t_node *nd;

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

t_node *ft_pop_node_from_bottom(t_stack *st)
{
	t_node *nd;

	st->nd_count--;
	if (!st->last_nd)
		return (NULL);
	else if (!st->last_nd->prev)
	{
		nd = st->last_nd;;
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

void ft_swap_first_nodes_on_stack(t_stack *st)
{
    t_node *nd_a;
    t_node *nd_b;

	if (st->nd_count > 1)
	{
		nd_a = ft_pop_node_from_top(st);
		nd_b = ft_pop_node_from_top(st);
		ft_putstr_fd("No probs\n", 1);
		ft_add_node_on_top(st, nd_a);
		ft_add_node_on_top(st, nd_b);
		ft_putstr_fd("s", 1);
		if (st->id == 0)
			ft_putstr_fd("a\n", 1);
		else
			ft_putstr_fd("b\n", 1);
	}
}

void ft_push_node_to_other_stack(t_stack *st_a, t_stack *st_b)
{
	ft_add_node_on_top(st_b, ft_pop_node_from_top(st_a));
}

void ft_rotate_stack(t_stack *st)
{
	ft_add_node_on_bottom(st, ft_pop_node_from_top(st));
}

void ft_rotate_both_stacks(t_stack *st_a, t_stack *st_b)
{
	ft_rotate_stack(st_a);
	ft_rotate_stack(st_b);
}

void ft_reverse_rotate_stack(t_stack *st)
{
	ft_add_node_on_top(st, ft_pop_node_from_bottom(st));
}

void ft_reverse_rotate_both_stacks(t_stack *st_a, t_stack *st_b)
{
	ft_reverse_rotate_stack(st_a);
	ft_reverse_rotate_stack(st_b);
}
