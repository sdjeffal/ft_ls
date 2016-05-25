/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:25:08 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/25 23:52:28 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"
#include <limits.h>
#include <unistd.h>

char		gettypefile(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		return ('-');
	else if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISLNK(st_mode))
		return ('l');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISFIFO(st_mode))
		return ('p');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else
		return ('u');
}

static void	gettime(t_file **f, int *pad)
{
	time_t	now;
	char	*tmp;
	int		month;
	int		len;

	if ((now = time(NULL)) == -1)
		msgerr();
	month = (now - (*f)->stat.st_mtime) / 2629800;
	now = (now - (*f)->stat.st_mtime);
	(*f)->atime = ft_strsub(ctime(&(*f)->stat.st_atime), 4, 12);
	if (month >= 6 || now < 0)
	{
		(*f)->mtime = ft_strsub(ctime(&(*f)->stat.st_mtime), 4, 7);
		tmp = ft_strsub(ctime(&(*f)->stat.st_mtime), 19, 5);
		(*f)->mtime = ft_fstrjoin((*f)->mtime, tmp, 0);
	}
	else
		(*f)->mtime = ft_strsub(ctime(&(*f)->stat.st_mtime), 4, 12);
	(*f)->mtime = ft_fstrjoin((*f)->mtime, " ", 1);
	(*f)->ctime = ft_strsub(ctime(&(*f)->stat.st_ctime), 4, 12);
	if (pad[4] < (len = ft_strlen((*f)->mtime)))
		pad[4] = len;
}

static void	getusrandgrp(t_file **f, int *pad)
{
	int	len;

	(*f)->gr = getgrgid((*f)->stat.st_gid);
	(*f)->pwd = getpwuid((*f)->stat.st_uid);
	if ((*f)->pwd == NULL)
	{
		if (((*f)->pwd = (struct passwd*)malloc(sizeof(struct passwd))))
			(*f)->pwd->pw_name = ft_itoa((*f)->stat.st_uid);
		else
			msgerr();
	}
	if ((*f)->gr == NULL)
	{
		if (((*f)->gr = (struct group*)malloc(sizeof(struct group))))
			(*f)->gr->gr_name = ft_itoa((*f)->stat.st_gid);
		else
			msgerr();
	}
	if (pad[1] < (len = ft_strlen((*f)->pwd->pw_name)))
		pad[1] = len;
	if (pad[2] < (len = ft_strlen((*f)->gr->gr_name)))
		pad[2] = len;
}

static void	getlink(t_file **f)
{
	char	*buf;
	ssize_t ret;

	buf = ft_strnew(PATH_MAX);
	ret = readlink((*f)->path, buf, PATH_MAX);
	if (ret == -1)
	{
		ft_putendl("------------error----------");
	}
	buf[ret + 1] = '\0';
	(*f)->link = buf;
}

char		*getlststat(t_file **lst)
{
	t_file		*tmp;
	char		*tsize;
	blkcnt_t	total;

	total = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp && (!tmp->error || (tmp->error && tmp->error->errn != ENOENT)))
		{
			total = total + tmp->stat.st_blocks;
			getchmod(&tmp);
			getnlink(&tmp, (*lst)->pad);
			gettime(&tmp, (*lst)->pad);
			getusrandgrp(&tmp, (*lst)->pad);
			getsize(&tmp, (*lst)->pad);
			if (islnk(tmp))
				getlink(&tmp);
			if (tmp->sub != NULL)
				tmp->tblk = getlststat(&tmp->sub);
		}
		tmp = tmp->next;
	}
	tsize = ft_fstrjoin("total ", ft_itoa(total), 2);
	return (tsize);
}
