/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:25:08 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/22 13:07:30 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

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
		return ('f');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else
		return ('u');
}

static void	gettime(t_file **f)
{
	time_t	now;
	char	*tmp;
	int		month;

	if ((now = time(NULL)) == -1)
		msgerr();
	month = (now - (*f)->stat.st_mtime) / 2629800;
	now = (now - (*f)->stat.st_mtime);
	if (f && (!(*f)->error || ((*f)->error && (*f)->error->errn != ENOENT)))
	{
		(*f)->atime = ft_strsub(ctime(&(*f)->stat.st_atime), 4, 12);
		if (month >= 6 || now < 0)
		{
			(*f)->mtime = ft_strsub(ctime(&(*f)->stat.st_mtime), 4, 7);
			tmp = ft_strsub(ctime(&(*f)->stat.st_mtime), 19, 5);
			(*f)->mtime = ft_strjoin((*f)->mtime, tmp);
			free(tmp);
		}
		else
			(*f)->mtime = ft_strsub(ctime(&(*f)->stat.st_mtime), 4, 12);
		(*f)->ctime = ft_strsub(ctime(&(*f)->stat.st_ctime), 4, 12);
	}
}

static void	getusrandgrp(t_file **f)
{
	int n;

	n = 0;
	if (f && (!(*f)->error || ((*f)->error && (*f)->error->errn != ENOENT)))
	{
		(*f)->gr = getgrgid((*f)->stat.st_gid);
		(*f)->pwd = getpwuid((*f)->stat.st_uid);
		if ((*f)->type == 'c' || (*f)->type == 'b')
		{
			n = (int)(((unsigned int)((*f)->stat.st_rdev) >> 24) & 0xFF);
			(*f)->major = ft_strjoin(ft_itoa(n), ",");
			n = (int)(((*f)->stat.st_rdev) & 0xFFFFFF);
			(*f)->minor = ft_strdup(ft_itoa(n));
		}
	}
}

static void	getchmod(t_file **f)
{
	if (f && (!(*f)->error || ((*f)->error && (*f)->error->errn != ENOENT)))
		(*f)->chmod = ft_strdup("---------");
	if ((*f)->chmod)
	{
		if ((*f)->stat.st_mode & S_IRUSR)
			(*f)->chmod[0] = 'r';
		if (S_IWUSR & (*f)->stat.st_mode)
			(*f)->chmod[1] = 'w';
		if (S_IXUSR & (*f)->stat.st_mode)
			(*f)->chmod[2] = 'x';
		if (S_IRGRP & (*f)->stat.st_mode)
			(*f)->chmod[3] = 'r';
		if (S_IWGRP & (*f)->stat.st_mode)
			(*f)->chmod[4] = 'w';
		if (S_IXGRP & (*f)->stat.st_mode)
			(*f)->chmod[5] = 'x';
		if (S_IROTH & (*f)->stat.st_mode)
			(*f)->chmod[6] = 'r';
		if (S_IWOTH & (*f)->stat.st_mode)
			(*f)->chmod[7] = 'w';
		if (S_IXOTH & (*f)->stat.st_mode)
			(*f)->chmod[8] = 'x';
	}
}

void		getlsttime(t_file **lst)
{
	t_file *tmp;

	tmp = *lst;
	while (tmp)
	{
		getchmod(&tmp);
		gettime(&tmp);
		getusrandgrp(&tmp);
		if (tmp->sub)
			getlsttime(&tmp->sub);
		tmp = tmp->next;
	}
}
