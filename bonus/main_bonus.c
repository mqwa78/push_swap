/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:48:53 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 02:57:01 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
		ft_checker(&stack_a, &stack_b);
		ft_free_lst(&stack_a, &stack_b);
	}
	return (0);
}
