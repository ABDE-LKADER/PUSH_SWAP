/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:54 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/26 12:10:42 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rab(t_stack **stack, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (size_stack(*stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print == 1)
		ft_printf("ra\n");
	if (print == 2)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rab(stack_a, 0);
	rab(stack_b, 0);
	ft_printf("rr\n");
}

void	rrab(t_stack **stack, int print)
{
	t_stack	*head;
	t_stack	*last;

	if (size_stack(*stack) < 2)
		return ;
	last = *stack;
	while (last->next->next)
		last = last->next;
	head = last->next;
	last->next = NULL;
	head->next = *stack;
	*stack = head;
	if (print == 1)
		ft_printf("rra\n");
	if (print == 2)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrab(stack_a, 0);
	rrab(stack_b, 0);
	ft_printf("rrr\n");
}
