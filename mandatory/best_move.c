/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:10:26 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/20 22:23:10 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_top(t_stack *stack, int num)
{
	int	min;
	int	last;
	int	fisrt;
	int	second;

	last = last_value(stack);
	min = lowest_value(stack);
	while (stack->next)
	{
		fisrt = stack->num;
		second = stack->next->num;
		if (num > fisrt && num < second)
			return (second);
		if (num < fisrt && num > last)
			return (fisrt);
		stack= stack->next;
	}
	return (min);
}

static int	get_moves(t_stack *stack_a, int num, int index)
{
	int		top;
	int		moves;
	t_stack	*loop;

	moves = 0;
	loop = stack_a;
	top = set_top(stack_a, num);
	// ft_printf("\t\t\t\t\tTOP: %d\n", top);
	while (loop->num != top)
	{
		moves++;
		loop = loop->next;
	}
	if (get_position(stack_a, top))
		moves = size_stack(stack_a) - moves;
	while (moves && index)
	{
		moves--;
		index--;
	}
	return (moves);
}

static int	best_val(t_stack *stack_a, t_stack *stack_b, t_stack *head_b)
{
	int		size;
	int		moves;
	int		index;
	int		bestVal;
	int		bestMove;

	index = 0;
	size = size_stack(stack_b);
	bestMove = size_stack(stack_a) + size_stack(stack_b);
	while (stack_b)
	{
		if (!get_position(head_b, stack_b->num))
			moves = get_moves(stack_a, stack_b->num, index);
		else if (get_position(head_b, stack_b->num))
			moves = get_moves(stack_a, stack_b->num, (size - index));
		// ft_printf("\t\t\t\t\tNUMBER: %d\n", stack_b->num);
		// ft_printf("MOVES IN STACK A: %d\n", moves);
		// if (!get_position(stack_b, head_b->num))
		// 	moves += index;
		// else if (get_position(stack_b, head_b->num))
		// 	moves += (size - index);
		moves += index * !get_position(head_b, stack_b->num)
			+ (size - index) * get_position(head_b, stack_b->num);
		// ft_printf("INDEX IN STACK B: %d\n", index);
		// ft_printf("TOTAL MOVES: %d\n", moves);
		if (moves < bestMove)
		{
			bestMove = moves;
			bestVal = stack_b->num;
		}
		// ft_printf("BEST VAL: %d\n", bestVal);
		stack_b = stack_b->next;
		index++;
	}
	return (bestVal);
}

void	best_move(t_stack **stack_a, t_stack **stack_b)
{
	int	top;
	int	bestVal;

	bestVal = best_val(*stack_a, *stack_b, *stack_b);
	top = set_top(*stack_a, bestVal);
	// t_stack *loop_a = *stack_a;
	// t_stack *loop_b = *stack_b;
	// ft_printf("STACK A:");
	// while (loop_a)
	// {
	// 	ft_printf(" %d |-| ", loop_a->num);
	// 	loop_a = loop_a->next;
	// }
	// ft_printf("\n");
	// ft_printf("STACK B:");
	// while (loop_b)
	// {
	// 	ft_printf(" %d |-| ", loop_b->num);
	// 	loop_b = loop_b->next;
	// }
	// ft_printf("\n");
	while ((*stack_a)->num != top || (*stack_b)->num != bestVal)
	{
		if ((*stack_b)->num != bestVal && !get_position(*stack_b, bestVal)
				&& (*stack_a)->num != top && !get_position(*stack_a, top))
			rr(stack_a, stack_b);
		else if ((*stack_b)->num != bestVal && get_position(*stack_b, bestVal)
				&& (*stack_a)->num != top && get_position(*stack_a, top))
			rrr(stack_a, stack_b);
		else if ((*stack_b)->num != bestVal && !get_position(*stack_b, bestVal))
			rab(stack_b, 2);
		else if ((*stack_b)->num != bestVal && get_position(*stack_b, bestVal))
			rrab(stack_b, 2);
		else if ((*stack_a)->num != top && !get_position(*stack_a, top))
			rab(stack_a, 1);
		else if ((*stack_a)->num != top && get_position(*stack_a, top))
			rrab(stack_a, 1);
	}
	pab(stack_a, stack_b, 1);
}
