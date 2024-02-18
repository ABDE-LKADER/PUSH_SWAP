/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:56 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/18 15:08:26 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_stack **stack, int print)
{
	t_stack	*temp;

	if (size_stack(*stack) < 2)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	if (print == 1)
		ft_printf("sa\n");
	if (print == 2)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sab(stack_a, 0);
	sab(stack_b, 0);
	ft_printf("ss\n");
}

void	pab(t_stack **stack_to, t_stack **stack_from, int print)
{
	t_stack	*new;

	if (!*stack_from)
		return ;
	new = *stack_from;
	*stack_from = (*stack_from)->next;
	new->next = *stack_to;
	*stack_to = new;
	if (print == 1)
		ft_printf("pa\n");
	if (print == 2)
		ft_printf("pb\n");
}
