/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/26 12:39:32 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message_error(t_stack *stack, int free)
{
	if (free)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	free_array(char *av)
{
	char *check;

	check = ft_strtrim(av, " ");
	if (!*check)
	{
		free(check);
		message_error(NULL, 0);
	}
	free(check);
}

int	check_is_sorted(t_stack *stack)
{
	t_stack	*check;

	while (stack)
	{
		check = stack->next;
		while (check)
		{
			if (stack->num > check->num)
				return (0);
			check = check->next;
		}
		stack = stack->next;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	num;

	(1) && (i = 0, sign = 1, num = 0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + str[i] - 48;
		i++;
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			message_error(NULL, 0);
	}
	return (num * sign);
}

void	check_in(int ac, char **av)
{
	int		i;
	int		j;
	char	*check;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((!ft_strchr(" -+0123456789", av[i][j])))
				message_error(NULL, 0);
			else if (ft_strchr("-+", av[i][j]) && !ft_isdigit(av[i][j + 1]))
				message_error(NULL, 0);
			else if (ft_isdigit(av[i][j])
				&& !ft_strchr(" 0123456789", av[i][j + 1]))
				message_error(NULL, 0);
			j++;
		}
		free_array(av[i]);
		ft_atol(av[i++]);
	}
}
