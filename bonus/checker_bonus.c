/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/19 17:27:23 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_actions(t_stack **stack_a, t_stack **stack_b,  t_list	*ops, char *input)
{
	int	len;

	len = ft_strlen(input);
	if (!ft_strncmp("sa\n", input, len) || !ft_strncmp("sb\n", input, len)
		|| !ft_strncmp("ss\n", input, len) || !ft_strncmp("pa\n", input, len)
		|| !ft_strncmp("pb\n", input, len) || !ft_strncmp("ra\n", input, len)
		|| !ft_strncmp("rb\n", input, len) || !ft_strncmp("rr\n", input, len)
		|| !ft_strncmp("rra\n", input, len) || !ft_strncmp("rrb\n", input, len)
		|| !ft_strncmp("rrr\n", input, len))
		return ;
	free(input);
	ft_lstclear(&ops, free);
	free_stack(*stack_a);
	free_stack(*stack_b);
	message_error();
}

static void	do_actions(t_stack **stack_a, t_stack **stack_b, char *input)
{
	int	len;

	len = ft_strlen(input);
	if (!ft_strncmp("sa\n", input, len))
		sab(stack_a);
	else if (!ft_strncmp("sb\n", input, len))
		sab(stack_b);
	else if (!ft_strncmp("ss\n", input, len))
		ss(stack_a, stack_b);
	else if (!ft_strncmp("pa\n", input, len))
		pab(stack_a, stack_b);
	else if (!ft_strncmp("pb\n", input, len))
		pab(stack_b, stack_a);
	else if (!ft_strncmp("ra\n", input, len))
		rab(stack_a);
	else if (!ft_strncmp("rb\n", input, len))
		rab(stack_b);
	else if (!ft_strncmp("rr\n", input, len))
		rr(stack_a, stack_b);
	else if (!ft_strncmp("rra\n", input, len))
		rrab(stack_a);
	else if (!ft_strncmp("rrb\n", input, len))
		rrab(stack_b);
	else if (!ft_strncmp("rrr\n", input, len))
		rrr(stack_a, stack_b);
}

static void	ft_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*op;
	t_list	*ops;
	t_list	*tmp;

	ops = NULL;
	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		check_actions(stack_a, stack_b, ops, op);
		tmp = ft_lstnew(op);
		ft_lstadd_back(&ops, tmp);
	}
	while (ops)
	{
		tmp = ops->next;
		do_actions(stack_a, stack_b, ops->content);
		ft_lstdelone(ops, free);
		ops = tmp;
	}
	if (check_is_sorted(*stack_a) && !size_stack(*stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac == 1)
		return (EXIT_SUCCESS);
	check_in(ac, av);
	stack_a = parce_in(ac, av);
	ft_checker(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (EXIT_SUCCESS);
}
