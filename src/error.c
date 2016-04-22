/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:44:17 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/12 17:42:30 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../inc/ft_ls.h"

void			msgerropt(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ft_ls [-alrRt] [file..]", 2);
	exit(EXIT_FAILURE);
}

void			msgerr(void)
{
	perror("ft_ls");
	exit(EXIT_FAILURE);
}

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
