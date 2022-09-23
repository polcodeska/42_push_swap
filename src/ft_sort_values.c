/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:12:03 by tmasur            #+#    #+#             */
/*   Updated: 2022/09/23 12:35:59 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_merge_sort(int arr[], int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (right - left) / 2 + left;
		ft_merge_sort(arr, left, mid);
		ft_merge_sort(arr, mid + 1, right);
		ft_merge_sort_algorithm(arr, left, mid, right);
	}
}

int	*ft_get_sub_arr(int arr[], int start, int len)
{
	int	i;
	int	j;
	int	*arr_sub;

	arr_sub = malloc (sizeof(*arr_sub) * len);
	i = 0;
	j = start;
	while (i < len)
	{
		arr_sub[i] = arr[j];
		i++;
		j++;
	}
	return (arr_sub);
}

void	ft_set_small_value(int arr[], int pos, int value)
{
	arr[pos] = value;
}

void	ft_merge_sort_algorithm(int arr[], int left, int mid, int right)
{
	int	i;
	int	j;
	int	k;
	int	*arr_l;
	int	*arr_r;

	arr_l = ft_get_sub_arr(arr, left, mid - left + 1);
	arr_r = ft_get_sub_arr(arr, mid + 1, right - mid);
	i = 0;
	j = 0;
	k = left;
	while (i < (mid - left + 1) && j < (right - mid))
	{
		if (arr_l[i] < arr_r[j])
			ft_set_small_value(arr, k++, arr_l[i++]);
		else
			ft_set_small_value(arr, k++, arr_r[j++]);
	}
	while (i < (mid - left + 1))
		ft_set_small_value(arr, k++, arr_l[i++]);
	while (j < (right - mid))
		ft_set_small_value(arr, k++, arr_r[j++]);
	free(arr_l);
	free(arr_r);
}
