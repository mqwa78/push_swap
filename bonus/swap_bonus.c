/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:09:57 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 05:47:09 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_list_swap(t_list **stack)
{
	t_list	*current;
	int		tmp;

	current = (*stack);
	if (!current || !current->next)
		return ;
	tmp = current->value;
	current->value = current->next->value;
	current->next->value = tmp;
}

void	do_sa(t_list **stack_a)
{
	ft_list_swap(stack_a);
}

void	do_sb(t_list **stack_b)
{
	ft_list_swap(stack_b);
}

void	do_ss(t_list **stack_a, t_list **stack_b)
{
	ft_list_swap(stack_a);
	ft_list_swap(stack_b);
}
