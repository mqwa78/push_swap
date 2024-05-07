/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:46:47 by mqwa              #+#    #+#             */
/*   Updated: 2024/05/07 00:28:09 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

t_bool	ft_isspace(int c)
{
	return (c == ' ' || c == '\t');
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

void	ft_cpy(char *dest, const char *src, int *pos)
{
	int	i;

	i = 0;
	while (src[*pos] && (ft_isdigit(src[*pos]) || src[*pos] == '-'))
	{
		dest[i] = src[*pos];
		i++;
		*pos += 1;
	}
	dest[i] = 0;
}

long	ft_atol(const char *str)
{
	int		i;
	long	m;
	long	res;

	res = 0;
	m = 1;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (m * res);
}
