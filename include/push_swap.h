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
	int total_costs;
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

// ft_sort_values.c
void ft_merge_sort(int arr[], int l, int r);

// main.c
void ft_push_swap(char **clean_argv, t_stack *st_a, t_stack *st_b);

// ft_validator_utils_1.c
int ft_arguments_valid(char **clear_argv);
int ft_count_values(char **clean_argv);
int *ft_parse_argv_to_int_array(char **clean_argv);
int ft_are_dublicates_found(char **clean_argv);

// ft_validator_utils_2.c
long ft_atol(char *str);
int ft_is_argument_a_number(char *clean_argv);
int ft_are_all_arguments_numbers(char **clean_argv);
int ft_are_all_arguments_integer(char **clean_argv);

// ft_stack_utils.c
void ft_init_nd(t_node *nd, int value, int pos);
void ft_init_stacks(t_stack *st_a, t_stack *st_b);
void ft_fill_stack_on_start(t_stack *st, char **clean_argv);

// ft_stack_operations_1.c
void ft_add_node_on_top(t_stack *st, t_node *nd);
void ft_add_node_on_bottom(t_stack *st, t_node *nd);
t_node *ft_pop_node_from_top(t_stack *st);
t_node *ft_pop_node_from_bottom(t_stack *st);
void ft_push_node_to_other_stack(t_stack *st_a, t_stack *st_b);

// ft_stack_operations_2.c
void ft_swap_first_nodes_on_stack(t_stack *st);
void ft_rotate_stack(t_stack *st, int with_output);
void ft_rotate_both_stacks(t_stack *st_a, t_stack *st_b);
void ft_reverse_rotate_stack(t_stack *st, int with_output);
void ft_reverse_rotate_both_stacks(t_stack *st_a, t_stack *st_b);

// ft_sort_push_swap.c
void ft_run_algo_for_three_values(t_stack *st);
void ft_run_algo_for_more_than_three_values(t_stack *st_a, t_stack *st_b);

//ft_stack_utils_2.c
void ft_set_total_costs(t_stack *st);
int ft_is_in_asc_order(int a, int b);
int ft_is_in_desc_order(int a, int b);
int ft_is_stack_sorted(t_stack *st, int (*ft_sort_order)(int, int));

// ft_stack_utils_3.c
void ft_set_new_pos_for_all_nodes_on_stack(t_stack *st);
void ft_set_indexes_for_all_nodes_on_stack(t_stack *st, int *int_arr);
void ft_set_target_pos_for_nodes(t_stack *st_a, t_stack *st_b);
void ft_set_costs(t_stack *st_a, t_stack *st_b);

// ft_stack_utils_4.c
int ft_get_pos_of_highest_index_in_stack(t_stack *st);
t_node *ft_get_cheapest_node(t_stack *st);
void ft_execute_operations(t_node *nd, t_stack *st_a, t_stack *st_b);
#endif
