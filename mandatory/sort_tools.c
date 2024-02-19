/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:22 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/19 13:30:20 by abadouab         ###   ########.fr       */
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
	int lowest;

	lowest = stack->num;
	while (stack)
	{
		if (stack->num < lowest)
			lowest = stack->num;
		stack = stack->next;
	}
	return (lowest);
}

int	get_position(t_stack *stack, int find)
{
	int	index;

	index = 0;
	while (index < size_stack(stack) / 2)
	{
		if (stack->num == find)
			return (0);
		stack = stack->next;
		index++;
	}
	return (1);
}
