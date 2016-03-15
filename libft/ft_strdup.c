/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 10:34:24 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/11/30 21:52:19 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp_s;
	int		i;
	int		srcl;

	i = 0;
	srcl = ft_strlen(s);
	cp_s = (char*)malloc(sizeof(char) * (srcl + 1));
	if (cp_s == NULL)
	{
		return (NULL);
	}
	while (i < srcl)
	{
		cp_s[i] = s[i];
		i++;
	}
	cp_s[i] = '\0';
	return (cp_s);
}
