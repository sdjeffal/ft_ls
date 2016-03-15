/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 06:14:35 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/12/09 13:40:04 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ret;
	unsigned char	*ptr;

	i = 0;
	ret = (unsigned char *)dest;
	ptr = (unsigned char *)src;
	while (i < n)
	{
		ret[i] = ptr[i];
		i++;
	}
	return (dest);
}
