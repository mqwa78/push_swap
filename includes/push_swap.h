/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:10:26 by mqwa              #+#    #+#             */
/*   Updated: 2024/05/06 23:56:49 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_SIZE 12
# define MIDDY 10
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
void	ft_middy_sort(t_list **stack_a, t_list **stack_b, int size);
void	ft_biggy_sort(t_list **stack_a, t_list **stack_b);

/*      BIGGY SORT         */

void	ft_best_elems(t_list **stack_a, t_list **stack_b);
int		ft_seek_elem_b(t_list **stack_a, t_list **stack_b, int pos_a);
int		ft_best_b(t_list *stack_b, int value);
int		ft_count_smallest_nbr(t_list *stack_b, int ref);
int		ft_bigger_nbr(int *tab, int size);
int		ft_count_op(t_list *stack_a, t_list *stack_b, int a, int b);
int		ft_count_up_down(int a, int b);
int		ft_count_all(int a_up, int b_up, int a_down, int b_down);
void	ft_reset_best(t_list **stack_a, t_list **stack_b);
void	ft_setup_best(t_list **stack_a, t_list **stack_b, int a, int b);
void	ft_do_instructions(t_list **stack_a, t_list **stack_b);
void	ft_setup_up(t_list *stack_a, t_list *stack_b, int pos_a, int pos_b);
void	ft_setup_down(t_list *stack_a, t_list *stack_b, int a_down, int b_down);
void	ft_setup_all(t_list *stack_a, t_list *stack_b, int a_down, int b_down);
void	ft_reset_all_var(t_list *elem_a, t_list *elem_b);
void	ft_fill_stack(t_list **stack_a, t_list **stack_b);
void	ft_fill_tab(t_list *stack, int *tab, int size);
void	ft_move_min(t_list **stack);
int		ft_seek_couple(int *tab, int a, int b);
void	ft_move_best(t_list **stack, int value);
void	ft_sort_stack(t_list **stack);

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
t_list	*ft_best_to_elem(t_list *stack);
int		ft_pos(t_list *stack);
void	ft_double_up(t_list **stack_a, t_list **stack_b, t_list *a, t_list *b);
void	ft_double_down(t_list **stack_a, t_list **stack_b, t_list *a, t_list*b);
void	ft_do_up_down(t_list **stack_a, t_list **stack_b, t_list *a, t_list *b);

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
