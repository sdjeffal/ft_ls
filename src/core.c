/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:24:51 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/27 08:31:53 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	readdirent(DIR *dir, t_file **f, t_opt op)
{
	t_dirent	*dp;
	t_file		*tmp;

	while ((dp = readdir(dir)) > 0)
	{
		if ((!op.a && dp->d_name[0] != '.') || op.a)
		{
			tmp = newfile(dp->d_name);
			tmp->path = ft_strdup((*f)->path);
			setpath(&tmp, tmp->name);
			insert(&(*f)->sub, tmp, op);
		}
	}
	if (dp < 0)
		msgerr();
	checkfiles(&(*f)->sub);
}

int			ls_core(t_opt op, t_file **lst)
{
	char	*tmp;
	int		ret1;
	int		ret2;

	ret1 = 0;
	ret2 = 0;
	if (*lst)
	{
		checkfiles(lst);
		ls_dir(lst, op);
		ret1 = printerror(*lst, ENOENT);
		if (!op.l)
			print_ls_dir(lst, op, &ret2);
		else
		{
			tmp = getlststat(lst);
			free(tmp);
			tmp = NULL;
			print_ls_dir_l(lst, op, &ret2);
		}
	}
	ret1 = (ret1 || ret2) ? 1 : 0;
	return (ret1);
}

void		ls_dir(t_file **lst, t_opt op)
{
	t_file	*tmp;
	DIR		*dir;

	tmp = *lst;
	while (tmp)
	{
		if (isdir(tmp) || (islnk(tmp) == 1 && op.l) || (islnk(tmp) && !op.l))
		{
			errno = 0;
			dir = opendir(tmp->path);
			if (dir)
			{
				readdirent(dir, &tmp, op);
				closedir(dir);
				if (op.rc)
					ls_dir_rec(&tmp->sub, op);
			}
		}
		tmp = tmp->next;
	}
}

void		ls_dir_rec(t_file **lst, t_opt op)
{
	t_file		*tmp;
	DIR			*dir;

	tmp = *lst;
	while (tmp)
	{
		if ((isdir(tmp)) && iscurandpar(tmp->name))
		{
			errno = 0;
			dir = opendir(tmp->path);
			if (dir)
			{
				readdirent(dir, &tmp, op);
				closedir(dir);
				if (op.rc)
					ls_dir_rec(&tmp->sub, op);
			}
		}
		tmp = tmp->next;
	}
}
