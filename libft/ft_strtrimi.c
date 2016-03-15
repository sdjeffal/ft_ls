/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:26:22 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 10:28:56 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimi(char const *s, int c)
{
	char	*p_start;
	char	*p_end;
	size_t	start;
	size_t	end;
	size_t	l_s;

	p_start = (char *)s;
	l_s = ft_strlen(s);
	p_end = (char*)s + l_s - 1;
	start = 0;
	end = 0;
	if (l_s == 0)
		return (p_start);
	while (p_start[start] == c)
		start++;
	if (p_start[start] == '\0')
		return (ft_strnew(0));
	while (*p_end == c)
	{
		p_end--;
		end++;
	}
	return (ft_strsub(s, start, l_s - start - end));
}
