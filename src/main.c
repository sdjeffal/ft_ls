/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:05:16 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/15 09:18:41 by sdjeffal         ###   ########.fr       */
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

	if((dir = opendir(filename)) == NULL)
	{
		msgnosuch(filename);
		return(0);
	}
	while ((dp = readdir(dir)) > 0)
	{
		if(dp->d_name[0] != '.')
			ft_putendl(dp->d_name);
	}
	closedir(dir);
	return (0);
}

void	ls_default(int ac, char **av)
{
	DIR *dir;
	t_dirent *dp;

	if(ac == 1 || (ac == 2 && !ft_strcmp(av[1], "--")))
	{
		if((dir = opendir("./")) == NULL)
		{
			perror("ft_ls");
			strerror(errno);
			exit(EXIT_FAILURE);
		}
		while ((dp = readdir(dir)) > 0)
			if(dp->d_name[0] != '.')
				ft_putendl(dp->d_name);
		closedir(dir);
		exit(EXIT_SUCCESS);
	}
}

void	filesortascii(t_file **lst)
{

}

int	main(int argc, char **argv)
{
	t_opt option;
	t_file *begin;
	t_file *tmp;

	ls_default(argc, argv);
	option = getopt(argc, argv);
	begin = getfile(argc, argv);

	tmp = begin;
	/**while(tmp != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
	while(tmp != NULL)
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
