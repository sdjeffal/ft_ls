/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:18:46 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/29 22:43:25 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ls_default(int ac, char **av)
{
	t_dirent	*dp;
	t_file		*begin;
	DIR			*dir;

	begin = NULL;
	if (ac == 1 || (ac == 2 && !ft_strcmp(av[1], "--")))
	{
		if ((dir = opendir("./")) == NULL)
			msgerr();
		while ((dp = readdir(dir)) > 0)
		{
			if (dp->d_name[0] != '.')
				insertascii(&begin, newfile(dp->d_name));
		}
		putlstfile(&begin);
		closedir(dir);
		exit(EXIT_SUCCESS);
	}
}

int		main(int argc, char **argv)
{
	t_file	*begin;
	t_opt	option;

	begin = NULL;
	ls_default(argc, argv);
	option = ft_getopt(argc, argv);
	getfile(&begin, argc, argv, option);
	ls_core(option, &begin);
	return (0);
}
