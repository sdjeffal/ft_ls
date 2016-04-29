/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 20:49:33 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/29 20:53:34 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static t_error	*mallocerror()
{
	t_error *e;

	if ((e = (t_error*)malloc(sizeof(t_error))) == NULL)
		msgerr();
	else
	{
		e->str = NULL;
		e->errn = 0;
	}
	return (e);
}

int				erropen(t_file *lst)
{
	if (errno == EACCES || errno == ENOENT)
	{
		lst->error = mallocerror();
		lst->error->str = ft_strjoin("ft_ls: ", lst->name);
		lst->error->str = ft_strjoin(lst->error->str, " ");
		lst->error->str = ft_strjoin(lst->error->str, strerror(errno));
		lst->error->errn = errno;
		if (errno == EACCES)
		{
			lstat(lst->path, &lst->stat);
			lst->type = gettypefile(lst->stat.st_mode);
		}
		return (1);
	}
	else if (errno == EMFILE || errno == ENFILE || errno == ENOMEM)
		msgerr();
	else if (errno == ENOTDIR)
	{
		lstat(lst->path, &lst->stat);
		lst->type = gettypefile(lst->stat.st_mode);
		return (1);
	}
	return (0);
}

int				errorexists(t_file *lst)
{
	if(lst)
	{
		while(lst)
		{
			if(lst->error)
				return (1);
			lst =lst->next;
		}
	}
	return (0);
}
