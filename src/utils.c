/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:08:56 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/26 17:22:05 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		getnbrfile(t_file *lst)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			if (isfile(tmp))
				i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int		getnbrdir(t_file *lst, t_opt op, int t)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			if (isdir(tmp) || islnk(tmp) == 1 || (!op.l && islnk(tmp)))
			{
				if ((tmp->type[0] == 'l' && tmp->sub != NULL) ||
					(tmp->type[0] != 'l' && (iscurandpar(tmp->name) ||
					(!iscurandpar(tmp->path) && t == 1))))
					i++;
			}
			tmp = (op.rv) ? tmp->prev : tmp->next;
		}
	}
	return (i);
}

int		getlenghtlst(t_file *lst)
{
	int		i;
	t_file	*tmp;

	i = 0;
	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

void	setpath(t_file **lst, char *path)
{
	int		last;
	char	*tmp;

	tmp = (*lst)->path;
	if ((*lst)->path)
	{
		last = ft_strlen((*lst)->path) - 1;
		if ((*lst)->path[last] != '/')
		{
			(*lst)->path = ft_strjoin((*lst)->path, "/");
			free(tmp);
			tmp = (*lst)->path;
		}
		(*lst)->path = ft_strjoin((*lst)->path, path);
		if (tmp)
			free(tmp);
	}
	else
		(*lst)->path = ft_strdup(path);
}

int		iscurandpar(char *s)
{
	int	i;

	i = 0;
	if (ft_strcmp(s, ".") && ft_strcmp(s, "..")
			&&
		ft_strcmp(s, "./") && ft_strcmp(s, "../"))
		return (1);
	else
		return (0);
}
