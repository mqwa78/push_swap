/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:57:16 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:59:15 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_list_cleaner(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack))
		return ;
	while ((*stack))
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}

void	ft_free_lst(t_list **stack_a, t_list **stack_b)
{
	ft_list_cleaner(stack_a);
	ft_list_cleaner(stack_b);
}

void	ft_send_error(t_list **stack_a, t_list **stack_b)
{
	write(2, "error\n", 6);
	ft_free_lst(stack_a, stack_b);
	exit(1);
}
