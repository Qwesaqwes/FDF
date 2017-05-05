/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:00:33 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/20 16:33:42 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrev2(char *str)
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
	}
	tmp[i] = '\0';
	return (tmp);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	str = ft_strrev2(str);
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	str = ft_strrev2(str);
	return (str);
}
