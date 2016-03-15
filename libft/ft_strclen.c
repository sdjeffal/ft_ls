/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 13:40:19 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/11/30 21:52:58 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strclen(const char *s, int c)
{
	size_t i;

	i = 0;
	if (!s)
	 return (0);
	while (s[i] != c)
		i++;
	return (i);
}
