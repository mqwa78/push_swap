/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:22:17 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:29:46 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	ft_list_swap :
	Swap les 2 premiers elements de la liste (s ils existent)
*/

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
	write(1, "sa\n", 3);
}

void	do_sb(t_list **stack_b)
{
	ft_list_swap(stack_b);
	write(1, "sb\n", 3);
}

void	do_ss(t_list **stack_a, t_list **stack_b)
{
	ft_list_swap(stack_a);
	ft_list_swap(stack_b);
	write(1, "ss\n", 3);
}
