/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:01:50 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/27 15:20:11 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	initpad(t_file *new)
{
	int	i;

	i = 7;
	while (--i >= 0)
		new->pad[i] = 0;
	new->pad[5] = 4;
	new->pad[6] = 3;
}

static void	initfile(t_file *new)
{
	initpad(new);
	new->name = NULL;
	ft_bzero(new->link, PATH_MAX + 1);
	new->path = NULL;
	new->nlink = NULL;
	new->type[0] = ' ';
	new->type[1] = '\0';
	new->chmod = NULL;
	new->gr = NULL;
	new->tblk = NULL;
	new->pwd = NULL;
	new->size = NULL;
	new->major = NULL;
	new->minor = NULL;
	new->atime = NULL;
	new->mtime = NULL;
	new->ctime = NULL;
	new->error = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->sub = NULL;
}

t_file		*newfile(char *name)
{
	t_file	*new;

	if ((new = (t_file*)malloc(sizeof(t_file))) == NULL)
		msgerr();
	else
	{
		initfile(new);
		if (name != NULL)
		{
			new->name = ft_strdup(name);
			if (new->name == NULL)
				msgerr();
		}
	}
	return (new);
}

char		*getclass(char *name, char *type, t_stat st)
{
	char	sy[2];

	sy[1] = '\0';
	if (type[0] == 'p')
		sy[0] = '|';
	else if (type[0] == 'l')
		sy[0] = '@';
	else if (type[0] == 'd')
		sy[0] = '/';
	else if (type[0] == '-' && ((S_IXUSR & st.st_mode) ||
			(S_IXGRP & st.st_mode) || (S_IXOTH & st.st_mode)))
		sy[0] = '*';
	else
		return (name);
	return (name = ft_fstrjoin(name, sy, 1));
}
