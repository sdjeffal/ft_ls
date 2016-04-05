/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:24:15 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/05 12:34:19 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	checkfiles(t_file **lst)
{
	DIR			*d;
	t_dirent	*dir;
	int			ret;
	t_file	*tmp;

	ret = 0;
	tmp = *lst;
	while (tmp)
	{
		if ((d = opendir(tmp->name)) == NULL)
		{
			if (erropen(tmp))
				delfile(lst, tmp->name);
		}
		else
		{
			ret = lstat(tmp->name, &tmp->stat);
			tmp->type = gettypefile(tmp->stat.st_mode);
			closedir(d);
		}
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
