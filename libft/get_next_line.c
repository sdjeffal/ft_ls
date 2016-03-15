/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:47:08 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/05 20:08:44 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_list	*ft_find_fd(t_list **begin, int fd)
{
	t_list	*tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

static char		*ft_realloc_strnjoin(char *str, char *buff, int ret)
{
	char	*tmp;

	tmp = str;
	str = ft_strnjoin(str, buff, ret);
	free(tmp);
	return (str);
}

static int		gnl_parse(t_list **lst, char *buff)
{
	int		r;

	while (!ft_strchr((*lst)->content, '\n')
			&& (r = read((*lst)->content_size, buff, BUFF_SIZE)))
		(*lst)->content = ft_realloc_strnjoin((*lst)->content, buff, r);
	r = 0;
	while (((char *)(*lst)->content)[r] && ((char *)(*lst)->content)[r] != '\n')
		++r;
	return (r);
}

int				get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static t_list	*list = NULL;
	t_list			*begin;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0))
		return (-1);
	begin = list;
	list = ft_find_fd(&begin, fd);
	ret = gnl_parse(&list, buff);
	*line = ft_strndup(list->content, ret);
	if (((char *)list->content)[ret] == '\n')
		++ret;
	tmp = list->content;
	list->content = ft_strdup(list->content + ret);
	free(tmp);
	list = begin;
	return (ret ? 1 : 0);
}
