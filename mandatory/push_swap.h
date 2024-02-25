/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:34 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/25 16:39:53 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mylib.h"
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				num;
	int				sub;
	int				top;
	struct s_stack	*next;
}	t_stack;

void	message_error(void);
long	ft_atol(const char *str);
void	check_in(int ac, char **av);
void	check_double(t_stack *stack);
int		check_is_sorted(t_stack *stack);

int		size_stack(t_stack *stack);
t_stack	*parce_in(int ac, char **av);
void	add_num(t_stack **stack, char *value);

void	free_stack(t_stack *stack);
int		check_is_sub(t_stack *stack);
int		last_value(t_stack *stack_a);
int		biggest_value(t_stack *stack);
int		lowest_value(t_stack *stack_a);
void	longest_in_sub(t_stack *stack);
int		get_position(t_stack *stack, int find);
void	best_move(t_stack **stack_a, t_stack **stack_b);

void	sab(t_stack **stack, int print);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pab(t_stack **stack_to, t_stack **stack_from, int print);

void	rab(t_stack **stack, int print);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrab(t_stack **stack, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
