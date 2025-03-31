
#include "push_swap.h"

int	sort_checker(t_stack **stack_a)
{
	t_stack	*stack_t;

	if (!stack_a || !(*stack_a)->next)
		return (0);
	stack_t = *stack_a;
	while (stack_t->next)
	{
		if (stack_t->data > stack_t->next->data)
			return (0);
		stack_t = stack_t->next;
	}
	return (1);
}

int	valid_num(int args, char **argv)
{
	long long	n;
	int			i;
	int			j;

	i = 1;
	while (i < args)
	{
		j = 0;
		n = ft_atoi(argv[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			// if (ft_isdigit(argv[i][j]) == 0)
			if ((argv[i][j]) < '0' || (argv[i][j]) > '9')			
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sorted_args(int args, char **argv)
{
	int	i;
	int	current;
	int	next;

	if (args < 3)
		return (1);
	i = 1;
	while (i < (args - 1))
	{
		current = ft_atoi(argv[i]);
		next = ft_atoi(argv[i + 1]);
		if (current > next)
			return (0);
		i++;
	}
	return (1);
}

int	dup_checker(int args, char **argv)
{
	int	i;
	int	j;
	int	n;
	int	c;

	if (args < 3)
		return (0);
	i = 1;
	j = 0;
	n = 0;
	c = 0;
	while (i < args)
	{
		c = ft_atoi(argv[i]);
		j = i + 1;
		while (j < args)
		{
			n = ft_atoi(argv[j]);
			if (n == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int args, char **argv)
{
	if (dup_checker(args, argv) == 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	else if (valid_num(args, argv) == 0)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	else if (sorted_args(args, argv) == 1)
		return (0);
	return (1);
}
