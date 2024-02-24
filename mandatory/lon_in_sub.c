/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lon_in_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:50:45 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/24 22:44:30 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	check_is_sub(t_stack *stack)
{
	while (stack)
	{
		if (!stack->sub)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// static int get_longest(t_stack *stack, int num)
// {
// 	int		count;
// 	t_stack *first;
// 	t_stack *second;

	
// 	count = 0;
// 	first = stack;
// 	second = stack->next;
// 	while (second)
// 	{
// 		if (num < first->num && first->num < second->num)
// 			count++;
// 		first = first->next;
// 		second = second->next;
// 	}
// 	return (count);
// }

// static void set_longest_sub(t_stack *longest)
// {
// 	t_stack *first;
// 	t_stack *second;

// 	first = longest;
// 	second = longest->next;
// 	while (second)
// 	{   
// 		if (longest->num < first->num && first->num < second->num)
// 			second->sub = 1;
// 		first = first->next;
// 		second = second->next;
// 	}
// }

// static void set_longest(t_stack *stack)

static void set_longest(t_stack *stack)
{
	int		index;
	t_stack *loop;
	t_stack *first;
	t_stack *second;

	loop = stack;
	while (loop)
	{
		loop->len = 1;
		loop->lis = -1;
		loop = loop->next;
	}
	first = stack;
	second = stack->next;
	while (second)
	{
		index = 0;
		first = stack;
		while (first != second)
		{
			if (first->num < second->num && (first->len + 1) >= second->len)
			{
				second->len = first->len + 1;
				second->lis = index;	
			}
			first = first->next;
			index++;
		}
		second = second->next;
	}
}

void longest_in_sub(t_stack *stack)
{
	set_longest(stack);
	// t_stack *temp_a = *stack_a;
	// ft_printf("\n---------> START\n");
	// while (temp_a)
	// {
	// 	ft_printf("NUMBER IS: %d\t\t", temp_a->num);
	// 	ft_printf("LIS IS: %d\t\t", temp_a->lis);
	// 	ft_printf("LEN IS: %d\n", temp_a->len);
	// 	temp_a = temp_a->next;
	// }
	// ft_printf("---------> END\n");
}
