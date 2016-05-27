/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 07:57:31 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/27 16:11:27 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/ft_ls.h"

static t_opt	*initopt(t_opt *new)
{
	new->a = FALSE;
	new->l = FALSE;
	new->rv = FALSE;
	new->rc = FALSE;
	new->t = FALSE;
	new->f = FALSE;
	new->fo = FALSE;
	return (new);
}

static int		setopt(char c, t_opt *opt)
{
	if (c == 'a')
		opt->a = TRUE;
	else if (c == 'l')
		opt->l = TRUE;
	else if (c == 'r')
	{
		if (!opt->f)
			opt->rv = TRUE;
	}
	else if (c == 'R')
		opt->rc = TRUE;
	else if (c == 't')
		opt->t = TRUE;
	else if (c == 'f')
	{
		opt->f = TRUE;
		opt->a = TRUE;
		opt->rv = FALSE;
	}
	else if (c == 'F')
		opt->fo = TRUE;
	else
		msgerropt(c);
	return (1);
}

t_opt			ft_getopt(int ac, char **av)
{
	t_opt	op;
	int		i;
	int		j;

	i = 0;
	initopt(&op);
	while (++i < ac)
	{
		j = 0;
		if (av[i][0] == '-' && av[i][1] == '-')
			break ;
		else if (av[i][j] == '-' && av[i][j + 1] != '\0')
		{
			while (av[i][++j] != '\0')
				setopt(av[i][j], &op);
		}
	}
	return (op);
}

void			getfile(t_file **lst, int ac, char **av, t_opt op)
{
	int		i;
	int		b;
	t_file	*tmp;

	b = FALSE;
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
			b = TRUE;
		else if ((av[i][0] != '-') || (av[i][0] == '-' && b))
		{
			tmp = newfile(av[i]);
			setpath(&tmp, tmp->name);
			insert(lst, tmp, op);
		}
	}
	if (!*lst)
	{
		tmp = newfile("./");
		setpath(&tmp, tmp->name);
		insert(lst, tmp, op);
	}
}

int				isopt(t_opt opt)
{
	if (opt.a || opt.l || opt.rv || opt.rc || opt.t || opt.f || opt.fo)
		return (TRUE);
	else
		return (FALSE);
}
