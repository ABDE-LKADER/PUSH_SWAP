/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:22 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/13 22:19:43 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}

void	sort_back(t_stack **stack_a, t_stack **stack_b)
{
	if (!size_stack(*stack_b))
		return ;
	while (*stack_b)
		pa(stack_a, stack_b);
}

int	last_value(t_stack *stack_a)
{
	while (stack_a->next)
		stack_a = stack_a->next;
	return (stack_a->value);
}

int	lowest_value(t_stack *stack)
{
	int lowest;

	lowest = stack->value;
	while (stack)
	{
		if (stack->value < lowest)
			lowest = stack->value;
		stack = stack->next;
	}
	return (lowest);
}

int	get_position(t_stack *stack, int lowest)
{
	size_t	index;

	index = 0;
	while (index <= size_stack(stack) / 2)
	{
		if (stack->value == lowest)
			return (0);
		stack = stack->next;
		index++;
	}
	return (1);
}
