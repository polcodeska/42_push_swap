#include "../include/push_swap.h"

void ft_init_nd(t_node *nd, int value, int pos)
{
    nd->value = value;
	nd->pos = pos;
    nd->index = 0;
	nd->target_pos = 0;
	nd->cost_a = 0;
	nd->cost_b = 0;
	nd->prev = NULL;
	nd->next = NULL;
}

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
