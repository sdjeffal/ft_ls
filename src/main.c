/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:05:16 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/01 16:17:09 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ls_default(int ac, char **av)
{
	DIR *dir;
	t_file *begin;
	t_dirent *dp;

	begin = NULL;
	if (ac == 1 || (ac == 2 && !ft_strcmp(av[1], "--")))
	{
		if ((dir = opendir("./")) == NULL)
			msgerr();
		while ((dp = readdir(dir)) > 0)
			if (dp->d_name[0] != '.')
				insertascii(&begin, dp->d_name);
		putlstfile(&begin);
		closedir(dir);
		exit(EXIT_SUCCESS);
	}
}

char	gettypefile(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		return ('-');
	else if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISLNK(st_mode))
		return ('l');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISFIFO(st_mode))
		return ('f');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else
		return ('u');
}

int	main(int argc, char **argv)
{
	t_opt option;
	t_file *begin;

	begin = NULL;
	ls_default(argc, argv);
	option = getopt(argc, argv);
	getfile(&begin, argc, argv);
	ls_core(option, &begin);
	if(begin == NULL)
		ft_putendl("vide");

	//putlstfile(&begin);
/**
	ft_putstr("-a");
	ft_putnendl(option.a);
	ft_putstr("-l");
	ft_putnendl(option.l);
	ft_putstr("-r");
	ft_putnendl(option.rv);
	ft_putstr("-R");
	ft_putnendl(option.rc);
	ft_putstr("-t");
	ft_putnendl(option.t);**/
	return (0);
}
