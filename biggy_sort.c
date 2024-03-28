/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggy_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:46:51 by mamahtal          #+#    #+#             */
/*   Updated: 2024/03/28 06:07:13 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_best_elems(t_list **stack_a, t_list **stack_b)
{
	int	list_size;
	int	count;
	int	a;
	int	b;
	int	tmp;

	list_size = ft_list_size(*stack_a);
	count = 0;
	a = 1;
	while (a <= list_size)
	{
		b = ft_seek_elem_b(stack_a, stack_b, a);
		tmp = ft_count_op(*stack_a, *stack_b, a, b);
		if (count == 0 || tmp < count)
		{
			count = tmp;
			ft_reset_best(stack_a, stack_b);
			ft_setup(stack_a, stack_b, a, b);
		}
		a++;
	}
}

/*int	main(void)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*a;
	t_list	*b;

	stack_a = NULL;
	stack_b = NULL;
	ft_list_push_back(&stack_a, 64);
	ft_list_push_back(&stack_a, 2);
	ft_list_push_back(&stack_a, 67);
	ft_list_push_back(&stack_a, 20);
	ft_list_push_back(&stack_a, 15);
	ft_list_push_back(&stack_b, 1);
	ft_list_push_back(&stack_b, 9);
	ft_list_push_back(&stack_b, 1000);
	ft_list_push_back(&stack_b, 63);
	ft_list_push_back(&stack_b, 1000000);
	a = stack_a;
	b = stack_b;
	while (a || b)
	{
		printf("%d | %d\n", a->value, b->value);
		a = a->next;
		b = b->next;
	}
	ft_best_elems(&stack_a, &stack_b);
	while (stack_a || stack_b)
	{
		if (stack_a->best)
			printf("best nbr pour a : %d\n", stack_a->value);
		if (stack_b->best)
			printf("best nbr pour b : %d\n", stack_b->value);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	ft_free_lst(&stack_a, &stack_b);
	return (0);
}*/
