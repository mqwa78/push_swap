/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:07:44 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 01:08:56 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_push_elem(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = (*src);
	(*src) = tmp;
}

void	do_pa(t_list **stack_b, t_list **stack_a)
{
	ft_push_elem(stack_b, stack_a);
}

void	do_pb(t_list **stack_a, t_list **stack_b)
{
	ft_push_elem(stack_a, stack_b);
}
