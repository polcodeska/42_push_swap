/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:06:54 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:34:27 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	r;

	r = n;
	if (r < 0)
	{
		ft_putchar_fd('-', fd);
		r = -r;
	}
	if (r >= 10)
		ft_putnbr_fd(r / 10, fd);
	ft_putchar_fd(r % 10 + '0', fd);
}
