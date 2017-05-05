/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:23:23 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/20 16:32:20 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrev(char *str)
{
	char	*tmp;
	int		size;
	int		i;
	int		j;

	i = 0;
	size = ft_strlen(str);
	j = size - 1;
	tmp = (char *)malloc(sizeof(char *) * size);
	if (tmp)
	{
		while (i < size)
		{
			tmp[i] = str[j];
			i++;
			j--;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

char			*ft_itoa(int n)
{
	char			*res;
	int				neg;
	int				i;
	unsigned int	tmp;

	i = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	tmp = (neg ? -(unsigned int)n : (unsigned int)n);
	res = (char*)malloc(sizeof(char *) * 12);
	if (!res)
		return (NULL);
	if (tmp == 0)
		res[i++] = '0';
	while (tmp != 0)
	{
		res[i++] = (tmp % 10) + 48;
		tmp = tmp / 10;
	}
	if (neg)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_strrev(res));
}
