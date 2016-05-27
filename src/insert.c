/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:09:45 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/26 15:12:59 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		filepushback(t_file **begin, t_file *new)
{
	t_file *tmp;

	tmp = NULL;
	if ((*begin) == NULL)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void		insertascii(t_file **lst, t_file *new)
{
	t_file *tmp;
	t_file *cmp;

	tmp = NULL;
	cmp = *lst;
	while (cmp && ft_strcmp(cmp->name, new->name) < 0)
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

static int	timecmp(struct timespec a, struct timespec b)
{
	if (a.tv_sec > b.tv_sec)
		return (1);
	else if (a.tv_sec < b.tv_sec)
		return (-1);
	else if (a.tv_sec == b.tv_sec)
	{
		if (a.tv_nsec > b.tv_nsec)
			return (1);
		else if (a.tv_nsec < b.tv_nsec)
			return (-1);
	}
	return (0);
}

void		insertmtime(t_file **lst, t_file *f)
{
	t_file	*tmp;
	t_file	*cmp;
	int		ret;

	tmp = NULL;
	cmp = *lst;
	ret = lstat(f->path, &f->stat);
	while (cmp && timecmp(f->stat.st_mtimespec, cmp->stat.st_mtimespec) <= 0)
	{
		if (timecmp(f->stat.st_mtimespec, cmp->stat.st_mtimespec) == 0)
			if (ft_strcmp(cmp->name, f->name) > 0)
				break ;
		tmp = cmp;
		cmp = cmp->next;
	}
	f->next = cmp;
	if (cmp)
		f->next->prev = f;
	if (tmp)
	{
		tmp->next = f;
		f->prev = tmp;
	}
	else
		*lst = f;
}

void		insert(t_file **lst, t_file *f, t_opt op)
{
	if (op.t)
		insertmtime(lst, f);
	else if (op.f)
		filepushback(lst, f);
	else
		insertascii(lst, f);
}
