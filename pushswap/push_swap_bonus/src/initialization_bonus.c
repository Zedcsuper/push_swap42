/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:13:51 by zjamaien          #+#    #+#             */
/*   Updated: 2025/01/12 14:43:36 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_stack	*fill_stack_values(int ac, char **av, int is_one_str)
{
	t_stack	*stack_a;
	long	nb;
	int		i;

	stack_a = NULL;
	nb = 0;
	if (is_one_str)
		i = 0;
	else
		i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (i == 0 && is_one_str)
			stack_a = stack_new((int)nb);
		else if (i == 1 && !is_one_str)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}


