

#include "push_swap.h"

// void	append_stack(t_stack **stack_a, int value)
// {
// 	t_stack	*stack_t;

// 	stack_t = *stack_a;
// 	if (!stack_t)
// 	{
// 		*stack_a = malloc(sizeof(t_stack));
// 		(*stack_a)->data = value;
// 		(*stack_a)->index = -1;
// 		(*stack_a)->next = NULL;
// 	}
// 	else
// 	{
// 		while (stack_t->next)
// 			stack_t = stack_t->next;
// 		stack_t->next = malloc(sizeof(t_stack));
// 		stack_t->next->data = value;
// 		stack_t->next->index = -1;
// 		stack_t->next->next = NULL;
// 	}
// }

// void	create_stack(int args, char **argv, t_stack **stack_a)
// {
// 	int	i;

// 	i = 1;
// 	while (i < args)
// 	{
// 		append_stack(stack_a, ft_atoi(argv[i]));
// 		i++;
// 	}
// }


void	build_list(int argc, char **arguments, t_stack **head)
{
	t_stack	*temp;
	int		count;

	count = 0;
	while (++count < argc)
	{
		if (!*head)
		{
			*head = malloc(sizeof(t_stack));
			temp = *head;
		}
		else
		{
			temp = *head;
			while (temp->next)
				temp = temp->next;
			temp->next = malloc(sizeof(t_stack));
			temp = temp->next;
		}
		temp->data = ft_atoi(arguments[count]);
		temp->index = -1;
		temp->next = NULL;
	}
}



long long	ft_atoi(char *str)
{
	long long	res1;
	int			vals[2];

	res1 = 0;
	vals[0] = 0;  
	vals[1] = 0; 
	while (str[vals[0]] == ' ' || str[vals[0]] == '\n' || str[vals[0]] == '\t' || \
		str[vals[0]] == '\v' || str[vals[0]] == '\f' || str[vals[0]] == '\r')
		vals[0]++;
	if (str[vals[0]] == '+' || str[vals[0]] == '-')
	{
		if (str[vals[0]] == '-')
			vals[1] = 1;
		vals[0]++;
	}
	while (str[vals[0]] >= '0' && str[vals[0]] <= '9')
	{
		if (vals[1])
			res1 = res1 * 10 + (str[vals[0]] - 48) * -1;
		else
			res1 = res1 * 10 + (str[vals[0]] - 48);
		vals[0]++;
	}
	return (res1);
}

void	ft_putstr_fd(char *str1, int fd)
{
	while (*str1)
	{
		write(fd, str1, 1);
		str1++;
	}
}


// int	biggest_index(t_stack **stack_a)
// {
// 	t_stack	*stack_t;
// 	int		index;

// 	stack_t = *stack_a;
// 	index = stack_t->index;
// 	while (stack_t->next)
// 	{
// 		if (index < stack_t->next->index)
// 			index = stack_t->next->index;
// 		stack_t = stack_t->next;
// 	}
// 	return (index);
// }




// int	max_index_bits(t_stack **stack_a)
// {
// 	int	index;
// 	int	max;

// 	if (!(*stack_a))
// 		return (0);
// 	index = count_nodes(stack_a) - 1;
// 	max = 0;
// 	while (index >> max)
// 		max++;
// 	return (max);
// }

// int	stack_node_ops(t_stack **s, int op)
// {
// 	t_stack	*t;
// 	int		cnt1;
// 	int		mxbit;

// 	if (!s || !*s)
// 		return (0);
// 	t = *s;
// 	cnt1 = 0;
// 	mxbit = 0;
// 	while (t && ++cnt1)
// 		t = t->next;
// 	if (op)
// 		return (cnt1);
// 	while ((cnt1 - 1) >> mxbit)
// 		mxbit++;
// 	return (mxbit);
// }
int	stack_node_ops(t_stack **s, int op)
{
	t_stack	*t;
	int		v[3];

	if (!s || !*s)
		return (0);
	t = *s;
	v[0] = 0;
	v[1] = t->index;
	v[2] = 0;
	while (t && (op != 2 || t->next))
	{
		if (op == 2 && t->next && t->next->index > v[1])
			v[1] = t->next->index;
		v[0] += (op != 2);
		t = t->next;
	}
	if (op == 2)
		return (v[1]);
	if (op == 1)
		return (v[0]);
	while ((v[0] - 1) >> v[2])
		v[2]++;
	return (v[2]);
}
// int	count_nodes(t_stack **stack_a)
// {
// 	t_stack	*stack_t;
// 	int		count;

// 	if (!(*stack_a))
// 		return (0);
// 	stack_t = *stack_a;
// 	count = 0;
// 	while (stack_t)
// 	{
// 		stack_t = stack_t->next;
// 		count++;
// 	}
// 	return (count);
// }

// void	free_stack(t_stack **stack)
// {
// 	t_stack	*current;
// 	t_stack	*next;

// 	current = *stack;
// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		free(current);
// 		current = next;
// 	}
// 	*stack = NULL;
// }
void	stack_manage(t_stack **s, int op, int idx)
{
	t_stack	*cur1;
	t_stack	*nxt1;
	int		count;

	if (op == 0)
	{
		cur1 = *s;
		while (cur1 != NULL)
		{
			nxt1 = cur1->next;
			free(cur1);
			cur1 = nxt1;
		}
		*s = NULL;
	}
	else
	{
		count = stack_node_ops(s, 1);
		if (idx <= (count >> 1))
			while (idx-- > 0)
				ra(s, "ra\n");
		else
			while (idx++ < count)
				rra(s, "rra\n");
	}
}

// void	bring_top(t_stack **stack_a, int index)
// {
// 	if (index <= (stack_node_ops(stack_a,1) >> 1))
// 	{
// 		while (index-- > 0)
// 			ra(stack_a, "ra\n");
// 	}
// 	else
// 	{
// 		while (index++ < stack_node_ops(stack_a,1))
// 			rra(stack_a, "rra\n");
// 	}
// }

