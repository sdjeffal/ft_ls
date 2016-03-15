/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:05:16 by sdjeffal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/15 11:32:24 by sdjeffal         ###   ########.fr       */
=======
/*   Updated: 2016/03/15 06:58:17 by sdjeffal         ###   ########.fr       */
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include "../inc/ft_ls.h"

int	isdir(char *filename)
{
	DIR	*dir;
	t_dirent *dp;

<<<<<<< HEAD
	if ((dir = opendir(filename)) == NULL)
	{
		msgnosuch(filename);
		return (0);
	}
	while ((dp = readdir(dir)) > 0)
	{
		if (dp->d_name[0] != '.')
=======
	if((dir = opendir(filename)) == NULL)
	{
		msgnosuch(filename);
		return(0);
	}
	while ((dp = readdir(dir)) > 0)
	{
		if(dp->d_name[0] != '.')
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
			ft_putendl(dp->d_name);
	}
	closedir(dir);
	return (0);
}

void	ls_default(int ac, char **av)
{
	DIR *dir;
<<<<<<< HEAD
	t_file *begin;
	t_dirent *dp;

	begin = NULL;
	if (ac == 1 || (ac == 2 && !ft_strcmp(av[1], "--")))
	{
		if ((dir = opendir("./")) == NULL)
=======
	t_dirent *dp;

	if(ac == 1 || (ac == 2 && !ft_strcmp(av[1], "--")))
	{
		if((dir = opendir("./")) == NULL)
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
		{
			perror("ft_ls");
			strerror(errno);
			exit(EXIT_FAILURE);
		}
		while ((dp = readdir(dir)) > 0)
<<<<<<< HEAD
			if (dp->d_name[0] != '.')
				insertascii(&begin, dp->d_name);
		putlstfile(&begin);
=======
			if(dp->d_name[0] != '.')
				ft_putendl(dp->d_name);
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
		closedir(dir);
		exit(EXIT_SUCCESS);
	}
}
<<<<<<< HEAD

=======
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
int	main(int argc, char **argv)
{
	t_opt option;
	t_file *begin;
	t_file *tmp;

	ls_default(argc, argv);
	option = getopt(argc, argv);
	begin = getfile(argc, argv);
<<<<<<< HEAD

=======
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
	tmp = begin;
	while(tmp != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
	/**while(tmp != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->prev;
	}**/
	/**while (name[i])
		isdir(name[i++]);**/
	ft_putstr("-a");
	ft_putnendl(option.a);
	ft_putstr("-l");
	ft_putnendl(option.l);
	ft_putstr("-r");
	ft_putnendl(option.rv);
	ft_putstr("-R");
	ft_putnendl(option.rc);
	ft_putstr("-t");
	ft_putnendl(option.t);
	return (0);
}
