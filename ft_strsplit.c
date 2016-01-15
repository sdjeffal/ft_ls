/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 22:10:27 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/12 22:19:19 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ret++;
		i++;
	}
	return (ret);
}

static size_t	ft_len_word(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;
	int		len;
	int		count_word;

	j = -1;
	if (s == NULL)
		return (NULL);
	count_word = ft_count_word(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (count_word + 1))) == NULL)
		return (NULL);
	while (++j < count_word)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = ft_len_word(s, c);
		if ((tab[j] = (char *)ft_memalloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		ft_strncpy(tab[j], s, len);
		while (*s != '\0' && *s != c)
			s++;
	}
	tab[j] = 0;
	return (tab);
}
