/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:18 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/20 12:30:47 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	message_error(t_stack *stack, int free)
{
	if (free)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	empty_check(char *av)
{
	char	*check;

	check = ft_strtrim(av, " ");
	if (!check)
		exit(EXIT_FAILURE);
	if (!*check)
	{
		free(check);
		message_error(NULL, 0);
	}
	free(check);
}

void	check_in(int ac, char **av)
{
	int		i;
	int		j;

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
		empty_check(av[i]);
		ft_atol(av[i++]);
	}
}
