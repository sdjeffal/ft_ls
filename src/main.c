/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:18:46 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/25 22:06:08 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"
/**
void	ls_default(int ac, char **av)
{
	t_dirent	*dp;
	t_file		*begin;
	DIR			*dir;

	begin = NULL;
	if (ac == 1 || (ac == 2 && !ft_strcmp(av[1], "--")))
	{
		if ((dir = opendir("./")) == NULL)
			msgerr();
		while ((dp = readdir(dir)) > 0)
		{
			if (dp->d_name[0] != '.')
				insertascii(&begin, newfile(dp->d_name));
		}
		putlstfile(&begin);
		closedir(dir);
		exit(EXIT_SUCCESS);
	}
}
**/
void	debuglst(t_file **begin)
{
	t_file	*tmp;

	tmp = *begin;
	while (tmp)
	{
		ft_putstr("name: ");
		ft_putendl(tmp->name);
		ft_putstr("type: ");
		ft_putchar(tmp->type);
		ft_putchar('\n');
		ft_putstr("path: ");
		if (tmp->path)
			ft_putstr(tmp->path);
		ft_putchar('\n');
		ft_putstr("chmod: ");
		if (tmp->chmod)
			ft_putendl(tmp->chmod);
		ft_putstr("nlink: ");
		if (tmp->stat.st_nlink)
			ft_putnendl(tmp->stat.st_nlink);
		ft_putstr("size: ");
		if (tmp->stat.st_size)
			ft_putnendl(tmp->stat.st_size);
		ft_putstr("user: ");
		if (tmp->pwd)
			ft_putendl(tmp->pwd->pw_name);
		ft_putstr("groupe: ");
		if (tmp->gr)
			ft_putendl(tmp->gr->gr_name);
		ft_putstr("atime: ");
		if (tmp->atime)
			ft_putendl(tmp->atime);
		ft_putstr("mtime: ");
		if (tmp->mtime)
			ft_putendl(tmp->mtime);
		ft_putstr("ctime: ");
		if (tmp->ctime)
			ft_putendl(tmp->ctime);
		ft_putstr("major: ");
		if (tmp->type == 'c' || tmp->type == 'b')
		{
			if (tmp->major)
				ft_putendl(tmp->major);
			ft_putstr("minor: ");
			if (tmp->minor)
				ft_putendl(tmp->minor);
		}
		ft_putstr("error->str: ");
		if (tmp->error)
			ft_putstr(tmp->error->str);
		ft_putendl("\n");
		tmp = tmp->next;
	}
	tmp = *begin;
	while (tmp)
	{	
		if(tmp->type == 'd')
		{
		ft_putendl(" -------------------------------------------------------");
		ft_putstr("|	name: ");
		ft_putendl(tmp->name);
		ft_putendl(" -------------------------------------------------------");
		ft_putstr("total:");
		ft_putendl(tmp->tblk);
		if(tmp->sub)
			debuglst(&tmp->sub);
		}
		tmp = tmp->next;
	}
}

t_file *getlast(t_file **begin)
{
	t_file *end;
	t_file *tmp;

	tmp = (*begin);
	if ((*begin))
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	end = tmp;
	return (end);
}

void freelst(t_file **lst)
{
	t_file *tmp;

	while ((*lst))
	{
		if ((*lst)->sub)
			freelst(&(*lst)->sub);
		tmp = (*lst);
		(*lst) = (*lst)->next;
		freefile(&tmp);
	}
}

int		main(int argc, char **argv)
{
	t_file	*begin;
	t_opt	option;
	int		ret;

	begin = NULL;
	ret = 0;
	option = ft_getopt(argc, argv);
	getfile(&begin, argc, argv, option);
	ls_core(option, &begin);
	freelst(&begin);
	exit(ret);
	return (0);
}
