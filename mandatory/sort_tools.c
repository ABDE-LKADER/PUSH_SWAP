/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:22 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/26 11:45:35 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_value(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->num);
}

int	lowest_value(t_stack *stack)
{
	int		lowest;

	lowest = stack->num;
	while (stack)
	{
		if (stack->num < lowest)
			lowest = stack->num;
		stack = stack->next;
	}
	return (lowest);
}

int	biggest_value(t_stack *stack)
{
	int		biggest;

	biggest = stack->num;
	while (stack)
	{
		if (stack->num > biggest)
			biggest = stack->num;
		stack = stack->next;
	}
	return (biggest);
}

int	get_position(t_stack *stack, int find)
{
	int		size;
	int		index;

	index = 0;
	size = size_stack(stack);
	while (index <= size / 2)
	{
		if (stack->num == find)
			return (0);
		stack = stack->next;
		index++;
	}
	return (1);
}
