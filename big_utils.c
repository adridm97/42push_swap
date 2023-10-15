/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:39:33 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 11:47:19 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_move(t_list *s_a, t_list *s_b, t_moves *move)
{
	t_list	*head;
	int		best;
	int		n_moves;
	int		tmp;

	head = s_a;
	n_moves = INT_MAX;
	while (head)
	{
		tmp = calculate_move(s_a, s_b, head->content, move);
		if (tmp < n_moves)
		{
			n_moves = tmp;
			best = head->content;
		}
		head = head->next;
	}
	return (best);
}

void	do_move(t_list **s_a, t_list **s_b, t_moves *move)
{
	while (move->ra--)
		ra(s_a);
	while (move->rb--)
		rb(s_b);
	while (move->rr--)
		rr(s_a, s_b);
	while (move->rra--)
		rra(s_a);
	while (move->rrb--)
		rrb(s_b);
	while (move->rrr--)
		rrr(s_a, s_b);
	pb(s_a, s_b);
}

int	calculate_move(t_list *s_a, t_list *s_b, int n, t_moves *move)
{
	int	size_a;
	int	size_b;
	int	next_smallest;
	int	index;
	int	total;

	init_moves(move);
	size_a = lstsize(s_a);
	size_b = lstsize(s_b);
	next_smallest = find_next_smallest(s_b, n);
	index = get_index(&s_a, n);
	if (index <= size_a / 2)
		move->ra = index;
	else
		move->rra = size_a - index;
	if (index <= size_b / 2)
		move->rb = next_smallest;
	else
		move->rrb = size_b - next_smallest;
	optimize(move);
	total = move->ra + move->rb + move->rr + move->rra + move->rrb + move->rrr;
	return (total);
}

void	init_moves(t_moves *move)
{
	move->ra = 0;
	move->rb = 0;
	move->rr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rrr = 0;
}

void	optimize(t_moves *move)
{
	if (move->ra > move->rb)
	{
		move->rr = move->rb;
		move->ra -= move->rb;
		move->rb = 0;
	}
	else
	{
		move->rr = move->ra;
		move->rb -= move->ra;
		move->ra = 0;
	}
	if (move->rra > move->rrb)
	{
		move->rrr = move->rrb;
		move->rra -= move->rrb;
		move->rrb = 0;
	}
	else
	{
		move->rrr = move->rra;
		move->rrb -= move->rra;
		move->rra = 0;
	}
}
