/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:22:19 by mqwa              #+#    #+#             */
/*   Updated: 2024/05/07 00:28:51 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_create_element(int value)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem != NULL)
	{
		elem->value = value;
		elem->best = 0;
		elem->do_up = 0;
		elem->do_down = 0;
		elem->double_up = 0;
		elem->double_down = 0;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, int value)
{
	t_list	*elem;
	t_list	*current;

	elem = ft_create_element(value);
	if (!elem)
		return ;
	current = (*begin_list);
	if (!current)
		(*begin_list) = elem;
	else
	{
		while (current->next)
			current = current->next;
		current->next = elem;
	}
}

t_list	*ft_last_elem(t_list *begin_list)
{
	if (!begin_list)
		return (begin_list);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

t_list	*ft_before_last_elem(t_list *begin_list)
{
	if (!begin_list || !begin_list->next)
		return (NULL);
	while (begin_list->next->next)
		begin_list = begin_list->next;
	return (begin_list);
}

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}
