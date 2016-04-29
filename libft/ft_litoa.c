/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:47:36 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/29 12:13:51 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long int	ft_count_digit(long n)
{
	unsigned long int	i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char					*ft_convert(char *str, long number, long length)
{
	if (number < 0)
	{
		str[0] = '-';
		while (length > 0)
		{
			str[length] = '0' - number % 10;
			number = number / 10;
			length--;
		}
	}
	else
	{
		while (length > 0)
		{
			str[length - 1] = '0' + number % 10;
			number = number / 10;
			length--;
		}
	}
	return (str);
}

char						*ft_litoa(long n)
{
	char				*str;
	unsigned long int	ln;

	ln = ft_count_digit(n);
	str = (n < 0) ? ft_strnew(ln + 1) : ft_strnew(ln);
	if (str == NULL)
		return (NULL);
	str = ft_convert(str, n, ln);
	return (str);
}
