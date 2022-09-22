#include "../include/push_swap.h"

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

int ft_are_all_arguments_numbers(char **clean_argv)
{
	while (*clean_argv)
	{
		if (!ft_is_argument_a_number(*clean_argv))
			return (0);
		clean_argv++;
	}
	return (1);
}

int ft_are_all_arguments_integer(char **clean_argv)
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
