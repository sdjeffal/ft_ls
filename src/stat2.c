/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 23:09:42 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/26 18:35:48 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	getnlink(t_file **f, int *pad)
{
	int	len;

	(*f)->nlink = ft_itoa((*f)->stat.st_nlink);
	if (pad[0] < (len = ft_strlen((*f)->nlink)))
		pad[0] = len;
}

void	getsize(t_file **f, int *pad)
{
	int	len;
	int	n;

	n = 0;
	if ((*f)->type[0] != 'c' && (*f)->type[0] != 'b')
	{
		(*f)->size = ft_itoa((*f)->stat.st_size);
		if (pad[3] < (len = ft_strlen((*f)->size)))
			pad[3] = len;
	}
	else if ((*f)->type[0] == 'c' || (*f)->type[0] == 'b')
	{
		n = major((*f)->stat.st_rdev);
		(*f)->major = ft_fstrjoin(ft_itoa(n), ",", 1);
		if (pad[5] < (len = ft_strlen((*f)->major)))
			pad[5] = len;
		n = minor((*f)->stat.st_rdev);
		(*f)->minor = ft_itoa(n);
		if (pad[6] < (len = ft_strlen((*f)->major)))
			pad[6] = len;
		if (pad[3] < (len = pad[5] + pad[6] + 1))
			pad[3] = len;
	}
}
