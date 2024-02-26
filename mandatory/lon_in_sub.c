/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lon_in_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:50:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/26 13:27:51 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sub(t_stack *stack)
{
	while (stack)
	{
		if (!stack->sub)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_in_sub(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->num == num)
		{
			stack->sub = 1;
			return ;
		}
		stack = stack->next;
	}
}

static int	**set_longest(int **lis, int size)
{
	int		num;
	int		len;
	int		seq;
	int		first;
	int		second;

	(1) && (num = 0, len = 1, seq = 2, second = 1);
	while (size--)
	{
		first = 0;
		while (first != second)
		{
			if (lis[num][first] < lis[num][second] && \
				(lis[len][first] + 1) >= lis[len][second])
			{
				lis[len][second] = lis[len][first] + 1;
				lis[seq][second] = first;
			}
			first++;
		}
		second++;
	}
	return (lis);
}

static int	**get_longest(t_stack *stack, int size)
{
	int		index;
	int		**lis;

	size--;
	(1) && (index = 0, lis = malloc(3 * sizeof(char **)),
		lis[0] = malloc(size * sizeof(char *)),
		lis[1] = malloc(size * sizeof(char *)),
		lis[2] = malloc(size * sizeof(char *)));
	while (stack)
	{
		stack->top = 0;
		stack->sub = 0;
		lis[0][index] = stack->num;
		lis[1][index] = 1;
		lis[2][index] = -1;
		stack = stack->next;
		index++;
	}
	return (lis = set_longest(lis, size));
}

void	longest_in_sub(t_stack *stack, int size)
{
	int		**lis;
	int		check;
	int		index;
	int		longest;

	(1) && (index = 0, check = 0, lis = get_longest(stack, size));
	while (size--)
	{
		if (lis[1][index] > check)
		{
			longest = index;
			check = lis[1][index];
		}
		index++;
	}
	while (lis[2][longest] != -1)
	{
		set_in_sub(stack, lis[0][longest]);
		longest = lis[2][longest];
	}
	index = 3;
	while (--index >= 0)
		free(lis[index]);
	free(lis);
}
