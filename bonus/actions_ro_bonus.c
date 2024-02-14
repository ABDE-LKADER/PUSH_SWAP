/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ro_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:52 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/19 17:27:27 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rab(t_stack **stack)
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
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rab(stack_a);
	rab(stack_b);
}

void	rrab(t_stack **stack)
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
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrab(stack_a);
	rrab(stack_b);
}
