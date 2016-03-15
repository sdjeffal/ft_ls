/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:31:32 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/12/21 18:44:05 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*p_s;
	char			*ret;
	unsigned int	i;

	p_s = (char *)s + start;
	ret = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (ret == NULL || s == NULL)
		return (NULL);
	while (i < len && p_s != '\0')
	{
		ret[i] = p_s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
