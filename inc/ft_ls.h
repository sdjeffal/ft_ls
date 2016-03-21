/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 17:57:44 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/21 15:32:22 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"
#	ifndef FALSE
# 		define FALSE	0
#	endif
#	ifndef TRUE
# 		define TRUE		1
#	endif

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct			s_opt
{
	int	a;
	int	l;
	int	rv;
	int	rc;
	int	t;
}						t_opt;

typedef struct			s_file
{
	char	*name;
	t_stat	stat;
	char	type;
	char	*size;
	char	*err;
	struct s_file	*prev;
	struct s_file	*next;
}						t_file;

t_opt					getopt(int ac, char **av);
t_file					*getfile(int ac, char **av);
t_file					*newfile(char *name);
void					checkfile(t_file *lst);
void					ls_default(int ac, char **av);
void					filepushback(t_file **begin, char *name);
void					insertascii(t_file **lst, char *s);
void					putlstfile(t_file **begin);
char					gettypefile(mode_t st_mode);
void					msgerropt(char c);
void					msgerrfile(char *file);
void					msgerr(void);
void					erropen(t_file *lst);
#endif
