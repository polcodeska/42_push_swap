#include "../include/push_swap.h"

void ft_push_swap(char **clean_argv, t_stack *st_a, t_stack *st_b);

#include <stdio.h>
void ft_print_node(t_node *nd);
void ft_print_all_nodes_in_stack(t_stack *st);
static void ft_print_stack(t_stack *st);
static void ft_print_all_stacks(t_stack *st_a, t_stack *st_b);

int main(int argc, char **argv)
{
	char **clean_argv;
	t_stack st_a;
	t_stack st_b;

	if (argc < 2)
        return (0);
	else if (argc < 3)
		clean_argv = ft_split(argv[1], ' ');
	else
		clean_argv = &argv[1];
	ft_push_swap(clean_argv, &st_a, &st_b);
    return (0);
}

void ft_push_swap(char **clean_argv, t_stack *st_a, t_stack *st_b)
{
	if (ft_arguments_valid(clean_argv))
	{
		ft_init_stacks(st_a, st_b);
		ft_fill_stack_on_start(st_a, clean_argv);
		if (ft_is_stack_sorted(st_a, ft_is_in_asc_order))
			return ;
		if (st_a->nd_count == 2)
			ft_swap_first_nodes_on_stack(st_a);
		else if (st_a->nd_count == 3)
			ft_run_algo_for_three_values(st_a);
		else
			ft_run_algo_for_more_than_three_values(st_a, st_b);
		/* printf("------------------ Stack A:\n"); */
		/* ft_print_all_nodes_in_stack(st_a); */
		/* printf("------------------ Stack B:\n"); */
		/* ft_print_all_nodes_in_stack(st_b); */
	}
}

void ft_print_stack(t_stack *st)
{
    printf("id:\t%d\n", st->id);
    printf("nd_count:\t%d\n", st->nd_count);
    printf("first node:\t%p\n", st->first_nd);
    printf("last node:\t%p\n", st->last_nd);
}

void ft_print_all_stacks(t_stack *st_a, t_stack *st_b)
{
	printf("------------------ Stack A:\n");
	ft_print_stack(st_a);
	printf("------------------ Stack B:\n");
	ft_print_stack(st_b);
}

void ft_print_node(t_node *nd)
{
    printf("value:\t%d\n", nd->value);
    printf("index:\t%d\n", nd->index);
    printf("pos:\t%d\n", nd->pos);
    printf("t_pos:\t%d\n", nd->target_pos);
    printf("cost_a:\t%d\n", nd->cost_a);
    printf("cost_b:\t%d\n", nd->cost_b);
    printf("total_costs:\t%d\n", nd->total_costs);
    printf("prev:\t%p\n", nd->prev);
    printf("next:\t%p\n", nd->next);
}

void ft_print_all_nodes_in_stack(t_stack *st)
{
	t_node *nd;

	nd = st->first_nd;
	if (nd)
	{
		while (nd->next)
		{
			ft_print_node(nd);
			nd = nd->next;
		}
		ft_print_node(nd);
	}
}
