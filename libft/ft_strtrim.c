/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 10:30:03 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 10:32:47 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*p_start;
	char	*p_end;
	size_t	start;
	size_t	end;
	size_t	l_s;

	if (s == NULL)
		return (NULL);
	p_start = (char *)s;
	l_s = ft_strlen(s);
	p_end = (char*)s + l_s - 1;
	start = 0;
	end = 0;
	while (ft_isspace(p_start[start]))
		start++;
	if (p_start[start] == '\0')
		return (ft_strnew(0));
	while (ft_isspace(*p_end))
	{
		p_end--;
		end++;
	}
	return (ft_strsub(s, start, l_s - start - end));
}
