/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:01:50 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/29 16:07:36 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_file		*newfile(char *name)
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

int	getnbrfile(t_file *lst)
{
	int i;
	t_file *tmp;

	i = 0;
	tmp = lst;
	if(tmp)
	{
		while(tmp)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
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

static void	freefile(t_file **file)
{
	if (*file)
	{
		if ((*file)->name)
			free((*file)->name);
		free(*file);
		*file = NULL;
	}
}

void	delfile(t_file **lst, char *name)
{
	t_file *tmp;
	t_file *cmp;

	cmp = NULL;
	tmp = *lst;
	while (tmp)
	{
		cmp = tmp;
		tmp = tmp->next;
		if (!ft_strcmp(cmp->name, name))
		{
			if(cmp->prev == NULL && cmp->next == NULL)
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

void	debuglst(t_file **begin)
{
	t_file	*tmp;

	tmp = *begin;
	while (tmp)
	{
		ft_putstr("name: ");
		ft_putendl(tmp->name);
		ft_putstr("type: ");
		ft_putchar(tmp->type);
		ft_putchar('\n');
		ft_putstr("err: ");
		ft_putstr(tmp->err);
		ft_putendl("");
		tmp = tmp->next;
	}
}

void	putlstfile(t_file **begin)
{
	t_file	*tmp;

	if (*begin)
	{
		tmp = *begin;
		while (tmp)
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
}
