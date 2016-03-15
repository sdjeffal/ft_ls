/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:08:32 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/15 12:08:58 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;
	int		nbr;
	char	*tmp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return ((char*)ft_strdup(s2));
	else if (s2 == NULL)
		return ((char*)ft_strdup(s1));
	nbr = ft_strlen(s1) + n;
	str = ft_strnew(nbr);
	tmp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && n-- > 0)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - tmp));
}
