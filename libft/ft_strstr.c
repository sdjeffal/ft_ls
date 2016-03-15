/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 00:56:20 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/12/09 13:33:16 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*p_haystack;
	char	*p_needle;
	char	*ret;
	int		res;

	p_haystack = (char*)haystack;
	p_needle = (char*)needle;
	if (*p_needle == '\0')
		return (p_haystack);
	ret = ft_strchr(p_haystack, (int)*p_needle);
	res = 0;
	while (ret != NULL && res == 0)
	{
		res = ft_strnequ(needle, ret, ft_strlen(needle));
		if (res == 0)
		{
			ret++;
			ret = ft_strchr(ret, *p_needle);
		}
	}
	return (ret);
}
