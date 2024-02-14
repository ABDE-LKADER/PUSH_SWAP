/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:34 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/19 17:32:30 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "mylib.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	message_error(void);
long	ft_atol(const char *str);
void	check_in(int ac, char **av);
void	check_double(t_stack *stack);
int		check_is_sorted(t_stack *stack);

size_t	size_stack(t_stack *stack);
t_stack	*parce_in(int ac, char **av);

void	free_stack(t_stack *stack);

void	sab(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pab(t_stack **stack_to, t_stack **stack_from);

void	rab(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrab(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
