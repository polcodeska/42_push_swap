#include "../include/push_swap.h"

int ft_arguments_valid(char **clean_argv)
{
	if (!ft_all_arguments_are_numbers(clean_argv) ||
			!ft_all_arguments_are_integer(clean_argv) ||
			ft_dublicates_found(clean_argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int ft_count_values(char **clean_argv)
{
    char **tmp_arr;

    tmp_arr = clean_argv;
    while (*clean_argv)
        clean_argv++;
    return (clean_argv - tmp_arr);
}

int ft_is_argument_a_number(char *clean_argv)
{
    if (*clean_argv == '-' || *clean_argv == '+')
        clean_argv++;
    while (*clean_argv)
    {
        if (!ft_isdigit(*clean_argv))
            return (0);
		clean_argv++;
    }
    return (1);
}

int ft_all_arguments_are_numbers(char **clean_argv)
{
	while (*clean_argv)
	{
		if (!ft_is_argument_a_number(*clean_argv))
			return (0);
		clean_argv++;
	}
	return (1);
}

long ft_atol(char *str)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		value = value * 10 + *(str++) - '0';
	return (sign * value);
}

int ft_all_arguments_are_integer(char **clean_argv)
{
	long arg;

	while (*clean_argv)
	{
		arg = ft_atol(*clean_argv);
		if (!(arg <= INT_MAX && arg >= INT_MIN))
			return (0);
		clean_argv++;
	}
	return (1);
}

int *ft_parse_argv_to_int_array(char **clean_argv)
{
	int *int_arr;
	int *tmp_arr;

	int_arr = malloc(sizeof *int_arr * ft_count_values(clean_argv));
	tmp_arr = int_arr;
	while (*clean_argv)
		*tmp_arr++ = ft_atoi(*clean_argv++);
	return (int_arr);
}

int ft_dublicates_found(char **clean_argv)
{
	int *int_arr;
	int value_count;
	int i;
	int j;

	int_arr = ft_parse_argv_to_int_array(clean_argv);
	value_count = ft_count_values(clean_argv);
    i = 0;
    while (i < value_count)
    {
        j = i + 1;
        while (j < value_count)
        {
            if (*(int_arr + i) == *(int_arr + j++))
			{
				free(int_arr);
                return (1);
			}
        }
        i++;
    }
	free(int_arr);
	return (0);
}
