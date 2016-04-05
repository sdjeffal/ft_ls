/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:24:51 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/05 15:48:56 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"
#include <unistd.h>

void	ls_core(t_opt op, t_file **lst)
{
	checkfiles(lst);
	if (!*lst)
		exit(EXIT_SUCCESS);
	if (!isopt(op))
	{
		ls_dir(lst, op);
		return ;
	}
}

DIR		*ft_opendir(t_file **lst)
{
	DIR	*dir;

	dir = opendir((*lst)->name);
	if(!dir)
		erropen(*lst);
	return (dir);
}

void	ls_dir(t_file **lst, t_opt op)
{
	t_file		*tmp;
	DIR			*dir;
	t_dirent	*dp;
	int			nbrf;
	int			nbrd;

	tmp = *lst;
	nbrf = printfile(tmp)
;	nbrd = getnbrdir(tmp);
	if (nbrf && nbrd)
		ft_putchar('\n');
	while (tmp)
	{
		if (isdir(tmp))
		{
			if (nbrf || nbrd > 1)
				ft_putendl(ft_strjoin(tmp->name, ":"));
			dir = ft_opendir(&tmp);
			if (tmp->err)
				write(2, &tmp->err, ft_strlen(tmp->err));
			while ((dp = readdir(dir)) > 0)
			{
				if (dp->d_name[0] != '.')
					insertascii(&tmp->sub, dp->d_name);
			}
			putlstfile(&tmp->sub);
			if (getnbrdir(tmp->next))
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

int	printfile(t_file *lst)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (isfile(tmp))
		{
			ft_putendl(tmp->name);
			i++;
		}
		tmp = tmp->next;
	}
	return (i);
}
