/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:24:15 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/12 17:28:06 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int	checkdir(t_file **lst, DIR *dir, char *path)
{
	int ret;

	if(!dir)
	{
		if (!erropen(*lst))
			return (0);
	}
	else
	{
		ret = lstat((*lst)->path, &(*lst)->stat);
		if (ret == -1)
		{
			if (errno == EBADF)
				msgerr();
		}
		else
			(*lst)->type = gettypefile((*lst)->stat.st_mode);
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
		d = opendir(tmp->path);
		checkdir(&tmp, d, tmp->path);
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
			f->type == 'b' || f->type == 's')
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
		if (f->type == 'l')
			return (TRUE);
	}
	return (FALSE);
}

int		isopt(t_opt opt)
{
	if (opt.a || opt.l || opt.rv || opt.rc || opt.t)
		return (TRUE);
	else
		return (FALSE);
}
