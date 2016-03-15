/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:34:57 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 11:37:04 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (n > 0)
	{
		if (*(unsigned char*)ptr1 != *(unsigned char*)ptr2)
			return (*(unsigned char*)ptr1 - *(unsigned char*)ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	return (0);
}
