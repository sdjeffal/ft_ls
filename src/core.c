/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:24:51 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/12 17:42:28 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	setlstpath(t_file **lst, char *path)
{
	t_file	*tmp;
	DIR		*d;

	tmp = *lst;
	while (tmp)
	{
		tmp->path = ft_strdup(path);
		setpath(&tmp, tmp->name);
		tmp = tmp->next;
	}
}

static void	readdirent(DIR *dir, t_file **f, t_opt op)
{
	t_dirent *dp;

	while ((dp = readdir(dir)) > 0)
	{
		if ((!op.a && dp->d_name[0] != '.') || op.a)
			insertascii(&(*f)->sub, dp->d_name);
	}
	if (dp < 0)
		msgerr();
	setlstpath(&(*f)->sub, (*f)->path);
	checkfiles(&(*f)->sub);
}

void	ls_core(t_opt op, t_file **lst)
{
	if (*lst)
	{
		checkfiles(lst);
		ls_dir(lst, op);
		getlsttime(lst);
		debuglst(lst);
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

static void	print_ls_dir(t_file **lst, t_opt op)
{
	t_file		*tmp;
	DIR			*dir;
	t_dirent	*dp;
	int			nbrf;
	int			nbrd;
	int			nbrerr;

	tmp = *lst;
	printerror(tmp, ENOENT);
	nbrf = printfile(tmp);
	nbrd = getnbrdir(tmp);
	nbrerr = errorexists(tmp);
	if (nbrf && nbrd)
		ft_putchar('\n');
	while (tmp)
	{
		if (isdir(tmp) || islnk(tmp))
		{
			if (nbrf || nbrd > 1 || nbrerr > 1)
				ft_putendl(ft_strjoin(tmp->name, ":"));
			if (tmp->error && tmp->error->errn == EACCES)
				ft_putendl(tmp->error->str);
			dir = opendir(tmp->path);
			if(dir)
			{
				while ((dp = readdir(dir)) > 0)
				{
						insertascii(&tmp->sub, dp->d_name);
				}
				closedir(dir);
				setlstpath(&tmp->sub, tmp->path);
				checkfiles(&tmp->sub);
				ft_putendl(tmp->sub->path);
				if (op.rc)
					ls_dir_rec(&tmp->sub, op);
				putlstfile(&tmp->sub);
			}
			if (getnbrdir(tmp->next) || errorexists(tmp->next))
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

