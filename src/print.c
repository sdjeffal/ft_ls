/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:09:19 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/27 15:07:46 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static int		putlstfile(t_file **begin, t_opt op)
{
	t_file	*tmp;
	int		ret;

	ret = 0;
	if (*begin)
	{
		tmp = (op.rv) ? getlast(begin) : *begin;
		while (tmp)
		{
			if (op.fo)
				tmp->name = getclass(tmp->name, tmp->type, tmp->stat);
			ft_putendl(tmp->name);
			tmp = (op.rv) ? tmp->prev : tmp->next;
		}
		ret = 1;
	}
	return (ret);
}

static int		printfile(t_file *lst, int *boolean, t_opt op)
{
	t_file	*tmp;
	int		i;

	i = 0;
	tmp = (op.rv) ? getlast(&lst) : lst;
	if (!(*boolean))
	{
		while (tmp)
		{
			if (isfile(tmp))
			{
				if (op.fo)
					tmp->name = getclass(tmp->name, tmp->type, tmp->stat);
				ft_putendl(tmp->name);
				i++;
			}
			tmp = (op.rv) ? tmp->prev : tmp->next;
		}
	}
	(*boolean) += 1;
	return (i);
}

static void		putpath(t_file *f, int i, int nbrf, int nbrerr)
{
	if ((f->type[0] == 'l' && f->sub != NULL) ||
		(f->type[0] != 'l' && (i > 1 || (i == 1 && nbrf) ||
		nbrerr || (f->next || f->prev))))
		ft_putendl(f->path = ft_fstrjoin(f->path, ":", 1));
}

static int		putdir(t_file *f, int i, int nbrf, int nbrerr)
{
	static int	ret;
	int			tmp;

	tmp = 0;
	putpath(f, i, nbrf, nbrerr);
	if (f->error && f->error->errn == EACCES)
	{
		ft_putendl(f->error->str);
		tmp = 1;
	}
	if (ret == 0 && tmp)
		ret = tmp;
	return (ret);
}

void			print_ls_dir(t_file **lst, t_opt op, int *ret)
{
	t_file		*tmp;
	int			nbrf;
	int			nbrd;
	int			nbrerr;
	static int	i;

	nbrerr = errorexists(*lst, op);
	nbrf = printfile(*lst, &i, op);
	tmp = (op.rv) ? getlast(lst) : *lst;
	nbrd = getnbrdir(tmp, op, i);
	if ((nbrf && i < 2 && nbrd) || (nbrd && i >= 2))
		ft_putchar('\n');
	while (tmp)
	{
		if ((isdir(tmp) || islnk(tmp)) && (iscurandpar(tmp->name) || i < 2))
		{
			*ret = putdir(tmp, i, nbrf, nbrerr);
			nbrf = putlstfile(&tmp->sub, op);
			if (op.rc)
				print_ls_dir(&tmp->sub, op, ret);
			if ((nbrd = getnbrdir((op.rv) ? tmp->prev : tmp->next, op, i)))
				ft_putchar('\n');
		}
		tmp = (op.rv) ? tmp->prev : tmp->next;
	}
}
