/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 19:30:23 by sdjeffal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/15 12:11:23 by sdjeffal         ###   ########.fr       */
=======
/*   Updated: 2016/03/11 19:34:08 by sdjeffal         ###   ########.fr       */
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"

void	ft_putlnbr(long n)
{
	long i;

	i = 0;
	if (n == LONG_MIN)
	{
		n = n / 10;
		i = 1;
	}
	if (n < 0)
	{
		ft_putchar('-');
<<<<<<< HEAD
		n = n * (-1);
=======
		n = n * - 1;
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
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
