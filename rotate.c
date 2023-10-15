/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:42:08 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 14:26:24 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **stack)
{
	t_list	*tmp;

	if (lstsize(*stack) < 2)
		return (-1);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	lstlast(*stack)->next = tmp;
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **stack)
{
	t_list	*tmp;

	if (lstsize(*stack) < 2)
		return (-1);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	lstlast(*stack)->next = tmp;
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **s_a, t_list **s_b)
{
	t_list	*tmp;

	if (lstsize(*s_a) < 2 || lstsize(*s_b) < 2)
		return (-1);
	tmp = *s_a;
	*s_a = (*s_a)->next;
	tmp->next = NULL;
	lstlast(*s_a)->next = tmp;
	tmp = *s_b;
	*s_b = (*s_b)->next;
	tmp->next = NULL;
	lstlast(*s_b)->next = tmp;
	ft_putendl_fd("rr", 1);
	return (0);
}
