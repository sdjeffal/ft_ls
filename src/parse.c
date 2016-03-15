/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 07:57:31 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/15 07:00:46 by sdjeffal         ###   ########.fr       */
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
	return (new);
}

static int	isopt(char c, t_opt *opt)
{
	if (c == 'a')
		opt->a = TRUE;
	else if (c == 'l')
		opt->l = TRUE;
	else if (c == 'r')
		opt->rv = TRUE;
	else if (c == 'R')
		opt->rc = TRUE;
	else if (c == 't')
		opt->t = TRUE;
	else 
		msgerropt(c);
	return (1);
}

t_opt	getopt(int ac, char **av)
{
	t_opt op;
	int i;
	int j;

	i = 0;
	initopt(&op);
	while (++i < ac)
	{
		j = 0;
		if ((av[i][0] == '-' && (av[i][1] == '-' || av[i][1] == 0)) 
				|| av[i][0] != '-')
			break;
		else if (av[i][j] == '-' && av[i][j + 1] != '\0')
		{
			while (av[i][++j] != '\0')
				isopt(av[i][j], &op);
		}
	}
	return (op);
}

static t_file	*parsefile(t_file *lst, int ac, char **av)
{
	int i;
	int b;

	b = FALSE;
	i = 0;
	while (++i < ac)
	{
		if ((av[i][0] == '-' && (av[i][1] == '-' || av[i][1] == 0)))
			b = TRUE;
		else if ((av[i][0] != '-') || (av[i][0] == '-' && b))
		{
			filepushback(&lst, av[i]);
			b = TRUE;
		}
	}
	if(!lst)
		filepushback(&lst, "./");
	return (lst);
}

t_file	*getfile(int ac, char **av)
{
	t_file	*begin;
	
	begin = NULL;
	begin = parsefile(begin, ac, av);
	return (begin);	
}
