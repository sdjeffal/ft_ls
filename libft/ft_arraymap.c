/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:41:40 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 11:43:43 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraymap(void *tab, size_t nb_elt, size_t s, void (*f)(const void*))
{
	size_t	i;
	char	*data;

	data = tab;
	i = 0;
	if (tab && nb_elt && s && f)
	{
		while (i < nb_elt)
		{
			f(data + i * s);
			i++;
		}
	}
}
