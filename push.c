/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:12:27 by aduenas-          #+#    #+#             */
/*   Updated: 2023/09/25 22:32:43 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **s_b, t_list **s_a)
{
	t_list	*tmp;

	if (lstsize(*s_b) == 0)
		return (-1);
	tmp = *s_b;
	*s_b = (*s_b)->next;
	if (!s_a)
	{
		*s_a = tmp;
		tmp->next = NULL;
	}
	tmp->next = *s_a;
	*s_a = tmp;
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **s_a, t_list **s_b)
{
	t_list	*tmp;

	if (lstsize(*s_a) == 0)
		return (-1);
	tmp = *s_a;
	*s_a = (*s_a)->next;
	if (!s_b)
	{
		*s_b = tmp;
		tmp->next = NULL;
	}
	tmp->next = *s_b;
	*s_b = tmp;
	ft_putendl_fd("pb", 1);
	return (0);
}
