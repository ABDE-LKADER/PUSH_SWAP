/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:10:25 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/19 15:20:28 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	last_value(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->num);
}

static int	set_top(t_stack *stack, int num)
{
	int		min;
	int		last;
	int		fisrt;
	int		second;

	(1) && (last = last_value(stack), min = lowest_value(stack));
	while (stack->next)
	{
		fisrt = stack->num;
		second = stack->next->num;
		if (num > fisrt && num < second)
			return (second);
		if (num < fisrt && num > last)
			return (fisrt);
		stack = stack->next;
	}
	return (min);
}

static int	get_moves(t_stack *stack_a, int num)
{
	int		top;
	int		moves;
	t_stack	*loop;

	(1) && (moves = 0, loop = stack_a, top = set_top(stack_a, num));
	while (loop->num != top)
	{
		moves++;
		loop = loop->next;
	}
	if (get_position(stack_a, top))
		moves = size_stack(stack_a) - moves;
	return (moves);
}

static int	best_val(t_stack *stack_a, t_stack *stack_b, t_stack *head_b)
{
	int		size;
	int		moves;
	int		index;
	int		bestval;
	int		bestmove;

	(1) && (index = 0, size = size_stack(stack_b),
		bestmove = size + size_stack(stack_a));
	while (stack_b)
	{
		moves = get_moves(stack_a, stack_b->num);
		if (get_position(head_b, stack_b->num))
			moves += (size - index);
		else
			moves += index;
		if (moves < bestmove)
		{
			bestmove = moves;
			bestval = stack_b->num;
		}
		stack_b = stack_b->next;
		index++;
	}
	return (bestval);
}

void	best_move(t_stack **stack_a, t_stack **stack_b)
{
	int		top;
	int		bestval;

	bestval = best_val(*stack_a, *stack_b, *stack_b);
	top = set_top(*stack_a, bestval);
	while ((*stack_a)->num != top || (*stack_b)->num != bestval)
	{
		if ((*stack_b)->num != bestval && !get_position(*stack_b, bestval)
			&& (*stack_a)->num != top && !get_position(*stack_a, top))
			rr(stack_a, stack_b);
		else if ((*stack_b)->num != bestval && get_position(*stack_b, bestval)
			&& (*stack_a)->num != top && get_position(*stack_a, top))
			rrr(stack_a, stack_b);
		else if ((*stack_b)->num != bestval && !get_position(*stack_b, bestval))
			rab(stack_b, 2);
		else if ((*stack_b)->num != bestval && get_position(*stack_b, bestval))
			rrab(stack_b, 2);
		else if ((*stack_a)->num != top && !get_position(*stack_a, top))
			rab(stack_a, 1);
		else if ((*stack_a)->num != top && get_position(*stack_a, top))
			rrab(stack_a, 1);
	}
	pab(stack_a, stack_b, 1);
}
