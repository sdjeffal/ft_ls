/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 12:46:36 by mbonfill          #+#    #+#             */
/*   Updated: 2016/05/27 09:04:37 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1_s2;

	len_s1_s2 = 0;
	str = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return ((char*)s2);
	else if (s2 == NULL)
		return ((char*)s1);
	len_s1_s2 = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1_s2 + 1));
	if (str)
	{
		ft_strcpy(str, s1);
		ft_strcpy(str + ft_strlen(s1), s2);
	}
	return (str);
}
