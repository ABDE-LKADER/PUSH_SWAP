/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/26 11:55:28 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_stack(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	free_stack(t_stack *stack)
{
	t_stack	*loop;

	if (!stack)
		return ;
	while (stack)
	{
		loop = stack->next;
		free(stack);
		stack = loop;
	}
}

void	check_double(t_stack *stack)
{
	t_stack	*head;
	t_stack	*temp;

	head = stack;
	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->num == temp->num)
				message_error(head, 1);
			temp = temp->next;
		}
		stack = stack->next;
	}
}

void	add_num(t_stack **stack, char *value)
{
	t_stack	*node;
	t_stack	*new;

	if (!stack)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->num = ft_atol(value);
	new->next = NULL;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	node = *stack;
	while (node->next)
		node = node->next;
	node->next = new;
}

t_stack	*parce_in(int ac, char **av)
{
	t_stack	*stack;
	char	**spn;
	int		i;
	int		j;

	i = 1;
	stack = NULL;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			j = 0;
			spn = ft_split(av[i], ' ');
			while (spn[j])
			{
				add_num(&stack, spn[j]);
				free(spn[j++]);
			}
			free(spn);
		}
		else
			add_num(&stack, av[i]);
		i++;
	}
	return (check_double(stack), stack);
}
