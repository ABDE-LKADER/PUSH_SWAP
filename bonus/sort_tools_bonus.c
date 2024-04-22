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

int	check_is_sorted(t_stack *stack)
{
	t_stack	*check;

	while (stack)
	{
		check = stack->next;
		while (check)
		{
			if (stack->num > check->num)
				return (0);
			check = check->next;
		}
		stack = stack->next;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	num;

	(1) && (i = 0, sign = 1, num = 0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + str[i] - 48;
		i++;
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			message_error(NULL, 0);
	}
	return (num * sign);
}
