/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:52 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/17 22:46:30 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (size_stack(*stack_a) < 2)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (size_stack(*stack_b) < 2)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	ra(stack_b, 0);
	ft_printf("rr\n");
}

void	rra(t_stack **stack_a, int print)
{
	t_stack	*head;
	t_stack	*last;

	if (size_stack(*stack_a) < 2)
		return ;
	last = *stack_a;
	while (last->next->next)
		last = last->next;
	head = last->next;
	last->next = NULL;
	head->next = *stack_a;
	*stack_a = head;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int print)
{
	t_stack	*head;
	t_stack	*last;

	if (size_stack(*stack_b) < 2)
		return ;
	last = *stack_b;
	while (last->next->next)
		last = last->next;
	head = last->next;
	last->next = NULL;
	head->next = *stack_b;
	*stack_b = head;
	if (print)
		ft_printf("rrb\n");
}
