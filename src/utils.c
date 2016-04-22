/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:08:56 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/22 13:08:58 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int	getnbrfile(t_file *lst)
{
	t_file *tmp;
	int i;

	i = 0;
	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			if(isfile(tmp))
				i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	getnbrdir(t_file *lst)
{
	t_file *tmp;
	int i;

	i = 0;
	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			if(isdir(tmp) || islnk(tmp))
				i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	getlenghtlst(t_file *lst)
{
	int i;
	t_file *tmp;

	i = 0;
	tmp = lst;
	if(tmp)
	{
		while(tmp)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

void	setpath(t_file **lst, char *path)
{
	int last;

	if ((*lst)->path)
	{
		last = ft_strlen((*lst)->path) - 1;
		if ((*lst)->path[last] != '/')
			(*lst)->path = ft_strjoin((*lst)->path, "/");
		(*lst)->path =  ft_strjoin((*lst)->path, path);
	}
	else
		(*lst)->path = ft_strdup(path);
}

