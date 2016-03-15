/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 22:31:57 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 08:51:22 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int i;

	i = 0;
	if (n == -2147483648)
	{
		n = n / 10;
		i = 1;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = ft_abs(n);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		n = 48 + n;
		ft_putchar_fd(n, fd);
	}
	if (i)
		ft_putchar_fd('8', fd);
}
