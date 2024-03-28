/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:10:26 by mqwa              #+#    #+#             */
/*   Updated: 2024/03/28 05:08:30 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_SIZE 12
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef int	t_bool;

typedef struct s_list
{
	int				value;
	t_bool			best;
	int				do_up;
	int				do_down;
	int				double_up;
	int				double_down;
	struct s_list	*next;
}						t_list;

/*  	CREATE_LIST        */

t_bool	ft_create_list(t_list **stack_a, int ac, char **av);
t_bool	ft_check_arg(char *arg);
t_bool	ft_create(t_list **stack_a, char *arg);
t_bool	ft_parse(char *tab);
size_t	ft_count_digits(char *arg, int pos);

/*		CREATE_TOOLS       */

t_bool	ft_isdigit(int c);
t_bool	ft_isspace(int c);
void	ft_bzero(void *s, size_t n);
void	ft_cpy(char *dest, const char *src, int *pos);
long	ft_atol(const char *str);

/*      PUSH_SWAP          */

void	ft_push_swap(t_list **stack_a, t_list **stack_b);
void	ft_tiny_sort(t_list **stack);
void	ft_tiny(t_list **stack, int min, int max, int last);
void	ft_middy_sort(t_list **stack_a, t_list **stack_b);
void	ft_biggy_sort(t_list **stack_a, t_list **stack_b);

/*      BIGGY SORT         */

void	ft_best_elems(t_list **stack_a, t_list **stack_b);
int		ft_seek_elem_b(t_list **stack_a, t_list **stack_b, int pos_a);
int		ft_best_b(t_list *stack_b, int value);
int		ft_count_smallest_nbr(t_list *stack_b, int ref);
int		ft_bigger_nbr(int *tab, int size);
int		ft_count_op(t_list *stack_a, t_list *stack_b, int a, int b);
int		ft_count_up(int a, int b);
int		ft_count_down(int a, int b);
int		ft_count_all(int a_up, int b_up, int a_down, int b_down);
void	ft_reset_best(t_list **stack_a, t_list **stack_b);
void	ft_setup(t_list **stack_a, t_list **stack_b, int a, int b);

/*     MIN AND MAX         */

int		ft_get_min(t_list *stack);
int		ft_get_max(t_list *stack);
t_bool	ft_ismin(t_list *stack, int value);
t_bool	ft_ismax(t_list *stack, int value);

/*     LIST_MANIPULATIONS  */

t_list	*ft_create_element(int value);
void	ft_list_push_back(t_list **begin_list, int value);
t_list	*ft_last_elem(t_list *begin_list);
t_list	*ft_before_last_elem(t_list *begin_list);
int		ft_list_size(t_list *begin_list);
t_bool	ft_isdoublon(t_list **stack_a, int value);
t_bool	ft_lst_is_sort(t_list *stack_a);
int		ft_get_value(t_list *stack, int pos);
int		ft_get_position(t_list *stack, int value);
t_list	*ft_get_elem(t_list *stack, int pos);

/*      FREE AND ERROR    */

void	ft_list_cleaner(t_list **stack);
void	ft_free_lst(t_list **stack_a, t_list **stack_b);
void	ft_send_error(t_list **stack_a, t_list **stack_b);

/*     OPERATIONS        */

void	ft_list_swap(t_list **stack);
void	do_sa(t_list **stack_a);
void	do_sb(t_list **stack_b);
void	do_ss(t_list **stack_a, t_list **stack_b);
void	ft_push_elem(t_list **src, t_list **dest);
void	do_pa(t_list **stack_b, t_list **stack_a);
void	do_pb(t_list **stack_a, t_list **stack_b);
void	ft_list_rotate(t_list **stack);
void	do_ra(t_list **stack_a);
void	do_rb(t_list **stack_b);
void	do_rr(t_list **stack_a, t_list **stack_b);
void	ft_rev_rotate(t_list **stack);
void	do_rra(t_list **stack_a);
void	do_rrb(t_list **stack_b);
void	do_rrr(t_list **stack_a, t_list **stack_b);
#endif
