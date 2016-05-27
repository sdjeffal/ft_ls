/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 19:57:27 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/27 15:05:10 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static char	*do_pad(char *s, int max)
{
	char	*ret;
	int		l;
	int		i;

	l = max + 2 - ft_strlen(s);
	i = -1;
	ret = ft_strnew(l);
	while (++i < l)
		ret[i] = ' ';
	return (ret);
}

char		*display(t_file *f, int *pad)
{
	char	*s;

	s = ft_strjoin(f->type, f->chmod);
	s = ft_fstrjoin(s, do_pad(f->nlink, pad[0]), 0);
	s = ft_fstrjoin(s, f->nlink, 1);
	s = ft_fstrjoin(s, " ", 1);
	if (f->pwd == NULL)
		s = ft_fstrjoin(s, ft_itoa(f->stat.st_uid), 0);
	else
		s = ft_fstrjoin(s, f->pwd->pw_name, 1);
	s = ft_fstrjoin(s, do_pad(f->pwd->pw_name, pad[1]), 0);
	if (f->gr == NULL)
		s = ft_fstrjoin(s, ft_itoa(f->stat.st_gid), 0);
	else
		s = ft_fstrjoin(s, f->gr->gr_name, 1);
	s = ft_fstrjoin(s, do_pad(f->gr->gr_name, pad[2] - 2), 0);
	return (s);
}

char		*displayfile(t_file *f, int *pad)
{
	char	*s;

	s = display(f, pad);
	s = ft_fstrjoin(s, do_pad(f->size, pad[3]), 0);
	s = ft_fstrjoin(s, f->size, 1);
	s = ft_fstrjoin(s, " ", 1);
	s = ft_fstrjoin(s, f->mtime, 1);
	s = ft_fstrjoin(s, f->name, 1);
	return (s);
}

char		*displaylnk(t_file *f, int *pad)
{
	char	*s;
	char	*tmp;

	tmp = NULL;
	s = NULL;
	s = displayfile(f, pad);
	tmp = ft_strjoin(" -> ", f->link);
	s = ft_fstrjoin(s, tmp, 0);
	return (s);
}

char		*displaydevice(t_file *f, int *pad)
{
	char	*s;
	char	*esp;
	char	*tmp;

	esp = do_pad(f->minor, pad[6]);
	tmp = esp;
	esp = ft_strsub(esp, 0, ft_strlen(esp) - 1);
	free(tmp);
	tmp = NULL;
	s = display(f, pad);
	s = ft_fstrjoin(s, do_pad(f->major, pad[5]), 0);
	s = ft_fstrjoin(s, f->major, 1);
	s = ft_fstrjoin(s, esp, 0);
	s = ft_fstrjoin(s, f->minor, 1);
	s = ft_fstrjoin(s, " ", 1);
	s = ft_fstrjoin(s, f->mtime, 1);
	s = ft_fstrjoin(s, f->name, 1);
	return (s);
}
