/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:49:51 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 14:25:33 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (lstsize(*stack) < 2)
		return (-1);
	tail = lstlast(*stack);
	head = *stack;
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (lstsize(*stack) < 2)
		return (-1);
	tail = lstlast(*stack);
	head = *stack;
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **s_a, t_list **s_b)
{
	t_list	*head;
	t_list	*tail;

	if (lstsize(*s_a) > 1)
	{
		head = lstlast(*s_a);
		tail = *s_a;
		while (tail->next->next)
			tail = tail->next;
		tail->next = NULL;
		head->next = *s_a;
		*s_a = head;
	}
	if (lstsize(*s_b) > 1)
	{
		head = lstlast(*s_b);
		tail = *s_b;
		while (tail->next->next)
			tail = tail->next;
		tail->next = NULL;
		head->next = *s_b;
		*s_b = head;
	}
	ft_putendl_fd("rrr", 1);
	return (0);
}
