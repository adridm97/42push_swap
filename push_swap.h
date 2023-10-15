/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:32:39 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 20:37:48 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_moves;

void	ft_check_args(int argc, char **argv);
void	ft_error(char *msg);
void	ft_free_(char **str);
t_list	*lstnew(int content);
t_list	*lstlast(t_list *head);
void	lstadd_back(t_list **stack, t_list *new);
void	print_list(t_list *head);
int		lstsize(t_list *stack);
void	free_stack(t_list *stack);
int		is_sorted(t_list **stack);
int		sa(t_list **stack);
int		sb(t_list **stack);
int		ss(t_list **s_a, t_list **s_b);
int		pa(t_list **s_b, t_list **s_a);
int		pb(t_list **s_a, t_list **s_b);
int		ra(t_list **stack);
int		rb(t_list **stack);
int		rr(t_list **s_a, t_list **s_b);
int		rra(t_list **stack);
int		rrb(t_list **stack);
int		rrr(t_list **s_a, t_list **s_b);
int		get_min(t_list **stack);
int		get_max(t_list **stack);
int		get_index(t_list **stack, int n);
void	big_sort(t_list **s_a, t_list **s_b);
void	simple_sort(t_list **s_a);
void	sort_b(t_list **s_a, t_list **s_b);
int		best_move(t_list *s_a, t_list *s_b, t_moves *move);
int		calculate_move(t_list *s_a, t_list *s_b, int n, t_moves *move);
void	init_moves(t_moves *move);
void	optimize(t_moves *move);
int		find_next_smallest(t_list *stack, int n);
int		find_next_biggest(t_list *stack, int n);
void	do_move(t_list **s_a, t_list **s_b, t_moves *move);
int		find_number_from_index(t_list *stack, int index);
void	empty_b(t_list **s_a, t_list **s_b);
void	clean_a(t_list **s_a);
#endif
