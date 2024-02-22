/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lon_in_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:50:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/22 15:38:03 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int	check_is_sub(t_stack *stack)
{
	while (stack)
	{
		if (stack->sub == 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int get_longest(t_stack *stack, int num)
{
	int		count;
	t_stack *first;
	t_stack *second;

	count = 0;
	first = stack;
	second = stack->next;
	while (second)
	{   
		if (num < first->num && first->num < second->num)
			count++;
		first = first->next;
		second = second->next;
	}
	return (count);
}

static void set_longest_sub(t_stack *longest)
{
	t_stack *first;
	t_stack *second;

	first = longest;
	second = longest->next;
	while (second)
	{   
		if (longest->num < first->num && first->num < second->num)
			second->sub = 1;
		first = first->next;
		second = second->next;
	}
}

static void set_longest(t_stack *stack)
{
	int count;
	int llong;
	t_stack *loop;
	t_stack *longest;

	count = 0;
	llong = 0;
	loop = stack;
	while (loop)
	{
		loop->sub = 0;
		count = get_longest(stack, loop->num);
		if (count > llong)
		{
			llong = count;
			longest = loop;
		}
		loop = loop->next;
	}
	longest->sub = 1;
	set_longest_sub(longest);
}

void longest_in_sub(t_stack **stack_a, t_stack **stack_b)
{
	set_longest(*stack_a);
	t_stack *temp_a = *stack_a;
	ft_printf("\n---------> START\n");
	while (temp_a)
	{
		ft_printf("NUMBER IS: %d\t\t", temp_a->num);
		ft_printf("SUB IS: %d\n", temp_a->sub);
		temp_a = temp_a->next;
	}
	ft_printf("---------> END\n");
	while (check_is_sub(*stack_a))
	{
		if (((*stack_a)->sub) == 0)
			pab(stack_a, stack_b, 1);
		else
			rab(stack_a, 1);
	}
}
