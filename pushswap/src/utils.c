/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:16:10 by zjamaien          #+#    #+#             */
/*   Updated: 2025/01/05 17:02:15 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	ft_strlen(char *s1)
{
	int	i;
	while (*s1)
	{
		s1++;
		i++;
	}
	return (i);
}



/* here try to git rid of !a */
void	exit_error(t_stack **a, t_stack **b)
{
	if (!a || *a != NULL)
		free_stack(a);
	if (!b || *b != NULL)
		free_stack(b);
	write(2, "Error\n", 6);
	exit (1);
}

long	ft_atoi(const char *str)
{
	long	nb;
	int		isneg;
	int		i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
/*
int	main()
{
	printf("%ld\n", ft_atoi("0000001"));
}
*/
