/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:21 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/19 17:13:06 by abadouab         ###   ########.fr       */
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

int	size_stack(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
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
