/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:47:36 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 11:54:03 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digit(int n)
{
	size_t		i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_convert(char *str, int number, int length)
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
		while (length >= 0)
		{
			str[length - 1] = '0' + number % 10;
			number = number / 10;
			length--;
		}
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			ln;

	ln = ft_count_digit(n);
	str = (n < 0) ? ft_strnew(ln + 1) : ft_strnew(ln);
	if (str == NULL)
		return (NULL);
	str = ft_convert(str, n, ln);
	return (str);
}
