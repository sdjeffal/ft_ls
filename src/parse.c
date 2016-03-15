/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 07:57:31 by sdjeffal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/15 12:01:21 by sdjeffal         ###   ########.fr       */
=======
/*   Updated: 2016/03/15 07:00:46 by sdjeffal         ###   ########.fr       */
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/ft_ls.h"

static t_opt	*initopt(t_opt *new)
<<<<<<< HEAD
{
=======
{	
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
	new->a = FALSE;
	new->l = FALSE;
	new->rv = FALSE;
	new->rc = FALSE;
	new->t = FALSE;
	return (new);
}

<<<<<<< HEAD
static int		isopt(char c, t_opt *opt)
=======
static int	isopt(char c, t_opt *opt)
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
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
<<<<<<< HEAD
	else
=======
	else 
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
		msgerropt(c);
	return (1);
}

<<<<<<< HEAD
t_opt			getopt(int ac, char **av)
{
	t_opt	op;
	int		i;
	int		j;
=======
t_opt	getopt(int ac, char **av)
{
	t_opt op;
	int i;
	int j;
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2

	i = 0;
	initopt(&op);
	while (++i < ac)
	{
		j = 0;
<<<<<<< HEAD
		if ((av[i][0] == '-' && (av[i][1] == '-' || av[i][1] == 0))
				|| av[i][0] != '-')
			break ;
=======
		if ((av[i][0] == '-' && (av[i][1] == '-' || av[i][1] == 0)) 
				|| av[i][0] != '-')
			break;
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
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
<<<<<<< HEAD
			insertascii(&lst, av[i]);
			b = TRUE;
		}
	}
	if (!lst)
		insertascii(&lst, "./");
	return (lst);
}

t_file			*getfile(int ac, char **av)
{
	t_file	*begin;

	begin = NULL;
	begin = parsefile(begin, ac, av);
	return (begin);
=======
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
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
}
