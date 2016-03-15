/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:09:40 by sdjeffal          #+#    #+#             */
/*   Updated: 2016/03/15 12:10:16 by sdjeffal         ###   ########.fr       */
=======
/*   ft_strclen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 13:40:19 by sdjeffal          #+#    #+#             */
/*   Updated: 2015/11/30 21:52:58 by sdjeffal         ###   ########.fr       */
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strclen(const char *s, int c)
{
	size_t i;

	i = 0;
	if (!s)
<<<<<<< HEAD
		return (0);
=======
	 return (0);
>>>>>>> fa85dc1c3d6f8bc147dd9369f21f1796cc92b9d2
	while (s[i] != c)
		i++;
	return (i);
}
