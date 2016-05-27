/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:18:46 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/27 15:55:18 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_file	*getlast(t_file **begin)
{
	t_file	*end;
	t_file	*tmp;

	tmp = (*begin);
	if ((*begin))
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	end = tmp;
	return (end);
}

void	freelst(t_file *tmp)
{
	t_file	*tmpnext;

	if (tmp)
	{
		while (tmp)
		{
			if (tmp->sub)
				freelst(tmp->sub);
			tmpnext = tmp->next;
			freefile(tmp);
			free(tmp);
			tmp = NULL;
			tmp = tmpnext;
		}
	}
}

int		main(int argc, char **argv)
{
	t_file	*begin;
	t_opt	option;
	int		ret;

	begin = NULL;
	ret = 0;
	option = ft_getopt(argc, argv);
	getfile(&begin, argc, argv, option);
	ret = ls_core(option, &begin);
	freelst(begin);
	exit(ret);
	return (0);
}
