/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:42:33 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 15:51:55 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list **stack)
{
	int		min;
	t_list	*head;

	head = (*stack);
	min = head->content;
	while (head->next)
	{
		head = head->next;
		if (head->content < min)
			min = head->content;
	}
	return (min);
}

int	get_max(t_list **stack)
{
	int		max;
	t_list	*head;

	head = *stack;
	max = head->content;
	while (head->next)
	{
		head = head->next;
		if (head->content > max)
			max = head->content;
	}
	return (max);
}

int	get_index(t_list **stack, int n)
{
	int		index;
	t_list	*head;

	index = 0;
	head = *stack;
	while (head->next != NULL && head->content != n)
	{
		head = head->next;
		index++;
	}
	return (index);
}
