/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chmod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:57:50 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/30 17:17:37 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	getchmodspec(t_file **f)
{
	if (f && (!(*f)->error || ((*f)->error && (*f)->error->errn != ENOENT)))
	{
		if ((*f)->chmod)
		{
			if ((*f)->stat.st_mode & S_ISUID)
				(*f)->chmod[2] = ((*f)->chmod[2] == 'x') ? 's' : 'S';
			if ((*f)->stat.st_mode & S_ISGID)
				(*f)->chmod[5] = ((*f)->chmod[5] == 'x') ? 's' : 'S';
			if ((*f)->stat.st_mode & S_ISVTX)
				(*f)->chmod[8] = ((*f)->chmod[8] == 'x') ? 't' : 'T';
		}
	}
}

void		getchmod(t_file **f)
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
		getchmodspec(f);
	}
}
