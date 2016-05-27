/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 10:24:35 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/27 10:41:34 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	freegrandusr(struct group *gr, struct passwd *pwd)
{
	int i;
	int b;

	i = 0;
	if (gr)
	{
		while (gr->gr_name[i] && (b = ft_isdigit(gr->gr_name[i])))
			i++;
		if (b)
		{
			free(gr->gr_name);
			free(gr);
		}
	}
	i = 0;
	if (pwd)
	{
		while (pwd->pw_name[i] && (b = ft_isdigit(pwd->pw_name[i])))
			i++;
		if (b)
		{
			free(pwd->pw_name);
			free(pwd);
		}
	}
}

static void	freetime(char *ctime, char *atime, char *mtime)
{
	if (ctime)
		free(ctime);
	if (atime)
		free(atime);
	if (mtime)
		free(mtime);
}

void		freefile(t_file *file)
{
	if (file)
	{
		if (file->name)
			free(file->name);
		if (file->path)
			free(file->path);
		if (file->nlink)
			free(file->nlink);
		if (file->chmod)
			free(file->chmod);
		if (file->size)
			free(file->size);
		if (file->tblk)
			free(file->tblk);
		if (file->major)
			free(file->major);
		if (file->minor)
			free(file->minor);
		freegrandusr(file->gr, file->pwd);
		freetime(file->ctime, file->atime, file->mtime);
		delerror(file);
	}
}
