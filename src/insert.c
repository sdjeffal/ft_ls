/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:09:45 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/22 13:09:50 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		filepushback(t_file **begin, char *name)
{
	t_file *tmp;

	tmp = NULL;
	if (*begin == NULL)
		*begin = newfile(name);
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newfile(name);
		tmp->next->prev = tmp;
	}
}

void		insertascii(t_file **lst, char *s)
{
	t_file *tmp;
	t_file *cmp;
	t_file *new;

	tmp = NULL;
	cmp = *lst;
	new = newfile(s);
	while (cmp && ft_strcmp(cmp->name, s) < 0)
	{
		tmp = cmp;
		cmp = cmp->next;
	}
	new->next = cmp;
	if (cmp)
		new->next->prev = new;
	if (tmp)
	{
		tmp->next = new;
		new->prev = tmp;
	}
	else
		*lst = new;
}
