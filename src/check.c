/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:24:15 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/20 18:34:30 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		checkdir(t_file **lst, DIR *dir)
{
	int	ret;

	ret = 0;
	ret = lstat((*lst)->path, &(*lst)->stat);
	if (!dir && ret == -1)
	{
		if (!erropen(*lst))
			return (0);
	}
	else
	{
		if (ret == -1)
		{
			if (errno == EBADF)
				msgerr();
		}
		else
		{
			if (errno == EACCES)
				adderror((*lst));
			(*lst)->type = gettypefile((*lst)->stat.st_mode);
		}
	}
	return (1);
}

void	checkfiles(t_file **lst)
{
	DIR		*d;
	t_file	*tmp;

	tmp = *lst;
	while (tmp)
	{
		errno = 0;
		d = opendir(tmp->path);
		checkdir(&tmp, d);
		if (d)
			closedir(d);
		tmp = tmp->next;
	}
}

int		isfile(t_file *f)
{
	if (f)
	{
		if (f->type == '-' || f->type == 'c' ||
			f->type == 'b' || f->type == 's' || f->type == 'p')
			return (TRUE);
	}
	return (FALSE);
}

int		isdir(t_file *f)
{
	if (f)
	{
		if (f->type == 'd')
			return (TRUE);
	}
	return (FALSE);
}

int		islnk(t_file *f)
{
	if (f)
	{
		if (f->type == 'l' && f->name)
		{
			if (f->name[ft_strlen(f->name) - 1] == '/')
				return (1);
			else
				return (-1);
		}
	}
	return (FALSE);
}
