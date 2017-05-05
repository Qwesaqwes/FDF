/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 16:13:18 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/20 16:09:31 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;

	if (!size)
		return (NULL);
	tmp = (void*)malloc(size);
	if (!tmp)
		return (NULL);
	ft_bzero((void*)tmp, size);
	return ((void*)tmp);
}
