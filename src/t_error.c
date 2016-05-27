/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 20:49:33 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/27 09:51:56 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_error	*mallocerror(void)
{
	t_error	*e;

	if ((e = (t_error*)malloc(sizeof(t_error))) == NULL)
		msgerr();
	else
	{
		e->str = NULL;
		e->errn = 0;
	}
	return (e);
}

void	adderror(t_file *f)
{
	f->error = mallocerror();
	f->error->str = ft_strjoin("ft_ls: ", f->name);
	f->error->str = ft_fstrjoin(f->error->str, ": ", 1);
	f->error->str = ft_fstrjoin(f->error->str, strerror(errno), 1);
	f->error->errn = errno;
}

void	delerror(t_file *f)
{
	if (f && f->error)
	{
		free(f->error->str);
		f->error->str = NULL;
		free(f->error);
		f->error = NULL;
	}
}

int		erropen(t_file *lst)
{
	if (errno == EACCES || errno == ENOENT)
	{
		adderror(lst);
		if (errno == EACCES)
		{
			lstat(lst->path, &lst->stat);
			lst->type[0] = gettypefile(lst->stat.st_mode);
		}
		return (1);
	}
	else if (errno == EMFILE || errno == ENFILE || errno == ENOMEM)
		msgerr();
	else if (errno == ENOTDIR)
	{
		lstat(lst->path, &lst->stat);
		lst->type[0] = gettypefile(lst->stat.st_mode);
		return (1);
	}
	return (0);
}

int		errorexists(t_file *lst, t_opt op)
{
	t_file	*tmp;

	tmp = (op.rv) ? getlast(&lst) : lst;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->error && tmp->error->str)
				return (1);
			tmp = (op.rv) ? tmp->prev : tmp->next;
		}
	}
	return (0);
}
