/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 16:08:27 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/20 16:15:15 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		tmp = (char*)malloc(ft_strlen(s) + 1);
		while (s[i] != '\0')
		{
			tmp[i] = (*f)(s[i]);
			i++;
		}
		return (tmp);
	}
	return (0);
}
