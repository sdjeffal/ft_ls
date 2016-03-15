/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 08:44:30 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/12/17 14:20:05 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	new = NULL;
	if (lst != NULL)
		new = ft_lstnew(lst->content, lst->content_size);
	if (new == NULL)
		return (NULL);
	new = f(lst);
	if (lst->next != NULL)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
