#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"
# include <limits.h>

typedef struct s_node
{
    int value;
    int index;
    int pos;
    int target_pos;
    int cost_a;
    int cost_b;
    struct s_node *next;;
    struct s_node *prev;
} t_node;

typedef struct
{
    int id;
	int nd_count;
    t_node *first_nd;
    t_node *last_nd;
} t_stack;

void ft_merge_sort(int arr[], int l, int r);

// ft_validate_arguments.c
int ft_arguments_valid(char **clear_argv);
int ft_count_values(char **clean_argv);
int ft_is_argument_a_number(char *clean_argv);
int ft_all_arguments_are_numbers(char **clean_argv);
long ft_atol(char *str);
int ft_all_arguments_are_integer(char **clean_argv);
int *ft_parse_argv_to_int_array(char **clean_argv);
int ft_dublicates_found(char **clean_argv);

// ft_stack_utils.c
void ft_init_stacks(t_stack *st_a, t_stack *st_b);

// ft_node_utils.c
void ft_init_nd(t_node *nd, int value, int index, int pos);
void ft_set_nd_value(t_node *nd, int value);
void ft_set_nd_index(t_node *nd, int index);
void ft_set_nd_pos(t_node *nd, int pos);
void ft_set_nd_target(t_node *nd, int target_pos);
void ft_set_nd_cost_a(t_node *nd, int cost_a);
void ft_set_nd_cost_b(t_node *nd, int cost_b);
void ft_set_nd_next(t_node *nd, t_node *next);
void ft_set_nd_prev(t_node *nd, t_node *prev);
int ft_get_nd_value(t_node *nd);
int ft_get_nd_index(t_node *nd);
int ft_get_nd_pos(t_node *nd);
int ft_get_nd_target_pos(t_node *nd);
int ft_get_nd_cost_a(t_node *nd);
int ft_get_nd_cost_b(t_node *nd);
t_node *ft_get_nd_next(t_node *nd);
t_node *ft_get_nd_prev(t_node *nd);
#endif
