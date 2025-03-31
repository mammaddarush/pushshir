
#include "push_swap.h"

int	find_smallest(t_stack **stack_a)
{
	t_stack	*stack_t;
	int		data;

	stack_t = *stack_a;
	while (stack_t->index != -1)
		stack_t = stack_t->next;
	data = stack_t->data;
	stack_t = *stack_a;
	while (stack_t->next)
	{
		if (data > stack_t->next->data && stack_t->next->index == -1)
			data = stack_t->next->data;
		stack_t = stack_t->next;
	}
	return (data);
}

void	index_sort(t_stack **stack_a)
{
	t_stack	*stack_t;
	int		i;
	int		size;
	int		data;

	if (!(*stack_a))
		return ;
	size = stack_node_ops(stack_a,1);
	i = 0;
	while (i < size)
	{
		stack_t = *stack_a;
		data = find_smallest(stack_a);
		while (stack_t->data != data)
			stack_t = stack_t->next;
		stack_t->index = i;
		i++;
	}
}

void	sort_three(t_stack **stack_a)
{
	int	index;

	if (!(*stack_a))
		return ;
	index = stack_node_ops(stack_a,2);
	while (!sort_checker(stack_a))
	{
		if ((*stack_a)->index == index)
			ra(stack_a, "ra\n");
		else
			sa(stack_a, "sa\n");
	}
}



void	sort_med(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_t;
	int		i;
	int		count;

	if (!(*stack_a))
		return ;
	i = 0;
	while (stack_node_ops(stack_a,1) > 3)
	{
		stack_t = *stack_a;
		count = 0;
		while (stack_t->index != i)
		{
			count++;
			stack_t = stack_t->next;
		}
		stack_manage(stack_a,1, count);
		pa(stack_b, stack_a, "pb\n");
		i++;
	}
	sort_three(stack_a);
	while (stack_node_ops(stack_b,1))
		pa(stack_a, stack_b, "pa\n");
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_t;
	int		max_bits;
	int		size;
	int		i;
	int		j;

	max_bits = stack_node_ops(stack_a,0);
	size = stack_node_ops(stack_a,1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			stack_t = *stack_a;
			if (((stack_t->index >> i) & 1))
				ra(stack_a, "ra\n");
			else
				pa(stack_b, stack_a, "pb\n");
			j++;
		}
		while (stack_node_ops(stack_b,1))
			pa(stack_a, stack_b, "pa\n");
		i++;
	}
}
