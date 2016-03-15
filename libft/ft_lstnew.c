/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:44:39 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/01/12 22:34:50 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (new_list)
	{
		if (content == NULL)
		{
			new_list->content = NULL;
			new_list->content_size = 0;
		}
		else
		{
			new_list->content = malloc(content_size);
			if (new_list->content == NULL)
				return (NULL);
			ft_memcpy(new_list->content, content, content_size);
			new_list->content_size = content_size;
		}
		new_list->next = NULL;
	}
	return (new_list);
}
