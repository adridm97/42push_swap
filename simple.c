/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:50:15 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 18:55:08 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **s_a, t_list **s_b)
{
	int	size;

	size = lstsize(*s_a);
	if (size == 2)
		sa(s_a);
	else if (size == 3)
		sort_three(s_a);
	else if (size == 4)
		sort_four(s_a, s_b);
	else if (size == 5)
		sort_five(s_a, s_b);
}

void	sort_three(t_list **s_a)
{
	int	min;
	int	index;

	min = get_min(s_a);
	index = get_index(s_a, min);
	if (index == 2)
	{
		if ((*s_a)->content > (*s_a)->next->content)
			sa(s_a);
		rra(s_a);
	}
	else if (index == 1)
	{
		rra(s_a);
		if ((*s_a)->content > (*s_a)->next->content)
			sa(s_a);
		rra(s_a);
	}
	else if (!is_sorted(s_a))
	{
		ra(s_a);
		sa(s_a);
		rra(s_a);
	}
}

void	sort_four(t_list **s_a, t_list **s_b)
{
	int	min;
	int	index;

	min = get_min(s_a);
	index = get_index(s_a, min);
	while (index != 0)
	{
		if (index > 1)
		{
			index = index % 2;
			if (index == 0)
			{
				rra(s_a);
				index = get_index(s_a, min);
			}
			rra(s_a);
			index = 0;
		}
		else if (index == 1)
			ra(s_a);
		index = 0;
	}
	pb(s_a, s_b);
	sort_three(s_a);
	pa(s_b, s_a);
}

void	sort_five(t_list **s_a, t_list **s_b)
{
	int	min;
	int	index;

	min = get_min(s_a);
	index = get_index(s_a, min);
	while (index != 0 && index > 2)
	{
		if (index > 2)
		{
			rra(s_a);
			index = get_index(s_a, min);
		}
		if (index == 4)
			rra(s_a);
		index = get_index(s_a, min);
	}
	while (index != 0)
	{
		ra(s_a);
		index = get_index(s_a, min);
	}
	pb(s_a, s_b);
	sort_four(s_a, s_b);
	pa(s_b, s_a);
}
