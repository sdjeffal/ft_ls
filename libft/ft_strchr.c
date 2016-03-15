/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:23:10 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 11:24:39 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p_s;

	p_s = (char *)s;
	while (*p_s != '\0')
	{
		if (*p_s == (char)c)
			return (p_s);
		p_s++;
	}
	if (*p_s == (char)c && *p_s == '\0')
		return (p_s);
	return (NULL);
}
