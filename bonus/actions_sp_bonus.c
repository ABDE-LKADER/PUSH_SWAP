/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:56 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/19 17:27:26 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sab(t_stack **stack)
{
	t_stack	*temp;

	if (size_stack(*stack) < 2)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sab(stack_a);
	sab(stack_b);
}

void	pab(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*new;

	if (!*stack_from)
		return ;
	new = *stack_from;
	*stack_from = (*stack_from)->next;
	new->next = *stack_to;
	*stack_to = new;
}
