/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:53:31 by jichen-m          #+#    #+#             */
/*   Updated: 2016/02/07 03:18:35 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*copy;

	i = 0;
	copy = (unsigned char *)b;
	while (i < len)
	{
		copy[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
