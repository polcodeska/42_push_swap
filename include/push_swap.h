#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"
# include <limits.h>

typedef struct s_node
{
    int value;
    int pos;
    int index;
    int target_pos;
    int cost_a;
    int cost_b;
    struct s_node *prev;
    struct s_node *next;;
} t_node;

typedef struct
{
    int id;
	int nd_count;
    t_node *first_nd;
    t_node *last_nd;
} t_stack;

void ft_merge_sort(int arr[], int l, int r);

// ft_validator_utils.c
int ft_arguments_valid(char **clear_argv);
int ft_count_values(char **clean_argv);
int ft_is_argument_a_number(char *clean_argv);
int ft_are_all_arguments_numbers(char **clean_argv);
long ft_atol(char *str);
int ft_are_all_arguments_integer(char **clean_argv);
int *ft_parse_argv_to_int_array(char **clean_argv);
int ft_are_dublicates_found(char **clean_argv);

// ft_stack_utils.c
void ft_init_stacks(t_stack *st_a, t_stack *st_b);
void ft_set_new_pos_for_all_nodes_on_stack(t_stack *st);
void ft_fill_stack_on_start(t_stack *st, char **clean_argv);
void ft_add_node_on_top(t_stack *st, t_node *nd);
void ft_add_node_on_bottom(t_stack *st, t_node *nd);
t_node *ft_pop_node_from_top(t_stack *st);
t_node *ft_pop_node_from_bottom(t_stack *st);
void ft_swap_first_nodes_on_stack(t_stack *st);
void ft_push_node_to_other_stack(t_stack *st_a, t_stack *st_b);
void ft_rotate_stack(t_stack *st);
void ft_rotate_both_stacks(t_stack *st_a, t_stack *st_b);
void ft_reverse_rotate_stack(t_stack *st);
void ft_reverse_rotate_both_stacks(t_stack *st_a, t_stack *st_b);
int ft_is_in_asc_order(int a, int b);
int ft_is_in_desc_order(int a, int b);
int ft_is_stack_sorted(t_stack *st, int (*ft_sort_order)(int, int));
void ft_run_algo_for_three_values(t_stack *st);

// ft_node_utils.c
void ft_init_nd(t_node *nd, int value, int pos);
#endif
