/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:54:15 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:56:14 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_bool	ft_parse(char *tab)
{
	size_t	i;

	i = 0;
	if (tab[0] == '0' && tab[1])
		return (0);
	if (tab[0] == '-' && (!tab[1] || tab[1] == '0' || !ft_isdigit(tab[1])))
		return (0);
	while (tab[i])
	{
		if (tab[i] == '-' && i != 0)
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_count_digits(char *arg, int pos)
{
	size_t	count;

	count = 0;
	while (arg[pos] && (ft_isdigit(arg[pos]) || arg[pos] == '-'))
	{
		count++;
		pos++;
	}
	return (count);
}

t_bool	ft_create(t_list **stack_a, char *arg)
{
	char	tab[INT_SIZE];
	int		i;
	long	nb;

	i = 0;
	while (arg[i])
	{
		while (arg[i] && ft_isspace(arg[i]))
			i++;
		if (arg[i] && (ft_isdigit(arg[i]) || arg[i] == '-'))
		{
			if (ft_count_digits(arg, i) >= INT_SIZE)
				return (0);
			ft_bzero(tab, INT_SIZE);
			ft_cpy(tab, arg, &i);
			if (!ft_parse(tab))
				return (0);
			nb = ft_atol(tab);
			if (nb < INT_MIN || nb > INT_MAX || !ft_isdoublon(stack_a, (int)nb))
				return (0);
			ft_list_push_back(stack_a, (int)nb);
		}
	}
	return (1);
}

t_bool	ft_check_arg(char *arg)
{
	size_t	i;

	if (!arg || !*arg)
		return (0);
	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && !ft_isspace(arg[i]) && arg[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

t_bool	ft_create_list(t_list **stack_a, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_check_arg(av[i]))
			return (0);
		if (!ft_create(stack_a, av[i]))
			return (0);
		i++;
	}
	return (1);
}
