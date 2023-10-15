/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:04:39 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 13:57:46 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	lstadd_back(t_list **stack, t_list *new)
{
	t_list	*node;

	if (*stack)
	{
		node = lstlast(*stack);
		node->next = new;
	}
	else
		*stack = new;
}

void	print_list(t_list *head)
{
	while (head != NULL)
	{
		ft_putnbr_fd(head->content, 1);
		ft_putendl_fd("", 1);
		head = head->next;
	}
}

int	lstsize(t_list *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
