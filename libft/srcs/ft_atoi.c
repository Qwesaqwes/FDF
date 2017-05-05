/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:26:20 by jichen-m          #+#    #+#             */
/*   Updated: 2016/02/07 02:47:01 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	res = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			res = res * 10 + (str[i] - '0');
		else
			return (res * sign);
		i++;
	}
	return (res * sign);
}
