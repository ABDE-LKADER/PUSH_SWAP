/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:35 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/18 15:13:43 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "mylib.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

long	ft_atol(const char *str);
void	check_in(int ac, char **av);
int		check_is_sorted(t_stack *stack);
void	message_error(t_stack *stack, int free);

int		size_stack(t_stack *stack);
void	free_stack(t_stack *stack);
t_stack	*parce_in(int ac, char **av);

void	sab(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pab(t_stack **stack_to, t_stack **stack_from);

void	rab(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrab(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
