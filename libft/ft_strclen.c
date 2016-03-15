/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:09:40 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/15 12:10:16 by sdjeffal         ###   ########.fr       */
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
