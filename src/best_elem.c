/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:43:18 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:27:50 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_smallest_nbr(t_list *stack_b, int ref)
{
	t_list	*current;
	int		count;

	current = stack_b;
	count = 0;
	while (current)
	{
		if (current->value < ref)
			count++;
		current = current->next;
	}
	return (count);
}

int	ft_bigger_nbr(int *tab, int size)
{
	int	index;
	int	res;

	index = 0;
	res = tab[index];
	while (index < size)
	{
		if (tab[index] > res)
			res = tab[index];
		index++;
	}
	return (res);
}

int	ft_best_b(t_list *stack_b, int ref)
{
	int		*tab;
	int		res;
	int		size;
	int		index;

	size = ft_count_smallest_nbr(stack_b, ref);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	index = 0;
	while (index < size)
	{
		if (stack_b->value < ref)
			tab[index++] = stack_b->value;
		stack_b = stack_b->next;
	}
	res = ft_bigger_nbr(tab, size);
	free(tab);
	return (res);
}

int	ft_seek_elem_b(t_list **stack_a, t_list **stack_b, int pos_a)
{
	t_list	*tmp;
	int		pos_b;

	tmp = ft_get_elem(*stack_a, pos_a);
	if (ft_ismin(*stack_b, tmp->value))
		pos_b = ft_get_position(*stack_b, ft_get_max(*stack_b));
	else
		pos_b = ft_get_position(*stack_b, ft_best_b(*stack_b, tmp->value));
	return (pos_b);
}

int	ft_count_op(t_list *stack_a, t_list *stack_b, int a, int b)
{
	int	a_down;
	int	b_down;
	int	count_op;
	int	tmp;

	a_down = ft_list_size(stack_a) - a + 1;
	b_down = ft_list_size(stack_b) - b + 1;
	count_op = ft_count_up_down(a - 1, b - 1);
	tmp = ft_count_up_down(a_down, b_down);
	if (tmp < count_op)
		count_op = tmp;
	tmp = ft_count_all(a - 1, b - 1, a_down, b_down);
	if (tmp < count_op)
		count_op = tmp;
	return (count_op + 1);
}
