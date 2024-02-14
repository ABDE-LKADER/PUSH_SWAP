/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:56 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/13 15:25:48 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int print)
{
	t_stack	*temp;

	if (size_stack(*stack_a) < 2)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (size_stack(*stack_b) < 2)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;

	if (!*stack_b)
		return ;
	new = *stack_b;
	*stack_b = (*stack_b)->next;
	new->next = *stack_a;
	*stack_a = new;
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;

	if (!*stack_a)
		return ;
	new = *stack_a;
	*stack_a = (*stack_a)->next;
	new->next = *stack_b;
	*stack_b = new;
	ft_printf("pb\n");
}
