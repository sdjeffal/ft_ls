#include "../inc/ft_ls.h"

t_file	*newfile(char *name)
{
	t_file *new;

	if((new = (t_file*)malloc(sizeof(t_file))) == NULL)
		msgerr();
	else
	{
		if(name == NULL)
			new->name = NULL;
		else
		{
			new->name = ft_strdup(name);
			if(new->name == NULL)		
				msgerr();
		}
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

void	filepushback(t_file **begin, char *name)
{
	t_file *tmp;

	tmp = NULL;
	if(*begin == NULL)
		*begin = newfile(name);
	else
	{
		tmp = *begin;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = newfile(name);
		tmp->next->prev = tmp;
	}
}
