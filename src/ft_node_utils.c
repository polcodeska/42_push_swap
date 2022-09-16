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
