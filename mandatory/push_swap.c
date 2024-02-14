/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/14 20:34:14 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less(t_stack **stack_a)
{
	int	one;
	int	tow;
	int	three;

	one = (*stack_a)->value;
	tow = (*stack_a)->next->value;
	three = (*stack_a)->next->next->value;
	if (one > tow && tow > three)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (one < three && three < tow)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (one > three && three > tow)
		ra(stack_a, 1);
	else if (one < three && three > tow)
		sa(stack_a, 1);
	else if (one > three && three < tow)
		rra(stack_a, 1);
}

void	sort_more(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int lowest;

	lowest = lowest_value(*stack_a);
	index = get_position(*stack_a, lowest);
	if ((*stack_a)->value == lowest)
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->value == lowest)
		sa(stack_a, 1);
	else if (!index)
		ra(stack_a, 1);
	else if (index)
		rra(stack_a, 1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	if (size_stack(*stack_a) == 2)
	{
		sa(stack_a, 1);
		return ;
	}
	while (!check_is_sorted(*stack_a))
	{
		len = size_stack(*stack_a);
		if (len == 3)
		{
			sort_less(stack_a);
			break ;
		}
		sort_more(stack_a, stack_b);
	}
	sort_back(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac == 1)
		return (EXIT_SUCCESS);
	check_in(ac, av);
	stack_a = parce_in(ac, av);
	if (check_is_sorted(stack_a))
		return (EXIT_SUCCESS);
	sort_stack(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
