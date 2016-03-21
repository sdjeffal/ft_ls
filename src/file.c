/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:01:50 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/18 16:23:23 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_file	*newfile(char *name)
{
	t_file *new;

	if ((new = (t_file*)malloc(sizeof(t_file))) == NULL)
		msgerr();
	else
	{
		if (name == NULL)
			new->name = NULL;
		else
		{
			new->name = ft_strdup(name);
			if (new->name == NULL)
				msgerr();
		}
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

void	filepushback(t_file **begin, char *name)
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

void	insertascii(t_file **lst, char *s)
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
	if(cmp)
		new->next->prev = new;
	if (tmp)
	{
		tmp->next = new;
		new->prev = tmp;
	}
	else
		*lst = new;
}

void	putlstfile(t_file **begin)
{
	t_file	*tmp;
	t_file	*end;

	tmp = *begin;
	while (tmp)
	{
		ft_putstr("name: ");
		ft_putendl(tmp->name);
		ft_putstr("type: ");
		ft_putchar(tmp->type);
		ft_putchar('\n');
		ft_putstr("err: ");
		ft_putendl(tmp->err);
		tmp = tmp->next;
	}
}
