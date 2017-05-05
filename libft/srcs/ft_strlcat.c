/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:01:10 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/20 16:14:42 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t		s2len;
	size_t		s1len;
	size_t		res;
	size_t		tmp;

	s2len = ft_strlen(s2);
	s1len = ft_strlen((const char *)s1);
	res = s2len + s1len;
	tmp = s2len - (res - (n - 1));
	if (n <= s1len)
		return (n + s2len);
	if (res < n)
		ft_strcat(s1, s2);
	else
		ft_strncat(s1, s2, tmp);
	return (res);
}
