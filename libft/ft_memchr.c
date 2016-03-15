/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:05:39 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 12:06:51 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;

	p_s = (unsigned char*)s;
	while (n > 0)
	{
		if ((unsigned char)*p_s == (unsigned char)c)
			return ((void*)p_s);
		p_s++;
		n--;
	}
	return (NULL);
}
