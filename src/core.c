/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:24:51 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/29 20:44:07 by sdjeffal         ###   ########.fr       */
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

void	ls_core(t_opt op, t_file **lst)
{
	if (*lst)
	{
		checkfiles(lst);
		ls_dir(lst, op);
		if (!op.l)
			print_ls_dir(lst, op);
		else
			getlststat(lst);
	}
	exit(EXIT_SUCCESS);
}

void	ls_dir(t_file **lst, t_opt op)
{
	t_file		*tmp;
	DIR			*dir;
	t_dirent	*dp;

	tmp = *lst;
	while (tmp)
	{
		if (isdir(tmp) || islnk(tmp))
		{
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

void	ls_dir_rec(t_file **lst, t_opt op)
{
	t_file		*tmp;
	DIR			*dir;
	t_dirent	*dp;

	tmp = *lst;
	while (tmp)
	{
		if ((isdir(tmp)) && ft_strcmp(tmp->name, ".") 
		&& ft_strcmp(tmp->name, "..") && ft_strcmp(tmp->name, "./") 
		&& ft_strcmp(tmp->name, "../"))
		{
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
