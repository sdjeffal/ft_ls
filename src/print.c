/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:09:19 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/29 12:12:28 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	putlstfile(t_file **begin)
{
	t_file	*tmp;

	if (*begin)
	{
		tmp = *begin;
		while (tmp)
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
}

int		printfile(t_file *lst, int boolean)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (isfile(tmp))
		{	
			if(!boolean)
				ft_putendl(tmp->name);
			i++;
		}
		tmp = tmp->next;
	}
	return (i);
}

void	printerror(t_file *f, int errn)
{
	t_file *tmp;

	tmp = f;
	while (tmp)
	{
		if (tmp->error && tmp->error->errn == errn)
			ft_putendl(tmp->error->str);
		tmp = tmp->next;
	}
}

void	print_ls_dir(t_file **lst, t_opt op)
{
	t_file		*tmp;
	int			nbrf;
	int			nbrd;
	int			nbrerr;
	static int		i;

	tmp = *lst;
	printerror(tmp, ENOENT);
	nbrf = printfile(tmp, i);
	i++;
	nbrd = getnbrdir(tmp);
	nbrerr = errorexists(tmp);
	if (nbrf && nbrd)
		ft_putchar('\n');
	while (tmp)
	{
		if (isdir(tmp) || islnk(tmp))
		{
			if (nbrf || nbrd > 1 || nbrerr > 1)
				ft_putendl(ft_strjoin(tmp->path, ":"));
			if (tmp->error && tmp->error->errn == EACCES)
				ft_putendl(tmp->error->str);
			if(tmp->sub)
			{
				putlstfile(&tmp->sub);
				if(op.rc)
					print_ls_dir(&tmp->sub, op);
			}
			if (getnbrdir(tmp->next) || errorexists(tmp->next))
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

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
