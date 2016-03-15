/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 10:43:20 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 10:44:58 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*ret;

	if (*s2 == '\0')
		return ((char*)s1);
	ret = ft_strstr(s1, s2);
	if (ret == NULL || &ret[ft_strlen(s2) - 1] > &s1[n - 1])
		return (NULL);
	return (ret);
}
