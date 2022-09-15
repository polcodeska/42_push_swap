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
