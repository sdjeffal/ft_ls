/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 17:57:44 by sdjeffal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/15 12:04:34 by sdjeffal         ###   ########.fr       */
=======
/*   Updated: 2016/03/11 19:28:13 by sdjeffal         ###   ########.fr       */
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
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
	struct s_file	*prev;
	struct s_file	*next;
}						t_file;

t_opt					getopt(int ac, char **av);
t_file					*getfile(int ac, char **av);
t_file					*newfile(char *name);
void					filepushback(t_file **begin, char *name);
<<<<<<< HEAD
void					insertascii(t_file **lst, char *s);
void					putlstfile(t_file **begin);
void					msgerropt(char c);
void					msgnosuch(char *name);
void					msgerr(void);
=======
void					msgerropt(char c);
void					msgnosuch(char *name);
void					msgerr();
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2

#endif
