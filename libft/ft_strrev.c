/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 10:34:39 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/08 10:36:27 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char *p_start;
	char *p_end;

	if (str)
	{
		p_start = str;
		p_end = &str[ft_strlen(str) - 1];
		while (p_start < p_end)
		{
			*p_start ^= *p_end;
			*p_end ^= *p_start;
			*p_start ^= *p_end;
			p_start++;
			p_end--;
		}
	}
	return (str);
}
