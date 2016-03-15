/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:29:28 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 11:32:51 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	p_dest = dest;
	p_src = src;
	if (p_src <= p_dest)
	{
		p_dest += n - 1;
		p_src += n - 1;
		while (n--)
			*p_dest-- = *p_src--;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
