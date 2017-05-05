/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:53:44 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/20 16:10:38 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str3;

	str = (unsigned char *)str1;
	str3 = (unsigned char *)str2;
	if (!str2)
		return (NULL);
	while (n--)
		*str++ = *str3++;
	return ((char *)str1);
}
