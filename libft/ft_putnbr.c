/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 09:15:05 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/11 19:30:46 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	int i;

	i = 0;
	if (n == INT_MIN)
	{
		n = n / 10;
		i = 1;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = ft_abs(n);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n = 48 + n;
		write(1, &n, 1);
	}
	if (i)
		ft_putchar('8');
}
