/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 17:57:44 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/05/25 23:49:35 by sdjeffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

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
	char	*link;
	char	*nlink;
	char	*path;
	char	type;
	t_stat	stat;
	char	*chmod;
	char	*size;
	char	*tblk;
	char	*major;
	char	*minor;
	char	*atime;
	char	*mtime;
	char	*ctime;
	int		pad[7];
	struct group	*gr;
	struct passwd	*pwd;
	struct s_error	*error;
	struct s_file	*prev;
	struct s_file	*next;
	struct s_file	*sub;
}						t_file;

typedef struct			s_error
{
	char *str;
	int errn;
}						t_error;

t_opt					ft_getopt(int ac, char **av);
void					getfile(t_file **lst, int ac, char **av, t_opt op);
t_file					*newfile(char *name);
void					checkfiles(t_file **lst);
void					ls_default(int ac, char **av);
void					filepushback(t_file **begin, char *name);
void					insertascii(t_file **lst, t_file *new);
void					insertmtime(t_file **lst, t_file *f);
void					insert(t_file **lst, t_file *f, t_opt op);
void					freefile(t_file **file);
void					adderror(t_file *f);
char					gettypefile(mode_t st_mode);
void					getnlink(t_file **f, int *pad);
void					getsize(t_file **f, int *pad);
void					msgerropt(char c);
void					msgerr(void);
t_error					*mallocerror(void);
int						erropen(t_file *lst);
int						errorexists(t_file *lst, t_opt op);
int						isfile(t_file *f);
int						islnk(t_file *f);
int						isdir(t_file *f);
int						isopt(t_opt opt);
char					*display(t_file *f, int *pad);
char					*displayfile(t_file *f, int *pad);
char					*displaylnk(t_file *f, int *pad);
char					*displaydevice(t_file *f, int *pad);
int						iscurandpar(char *s);
void					delfile(t_file **lst, char *name);
void					ls_core(t_opt op, t_file **lst);
void					ls_dir(t_file **lst, t_opt op);
void					ls_dir_rec(t_file **lst, t_opt op);
void					debuglst(t_file **begin);
int						getlenghtlst(t_file *lst);
int						getnbrdir(t_file *lst, t_opt op, int t);
int						checkdir(t_file **lst, DIR *dir);
void					print_ls_dir(t_file **lst, t_opt op);
void					print_ls_dir_l(t_file **lst, t_opt op);
int						printerror(t_file *f, int errn);
void					setpath(t_file **lst, char *path);
char					*getlststat(t_file **f);
void					getchmod(t_file **f);
t_file					*getlast(t_file **begin);
#endif
