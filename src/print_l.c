/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:10:14 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/27 15:07:19 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	putfile_l(t_file *f, int *pad)
{
	char	*s;

	s = NULL;
	if (islnk(f))
		s = displaylnk(f, pad);
	else if (f->type[0] == '-' || f->type[0] == 'd'
			||
			f->type[0] == 's' || f->type[0] == 'p')
		s = displayfile(f, pad);
	else if (f->type[0] == 'b' || f->type[0] == 'c')
		s = displaydevice(f, pad);
	ft_putendl(s);
	free(s);
}

static void	putlstfile_l(t_file **begin, t_opt op)
{
	t_file	*tmp;

	if (*begin)
	{
		tmp = (op.rv) ? getlast(begin) : *begin;
		while (tmp)
		{
			if (op.fo)
				tmp->name = getclass(tmp->name, tmp->type, tmp->stat);
			putfile_l(tmp, (*begin)->pad);
			tmp = (op.rv) ? tmp->prev : tmp->next;
		}
	}
}

static	int	printonlyfile_l(t_file *lst, int *boolean, t_opt op)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = (op.rv) ? getlast(&lst) : lst;
	if (!(*boolean))
	{
		while (tmp)
		{
			if (isfile(tmp) || islnk(tmp) == -1)
			{
				putfile_l(tmp, lst->pad);
				i++;
			}
			tmp = (op.rv) ? tmp->prev : tmp->next;
		}
	}
	(*boolean) += 1;
	return (i);
}

int			putdirl(t_file *f, int nbrf, int i, int nbrerr)
{
	static int	ret;
	int			tmp;

	tmp = 0;
	if (i > 1 || (i == 1 && nbrf) || nbrerr || (f->next || f->prev))
		ft_putendl(f->path = ft_fstrjoin(f->path, ":", 1));
	ft_putendl(f->tblk);
	if (f->error && f->error->errn == EACCES)
	{
		ft_putendl(f->error->str);
		tmp = 1;
	}
	if (ret == 0 && tmp)
		ret = tmp;
	return (ret);
}

void		print_ls_dir_l(t_file **lst, t_opt op, int *ret)
{
	t_file		*tp;
	int			nbrf;
	int			nbrd;
	int			nbrerr;
	static int	i;

	nbrerr = errorexists(*lst, op);
	nbrf = printonlyfile_l(*lst, &i, op);
	tp = (op.rv) ? getlast(lst) : *lst;
	nbrd = getnbrdir(tp, op, i);
	if ((nbrf && nbrd) || (nbrd && i >= 2))
		ft_putchar('\n');
	while (tp)
	{
		if ((isdir(tp) || islnk(tp) == 1) && (iscurandpar(tp->name) || i < 2))
		{
			*ret = putdirl(tp, nbrf, i, nbrerr);
			putlstfile_l(&tp->sub, op);
			if (op.rc)
				print_ls_dir_l(&tp->sub, op, ret);
			if (getnbrdir((op.rv) ? tp->prev : tp->next, op, i))
				ft_putchar('\n');
		}
		tp = (op.rv) ? tp->prev : tp->next;
	}
}
