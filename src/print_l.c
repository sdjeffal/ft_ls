/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:10:14 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/25 23:16:21 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void putfile_l(t_file *f, int *pad)
{
	char *s;

	if (islnk(f))
		s = displaylnk(f, pad);
	else if(f->type == '-' || f->type == 'd'
			||
			f->type == 's' || f->type == 'p')
		s = displayfile(f, pad);
	else if(f->type == 'b' || f->type == 'c')
		s = displaydevice(f, pad);
	ft_putendl(s);
}

static void	putlstfile_l(t_file **begin)
{
	t_file	*tmp;

	if (*begin)
	{
		tmp = *begin;
		while (tmp)
		{
			putfile_l(tmp, (*begin)->pad);
			tmp = tmp->next;
		}
	}
}

static	int	printonlyfile_l(t_file *lst, int boolean)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (isfile(tmp) || islnk(tmp) == -1)
		{	
			if(!boolean)
				putfile_l(tmp, lst->pad);
			i++;
		}
		tmp = tmp->next;
	}
	return (i);
}

void		print_ls_dir_l(t_file **lst, t_opt op)
{
	t_file		*tmp;
	int			nbrf;
	int			nbrd;
	int			nbrerr;
	static int	i;

	tmp = *lst;
	nbrf = printonlyfile_l(tmp, i++);
	nbrd = getnbrdir(tmp, op, i);
	nbrerr = errorexists(tmp, op);
	if (nbrf && nbrd)
		ft_putchar('\n');
	while (tmp)
	{
		if ((isdir(tmp) || islnk(tmp) == 1) && (iscurandpar(tmp->name) || i < 2))
		{
			if (nbrf || nbrd > 1 || nbrerr > 1)
				ft_putendl(tmp->path = ft_fstrjoin(tmp->path, ":", 1));
			ft_putendl(tmp->tblk);
			if (tmp->error && tmp->error->errn == EACCES)
				ft_putendl(tmp->error->str);
			putlstfile_l(&tmp->sub);
			if(op.rc)
				print_ls_dir_l(&tmp->sub, op);
			if (getnbrdir(tmp->next, op, i))
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}
