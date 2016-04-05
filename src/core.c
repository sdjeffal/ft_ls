/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:24:51 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/05 11:05:06 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ls_core(t_opt op, t_file **lst)
{
	checkfiles(lst);
	if (!*lst)
		exit(EXIT_SUCCESS);
	if (!isopt(op))
	{
		ls_dir(lst);
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

void	ls_dir(t_file **lst)
{
	t_file		*tmp;
	t_file		*new;
	DIR			*dir;
	t_dirent	*dp;

	tmp = *lst;
	new = NULL;
	while (tmp)
	{
		if(isdir(tmp))
		{
			ft_putendl(ft_strjoin(tmp->name, ":"));
			dir = ft_opendir(&tmp);
			while ((dp = readdir(dir)) > 0)
			{
				insertascii(&tmp->sub, dp->d_name);
			}
			putlstfile(&tmp->sub);
			ft_putchar('\n');
		}
		tmp = tmp->next;
	}


}
