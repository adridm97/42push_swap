/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:50:57 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 18:42:44 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_smallest(t_list *stack, int n)
{
	int	index;
	int	max;
	int	index_next;
	int	value;

	index = 0;
	max = get_max(&stack);
	if (n < get_min(&stack) || n > max)
		index_next = get_index(&stack, max);
	else
	{
		value = INT_MIN;
		while (stack)
		{
			if (stack->content < n && stack->content > value)
			{
				value = stack->content;
				index_next = index;
			}
			index++;
			stack = stack->next;
		}
	}
	return (index_next);
}

int	find_next_biggest(t_list *stack, int n)
{
	int	index;
	int	max;
	int	min;
	int	index_next;
	int	value;

	index = 0;
	value = INT_MAX;
	max = get_max(&stack);
	min = get_min(&stack);
	if (n > max)
		return (get_index(&stack, min));
	while (stack)
	{
		if (stack->content > n && stack->content < value)
		{
			value = stack->content;
			index_next = index;
		}
		index++;
		stack = stack->next;
	}
	return (index_next);
}

int	find_number_from_index(t_list *stack, int index)
{
	while (index)
	{
		index--;
		stack = stack->next;
	}
	return (stack->content);
}
