/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 04:09:51 by mamahtal          #+#    #+#             */
/*   Updated: 2024/03/28 04:20:39 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_up(int a, int b)
{
	int	res;

	if (a > b)
		res = a;
	else
		res = b;
	return (res);
}

int	ft_count_down(int a, int b)
{
	int	res;

	if (a > b)
		res = a;
	else
		res = b;
	return (res);
}

int	ft_count_all(int a_up, int b_up, int a_down, int b_down)
{
	int	res;
	int	tmp;

	res = a_up + b_down;
	tmp = b_up + a_down;
	if (tmp < res)
		res = tmp;
	return (res);
}
