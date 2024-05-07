/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 06:03:52 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:28:32 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_fill_tab(t_list *stack, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = stack->value;
		stack = stack->next;
		i++;
	}
}

int	ft_seek_couple(int *tab, int a, int b)
{
	int	res;
	int	i;

	i = 0;
	while (i < MIDDY && tab[i] < b)
		i++;
	if (i == MIDDY)
		res = a;
	else
	{
		if (a < b)
			res = tab[i];
		else if (tab[i] < a)
			res = tab[i];
		else
			res = a;
	}
	return (res);
}

void	ft_move_best(t_list **stack, int value)
{
	int	pos;
	int	lst_size;

	pos = ft_get_position(*stack, value);
	lst_size = ft_list_size(*stack);
	while (pos++ <= lst_size)
		do_rra(stack);
}
