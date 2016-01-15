/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 00:06:06 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/12/10 18:45:31 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char*)src;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < n && ptr[j] != '\0')
	{
		dest[i] = ptr[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
