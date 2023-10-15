/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:18:12 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 20:55:34 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_list **s_a, t_list **s_b)
{
	if (lstsize(*s_a) > 3)
		pb(s_a, s_b);
	if (lstsize(*s_a) > 3)
		pb(s_a, s_b);
	if (lstsize(*s_a) > 3)
		sort_b(s_a, s_b);
	simple_sort(s_a);
	empty_b(s_a, s_b);
	clean_a(s_a);
}

void	simple_sort(t_list **s_a)
{
	int	max;

	max = get_max(s_a);
	if ((*s_a)->content == max)
		ra(s_a);
	else if ((*s_a)->next->content == max)
		rra(s_a);
	if (!is_sorted(s_a))
		sa(s_a);
}

void	sort_b(t_list **s_a, t_list **s_b)
{
	int		n;
	t_moves	move;

	while (lstsize(*s_a) > 5)
	{
		n = best_move(*s_a, *s_b, &move);
		calculate_move(*s_a, *s_b, n, &move);
		do_move(s_a, s_b, &move);
	}
}

void	empty_b(t_list **s_a, t_list **s_b)
{
	int	n;
	int	index_target;

	while (*s_b)
	{
		index_target = find_next_biggest(*s_a, (*s_b)->content);
		n = find_number_from_index(*s_a, index_target);
		if (index_target <= lstsize(*s_a) / 2)
		{
			while ((*s_a)->content != n)
				ra(s_a);
		}
		else
		{
			while ((*s_a)->content != n)
				rra(s_a);
		}
		pa(s_b, s_a);
	}
}

void	clean_a(t_list **s_a)
{
	int	min;

	min = get_min(s_a);
	if (get_index(s_a, min) <= lstsize(*s_a) / 2)
	{
		while ((*s_a)->content != min)
			ra(s_a);
	}
	else
	{
		while ((*s_a)->content != min)
			rra(s_a);
	}
}
