/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 23:39:01 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/12/10 18:18:17 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d;
	size_t s;

	d = 0;
	while (dst[d] != '\0' && d < size)
		d++;
	s = d;
	while (src[d - s] != '\0' && d < size - 1)
	{
		dst[d] = src[d - s];
		d++;
	}
	if (s < size)
		dst[d] = '\0';
	return (s + ft_strlen(src));
}
