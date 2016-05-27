/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:44:17 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/26 13:03:33 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		printerror(t_file *f, int errn)
{
	t_file	*tmp;
	int		ret;

	tmp = f;
	ret = 0;
	while (tmp)
	{
		if (tmp->error && tmp->error->errn == errn)
		{
			ft_putendl(tmp->error->str);
			ret = 1;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	msgerropt(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ft_ls [-alrRtfF] [file..]", 2);
	exit(EXIT_FAILURE);
}

void	msgerr(void)
{
	perror("ft_ls");
	exit(EXIT_FAILURE);
}
