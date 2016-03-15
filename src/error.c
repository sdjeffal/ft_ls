/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:44:17 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/15 12:04:46 by sdjeffal         ###   ########.fr       */
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
	strerror(errno);
	exit(EXIT_FAILURE);
}

void	msgnosuch(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(" No such file or directory", 2);
}
