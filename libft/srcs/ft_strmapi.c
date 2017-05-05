/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 15:41:49 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/20 15:41:53 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		tmp = (char*)malloc(ft_strlen(s) + 1);
		while (s[i])
		{
			tmp[i] = (*f)(i, s[i]);
			i++;
		}
		return (tmp);
	}
	return (0);
}
