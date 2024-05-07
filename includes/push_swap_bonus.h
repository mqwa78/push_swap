/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:43:38 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 04:42:09 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

/*     LIST_MANIPULATIONS  */

t_list	*ft_create_element(int value);
void	ft_list_push_back(t_list **begin_list, int value);
t_list	*ft_last_elem(t_list *begin_list);
t_list	*ft_before_last_elem(t_list *begin_list);
int		ft_list_size(t_list *begin_list);
t_bool	ft_isdoublon(t_list **stack_a, int value);
t_bool	ft_lst_is_sort(t_list *stack_a);

/*      CHECKER             */

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_seek(t_list **stack_a, t_list **stack_b, char *line);
int		ft_seek2(t_list **stack_a, t_list **stack_b, char *line);
void	ft_check_line(t_list **a, t_list **b, char *line);
void	ft_checker(t_list **stack_a, t_list **stack_b);
char	*ft_gnl(int fd);
char	*ft_read(int fd, char *line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);

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
