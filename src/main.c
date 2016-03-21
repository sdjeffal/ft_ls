/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:05:16 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/21 15:39:39 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include "../inc/ft_ls.h"

void	ls_default(int ac, char **av)
{
	DIR *dir;
	t_file *begin;
	t_dirent *dp;

	begin = NULL;
	if (ac == 1 || (ac == 2 && !ft_strcmp(av[1], "--")))
	{
		if ((dir = opendir("./")) == NULL)
			msgerr();
		while ((dp = readdir(dir)) > 0)
			if (dp->d_name[0] != '.')
				insertascii(&begin, dp->d_name);
		putlstfile(&begin);
		closedir(dir);
		exit(EXIT_SUCCESS);
	}
}

void	checkfile(t_file *lst)
{
	DIR			*d;
	t_dirent	*dir;
	int ret;

	ret = 0;
	while (lst)
	{
		if ((d = opendir(lst->name)) == NULL)
			erropen(lst);
		else
		{
			lstat(lst->name, &lst->stat);
			lst->type = gettypefile(lst->stat.st_mode);
			closedir(d);
		}
		lst = lst->next;
	}
}

void	ls_core(t_opt op, t_file *lst)
{
	checkfile(lst);
}
/**
int	isfile()

int isdir()
**/
int	isopt(t_opt opt)
{
	if(opt.a && opt.l && opt.rv && opt.rc && opt.t)
		return (1);
	else return (0);
}

char	gettypefile(mode_t st_mode)
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

int	main(int argc, char **argv)
{
	t_opt option;
	t_file *begin;
	t_file *tmp;

	begin = NULL;
	ls_default(argc, argv);
	option = getopt(argc, argv);
	begin = getfile(argc, argv);
	tmp = begin;
	ls_core(option, begin);
	putlstfile(&begin);
	/**
	ft_putstr("-a");
	ft_putnendl(option.a);
	ft_putstr("-l");
	ft_putnendl(option.l);
	ft_putstr("-r");
	ft_putnendl(option.rv);
	ft_putstr("-R");
	ft_putnendl(option.rc);
	ft_putstr("-t");
	ft_putnendl(option.t);**/
	return (0);
}
