/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lon_in_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:50:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/25 23:07:53 by abadouab         ###   ########.fr       */
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

static int **set_longest(int **lis, int	size)
{
	int		num;
	int		len;
	int		seq;
	int 	first;
	int 	second;

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
	lis = set_longest(lis, size);
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
	index = 0;
	int	s = size;
	int	s1 = size;
	int	s2 = size;
	ft_printf("NUMBERS >\n");
	while (s--)
	{
		ft_printf("--------> %d \t", lis[0][index]);
		index++;
	}
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("LEN >\n");
	index = 0;
	while (s1--)
	{
		ft_printf("--------> %d \t", lis[1][index]);
		index++;
	}
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("SEQ >\n");
	index = 0;
	while (s2--)
	{
		ft_printf("--------> %d \t", lis[2][index]);
		index++;
	}
	ft_printf("\n");
	ft_printf("\n\n\t\t\t\tSIZE %d \n\n", size);
	index = 0;
	longest = 0;
	while (size--)
	{
		if (lis[1][index] > longest)
			longest = index;
		index++;
	}
	// ft_printf("\n>>>>>>>>>>>>>>>>>>>>>>>>> %d\n", lis[0][longest]);
	ft_printf("\n\n\t\t\t\tLONGEST %d \n\n", index);
	start = 0;
	// set_in_sub(stack, lis[0][start]);
	while (lis[2][longest] != -1)
	{
		set_in_sub(stack, lis[0][longest]);
		ft_printf("\n>>>>>>>>>>>>>>>>>>>>>>>>> %d\n", lis[0][longest]);
		longest = lis[2][longest];
	}
	set_in_sub(stack, lis[0][longest]);
	ft_printf("\n>>>>>>>>>>>>>>>>>>>>>>>>> %d\n", lis[0][longest]);
}
