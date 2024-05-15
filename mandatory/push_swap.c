/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:36 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/15 16:42:09 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_less(t_stack **stack_a)
{
	int	one;
	int	tow;
	int	three;

	one = (*stack_a)->num;
	tow = (*stack_a)->next->num;
	three = (*stack_a)->next->next->num;
	if (one > tow && tow > three)
	{
		sab(stack_a, 1);
		rrab(stack_a, 1);
	}
	else if (one < three && three < tow)
	{
		sab(stack_a, 1);
		rab(stack_a, 1);
	}
	else if (one > three && three > tow)
		rab(stack_a, 1);
	else if (one < three && three > tow)
		sab(stack_a, 1);
	else if (one > three && three < tow)
		rrab(stack_a, 1);
}

static void	sort_min(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	lowest;

	if (size == 3)
	{
		if (!check_is_sorted(*stack_a))
			sort_less(stack_a);
		while (*stack_b)
			pab(stack_a, stack_b, 1);
		return ;
	}
	lowest = lowest_value(*stack_a);
	if (check_is_sorted(*stack_a) && !(*stack_b))
		(free_stack(*stack_a), exit(EXIT_SUCCESS));
	if ((*stack_a)->num == lowest)
		pab(stack_b, stack_a, 2);
	else if (!get_position(*stack_a, lowest))
		rab(stack_a, 1);
	else
		rrab(stack_a, 1);
	sort_min(stack_a, stack_b, size_stack(*stack_a));
}

static void	sort_quick(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		pivot;

	longest_in_sub(*stack_a, size);
	while (!check_is_sorted(*stack_a))
	{
		if (check_is_sub(*stack_a))
			break ;
		pivot = (lowest_value(*stack_a) + biggest_value(*stack_a)) / 2;
		if ((*stack_a)->sub)
			rab(stack_a, 1);
		if (!(*stack_a)->sub)
			pab(stack_b, stack_a, 2);
		if ((*stack_b)->num < pivot)
			rab(stack_b, 2);
	}
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		lowest;

	size = size_stack(*stack_a);
	if (size == 2)
	{
		sab(stack_a, 1);
		return ;
	}
	if (size <= 5)
	{
		sort_min(stack_a, stack_b, size);
		return ;
	}
	sort_quick(stack_a, stack_b, size);
	while (*stack_b)
		best_move(stack_a, stack_b);
	lowest = lowest_value(*stack_a);
	while ((*stack_a)->num != lowest)
	{
		if (!get_position(*stack_a, lowest))
			rab(stack_a, 1);
		else
			rrab(stack_a, 1);
	}
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
	if (!stack_a)
		return (EXIT_FAILURE);
	if (check_is_sorted(stack_a))
		return (free_stack(stack_a), EXIT_SUCCESS);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	return (EXIT_SUCCESS);
}
