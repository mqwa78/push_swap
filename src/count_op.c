/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 04:09:51 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:28:02 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_up_down(int a, int b)
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

void	ft_setup_up(t_list *stack_a, t_list *stack_b, int pos_a, int pos_b)
{
	t_list	*elem_a;
	t_list	*elem_b;

	elem_a = ft_best_to_elem(stack_a);
	elem_b = ft_best_to_elem(stack_b);
	ft_reset_all_var(elem_a, elem_b);
	if (pos_a < pos_b)
	{
		elem_a->double_up = pos_a;
		elem_b->do_up = pos_b - pos_a;
	}
	else
	{
		elem_b->double_up = pos_b;
		elem_a->do_up = pos_a - pos_b;
	}
}

void	ft_setup_down(t_list *stack_a, t_list *stack_b, int a_down, int b_down)
{
	t_list	*elem_a;
	t_list	*elem_b;

	elem_a = ft_best_to_elem(stack_a);
	elem_b = ft_best_to_elem(stack_b);
	ft_reset_all_var(elem_a, elem_b);
	if (a_down < b_down)
	{
		elem_a->double_down = a_down;
		elem_b->do_down = b_down - a_down;
	}
	else
	{
		elem_b->double_down = b_down;
		elem_a->do_down = a_down - b_down;
	}
}

void	ft_setup_all(t_list *stack_a, t_list *stack_b, int a_down, int b_down)
{
	t_list	*elem_a;
	t_list	*elem_b;
	int		pos_a;
	int		pos_b;

	elem_a = ft_best_to_elem(stack_a);
	elem_b = ft_best_to_elem(stack_b);
	ft_reset_all_var(elem_a, elem_b);
	pos_a = ft_pos(stack_a);
	pos_b = ft_pos(stack_b);
	if (pos_a + b_down < pos_b + a_down)
	{
		elem_a->do_up = pos_a - 1;
		elem_b->do_down = b_down;
	}
	else
	{
		elem_b->do_up = pos_b - 1;
		elem_a->do_down = a_down;
	}
}
