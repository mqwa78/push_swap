/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:26:40 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:29:27 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	ft_push_elem :
	Envoyer element au sommet de la pile src vers la pile dest
*/

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

/*
	pa :
	Prend le premier element au sommet de b et le met sur a
*/

void	do_pa(t_list **stack_b, t_list **stack_a)
{
	ft_push_elem(stack_b, stack_a);
	write(1, "pa\n", 3);
}

/*
	pb :
	Prend le premier element au sommet de a et le met sur b
*/

void	do_pb(t_list **stack_a, t_list **stack_b)
{
	ft_push_elem(stack_a, stack_b);
	write(1, "pb\n", 3);
}
