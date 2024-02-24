/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/24 22:44:29 by abadouab         ###   ########.fr       */
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

static void	sort_quick(t_stack **stack_a, t_stack **stack_b)
{
	int		mid;

	while (!check_is_sorted(*stack_a))
	{
		mid = (lowest_value(*stack_a) + biggest_value(*stack_a)) / 2;
		if (!(*stack_a)->sub)
			pab(stack_b, stack_a, 2);
		else if ((*stack_a)->sub)
			rab(stack_a, 1);
		if ((*stack_b)->num < mid)
			rab(stack_b, 2);
	}
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	// t_stack *temp_a = *stack_a;
	if (size_stack(*stack_a) == 2)
	{
		sab(stack_a, 1);
		return ;
	}
	if (size_stack(*stack_a) == 3)
	{
		sort_less(stack_a);
		return ;
	}
	longest_in_sub(*stack_a);
	sort_quick(stack_a, stack_b);
	while (*stack_b)
		best_move(stack_a, stack_b);
	while ((*stack_a)->num != lowest_value(*stack_a))
	{
		if (!get_position(*stack_a, lowest_value(*stack_a)))
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
	if (check_is_sorted(stack_a))
		return (EXIT_SUCCESS);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (EXIT_SUCCESS);
}
