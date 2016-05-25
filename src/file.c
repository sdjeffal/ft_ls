/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:01:50 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/25 23:57:54 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	initfile(t_file **new)
{
	int	i;

	i = 7;
	while (--i > 0)
		(*new)->pad[i] = 0;
	(*new)->pad[5] = 4;
	(*new)->pad[6] = 3;
	(*new)->name = NULL;
	(*new)->link = NULL;
	(*new)->path = NULL;
	(*new)->type = ' ';
	(*new)->chmod = NULL;
	(*new)->gr = NULL;
	(*new)->tblk = NULL;
	(*new)->pwd = NULL;
	(*new)->size = NULL;
	(*new)->major = NULL;
	(*new)->minor = NULL;
	(*new)->atime = NULL;
	(*new)->mtime = NULL;
	(*new)->ctime = NULL;
	(*new)->error = NULL;
	(*new)->next = NULL;
	(*new)->prev = NULL;
	(*new)->sub = NULL;
}

t_file		*newfile(char *name)
{
	t_file	*new;

	if ((new = (t_file*)malloc(sizeof(t_file))) == NULL)
		msgerr();
	else
	{
		initfile(&new);
		if (name != NULL)
		{
			new->name = ft_strdup(name);
			if (new->name == NULL)
				msgerr();
		}
	}
	return (new);
}

void		freefile(t_file **file)
{
	if (*file)
	{
		free(*file);
		*file = NULL;
	}
}

void		delfile(t_file **lst, char *name)
{
	t_file	*tmp;
	t_file	*cmp;

	cmp = NULL;
	tmp = *lst;
	while (tmp)
	{
		cmp = tmp;
		tmp = tmp->next;
		if (!ft_strcmp(cmp->name, name))
		{
			if (cmp->prev == NULL && cmp->next == NULL)
			{
				freefile(&cmp);
				*lst = NULL;
			}
			else if (cmp->prev == NULL)
			{
				cmp->next->prev = NULL;
				*lst = cmp->next;
				freefile(&cmp);
			}
			else if (cmp->next == NULL)
			{
				cmp->prev->next = NULL;
				freefile(&cmp);
			}
			else
			{
				cmp->next->prev = cmp->prev;
				cmp->prev->next = cmp->next;
				freefile(&cmp);
			}
		}
	}
}
