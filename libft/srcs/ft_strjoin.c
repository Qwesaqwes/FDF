/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 16:14:55 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/20 16:14:30 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, s1, len1);
	ft_strcpy(tmp + len1, s2);
	return (tmp);
}
