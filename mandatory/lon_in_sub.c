/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lon_in_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:50:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/25 18:37:57 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

static int **set_longest(int **lis)
{
	int		num;
	int		len;
	int		seq;
	int 	first;
	int 	second;

	(1) && (num = 0, len = 1, seq = 2, first = 0, second = 1);
	while (lis[num][second])
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

static int	**get_longest(t_stack *stack)
{
	int		size;
	int		index;
	int		**lis;

	(1) && (size = size_stack(stack), lis = malloc(3 * sizeof(char **)),
		lis[0] = malloc(size * sizeof(char *)),
		lis[1] = malloc(size * sizeof(char *)),
		lis[2] = malloc(size * sizeof(char *)),
		index = 0);
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
	lis = set_longest(lis);
	return (lis);
}

void longest_in_sub(t_stack *stack)
{
	int		size;
	int		**lis;
	int		start;
	int		index;
	int		longest;

	lis = get_longest(stack);
	(1) && (index = 1, longest = lis[1][0], size = size_stack(stack));
	while (size)
	{
		if (lis[1][index] > longest)
		{
			start = index;
			longest = lis[1][index];
		}
		index++;
		size--;
	}
	set_in_sub(stack, lis[0][start]);
	while (lis[2][longest] != -1)
	{
		set_in_sub(stack, lis[0][longest]);
			ft_printf("L: ------- %d\n", longest);
			ft_printf("I: ------- %d\n", lis[2][longest]);
			ft_printf("N: ------- %d\n", lis[0][longest]);
		longest = lis[2][longest];
	}
	set_in_sub(stack, lis[0][longest]);
}
