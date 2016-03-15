/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 22:28:03 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/12 23:03:12 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (n + 1));
	if (str)
	{
		while (i < n)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
