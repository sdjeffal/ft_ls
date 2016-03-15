/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:49:43 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/12/17 09:54:28 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;
	unsigned int		i;

	i = 0;
	p_dst = dst;
	p_src = src;
	if (n != 0)
	{
		while (i < n)
		{
			if (p_src[i] == (unsigned char)c)
			{
				p_dst[i] = p_src[i];
				return ((void *)&p_dst[i + 1]);
			}
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (NULL);
}
