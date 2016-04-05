/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:44:17 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/04/01 15:51:14 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../inc/ft_ls.h"

void	msgerropt(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ft_ls [-alrRt] [file..]", 2);
	exit(EXIT_FAILURE);
}

void	msgerr(void)
{
	perror("ft_ls");
	exit(EXIT_FAILURE);
}

int	erropen(t_file *lst)
{
	if (errno == EACCES)
		lst->err = ft_strdup(strerror(errno));
	else if (errno == ENOENT)
	{
		perror(ft_strjoin("ft_ls: ", lst->name));
		return (1);
	}
	else if (errno == EMFILE || errno == ENFILE || errno == ENOMEM)
		msgerr();
	else if (errno == ENOTDIR)
	{
		lstat(lst->name, &lst->stat);
		lst->type = gettypefile(lst->stat.st_mode);
		return (0);
	}
	return (0);
}
