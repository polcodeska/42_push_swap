#include "../include/push_swap.h"

void ft_push_swap(char **clean_argv, t_stack *st_a, t_stack *st_b);

#include <stdio.h>
static void ft_print_node(t_node *nd);
static void ft_print_all_nodes_in_stack(t_stack *st);
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
	ft_init_stacks(st_a, st_b);
	ft_print_all_stacks(st_a, st_b);
	if (ft_arguments_valid(clean_argv))
	{
		write(1, "Arguments valid\n", 16);
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
    printf("next:\t%p\n", nd->next);
    printf("prev:\t%p\n", nd->prev);
}

void ft_print_all_nodes_in_stack(t_stack *st)
{
	t_node *tmp_node;

	tmp_node = st->first_nd;
	if (tmp_node)
	{
		while (tmp_node->next)
		{
			ft_print_node(tmp_node);
			tmp_node = tmp_node->next;
		}
		ft_print_node(tmp_node);
	}
}
