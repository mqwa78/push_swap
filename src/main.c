/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:06:41 by mqwa              #+#    #+#             */
/*   Updated: 2024/05/07 04:30:35 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		if (!ft_create_list(&stack_a, ac, av))
			ft_send_error(&stack_a, &stack_b);
		if (!ft_lst_is_sort(stack_a))
			ft_push_swap(&stack_a, &stack_b);
		ft_free_lst(&stack_a, &stack_b);
	}
	return (0);
}
