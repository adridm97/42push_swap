/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:20:27 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/15 20:31:37 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = 0;
	while (args[i])
	{
		new = lstnew(ft_atoi(args[i]));
		lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		ft_free_(args);
}

void	sort_stack(t_list **s_a, t_list **s_b)
{
	if (lstsize(*s_a) == 2)
		sa(s_a);
	else
		big_sort(s_a, s_b);
}

int	main(int argc, char **argv)
{
	t_list	*s_a;
	t_list	*s_b;
	int		min;

	s_a = NULL;
	s_b = NULL;
	if (argc < 2)
		return (-1);
	if (argv[2] == 0)
		ft_error("Error");
	ft_check_args(argc, argv);
	init_stack(&s_a, argc, argv);
	min = get_min(&s_a);
	get_index(&s_a, min);
	if (is_sorted(&s_a))
	{
		free_stack(s_a);
		return (0);
	}
	sort_stack(&s_a, &s_b);
	return (0);
}
