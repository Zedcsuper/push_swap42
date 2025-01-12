/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:36:05 by zjamaien          #+#    #+#             */
/*   Updated: 2025/01/12 14:36:34 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

static int	is_overflow(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i++] - '0');
		if ((!sign && res > INT_MAX) || (sign && - res < INT_MIN))
			return (1);
	}	
	return (0);
}

static int	have_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if ((j != i) && (ft_atoi(av[i]) == ft_atoi(av[j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_correct_input(char **av, int is_one_str)
{
	int	i;

	if (is_one_str)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]) || is_overflow(av[i]))
			return (0);
		i++;
	}
	if (have_duplicate(av))
		return (0);
	return (1);
}
