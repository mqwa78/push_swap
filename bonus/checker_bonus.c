/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:43:30 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 05:45:00 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}

int	ft_seek(t_list **stack_a, t_list **stack_b, char *line)
{
	int	res;

	res = 1;
	if (ft_strncmp(line, "sa\n", 3) == 0)
		do_sa(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		do_sb(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		do_ss(stack_a, stack_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		do_pa(stack_b, stack_a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		do_pb(stack_a, stack_b);
	else
		res = 0;
	return (res);
}

int	ft_seek2(t_list **stack_a, t_list **stack_b, char *line)
{
	int	res;

	res = 1;
	if (ft_strncmp(line, "ra\n", 3) == 0)
		do_ra(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		do_rb(stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		do_rr(stack_a, stack_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		do_rra(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		do_rrb(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		do_rrr(stack_a, stack_b);
	else
		res = 0;
	return (res);
}

void	ft_check_line(t_list **a, t_list **b, char *line)
{
	if (ft_seek(a, b, line) == 0 && ft_seek2(a, b, line) == 0)
		ft_send_error(a, b);
}

void	ft_checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		etat;

	etat = 1;
	while (etat)
	{
		line = ft_gnl(0);
		if (!line)
			etat = 0;
		if (etat)
		{
			ft_check_line(stack_a, stack_b, line);
			free(line);
		}
	}
	if (line)
		free(line);
	if (ft_lst_is_sort(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
