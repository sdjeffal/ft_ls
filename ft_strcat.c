/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 12:46:36 by mbonfill          #+#    #+#             */
/*   Updated: 2015/12/09 13:16:51 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char*)src;
	while (dest[i] != '\0')
		i++;
	while (ptr[j] != '\0')
	{
		dest[i] = ptr[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
