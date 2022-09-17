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

void ft_set_indexes_for_all_nodes_on_stack(t_stack *st, int *int_arr)
{
    int i;
    int j;
    t_node *nd;

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
                break;
            }
            j++;
        }
        nd = nd->next;
        i++;
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
	ft_set_indexes_for_all_nodes_on_stack(st, int_arr);
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
		ft_add_node_on_top(st, nd_a);
		ft_add_node_on_top(st, nd_b);
		ft_putstr_fd("s", 1);
		if (st->id == 0)
			ft_putstr_fd("a\n", 1);
		else
			ft_putstr_fd("b\n", 1);
		ft_set_new_pos_for_all_nodes_on_stack(st);
	}
}

void ft_push_node_to_other_stack(t_stack *st_a, t_stack *st_b)
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

void ft_rotate_stack(t_stack *st)
{
	ft_add_node_on_bottom(st, ft_pop_node_from_top(st));
	ft_set_new_pos_for_all_nodes_on_stack(st);
	ft_putstr_fd("r", 1);
	if (st->id == 0)
		ft_putstr_fd("a\n", 1);
	else
		ft_putstr_fd("b\n", 1);
}

void ft_rotate_both_stacks(t_stack *st_a, t_stack *st_b)
{
	ft_rotate_stack(st_a);
	ft_rotate_stack(st_b);
	ft_putstr_fd("rr\n", 1);
}

void ft_reverse_rotate_stack(t_stack *st)
{
	ft_add_node_on_top(st, ft_pop_node_from_bottom(st));
	ft_set_new_pos_for_all_nodes_on_stack(st);
	ft_putstr_fd("rr", 1);
	if (st->id == 0)
		ft_putstr_fd("a\n", 1);
	else
		ft_putstr_fd("b\n", 1);
}

void ft_reverse_rotate_both_stacks(t_stack *st_a, t_stack *st_b)
{
	ft_reverse_rotate_stack(st_a);
	ft_reverse_rotate_stack(st_b);
	ft_putstr_fd("rrr\n", 1);
}

int ft_is_in_asc_order(int a, int b)
{
	return (a >= b);
}

int ft_is_in_desc_order(int a, int b)
{
	return (a <= b);
}

int ft_is_stack_sorted(t_stack *st, int (*ft_is_in_order)(int, int))
{
    t_node *nd;

    nd = st->first_nd;
    while (nd->next)
    {
        if (ft_is_in_order(nd->value, nd->next->value))
            return (0);
        nd = nd->next;
    }
    return (1);
}

void ft_run_algo_for_three_values(t_stack *st)
{
	t_node *nd_a;
	t_node *nd_b;
	t_node *nd_c;

	while (!ft_is_stack_sorted(st, ft_is_in_asc_order))
	{
		nd_a = st->first_nd;
		nd_b = st->first_nd->next;
		nd_c = st->last_nd;
		if (nd_a->index > nd_b->index &&
				nd_a->index > nd_c->index)
			ft_rotate_stack(st);
		else if (nd_b->index > nd_a->index &&
				nd_b->index > nd_c->index)
			ft_reverse_rotate_stack(st);
		else if (nd_a->index > nd_b->index)
			ft_swap_first_nodes_on_stack(st);
	}
}
