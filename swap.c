/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:22:54 by aduenas-          #+#    #+#             */
/*   Updated: 2023/09/27 22:08:00 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **stack)
{
	t_list	*next;
	int		tmp_val;

	if (lstsize(*stack) < 2)
		return (-1);
	next = (*stack)->next;
	if (!*stack && !next)
	{
		ft_error("Error while Swap s_a");
		return (-1);
	}
	tmp_val = (*stack)->content;
	(*stack)->content = next->content;
	next->content = tmp_val;
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack)
{
	t_list	*next;
	int		tmp_val;

	if (lstsize(*stack) < 2)
		return (-1);
	next = (*stack)->next;
	if (!*stack && !next)
	{
		ft_error("Error while Swap s_b");
		return (-1);
	}
	tmp_val = (*stack)->content;
	(*stack)->content = next->content;
	next->content = tmp_val;
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **s_a, t_list **s_b)
{
	t_list	*next;
	int		tmp_val;

	if (lstsize(*s_a) < 2)
		return (-1);
	next = (*s_a)->next;
	if (!*s_a && !next && !*s_b)
	{
		ft_error("Error while Swap ss");
		return (-1);
	}
	tmp_val = (*s_a)->content;
	(*s_a)->content = next->content;
	next->content = tmp_val;
	next = (*s_b)->next;
	tmp_val = (*s_b)->content;
	(*s_b)->content = next->content;
	next->content = tmp_val;
	ft_putendl_fd("ss", 1);
	return (0);
}
