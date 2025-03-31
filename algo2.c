
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
// int	sort_checker(t_stack **stack_a)
// {
// 	t_stack	*stack_t;

// 	if (!stack_a || !(*stack_a)->next)
// 		return (0);
// 	stack_t = *stack_a;
// 	while (stack_t->next)
// 	{
// 		if (stack_t->data > stack_t->next->data)
// 			return (0);
// 		stack_t = stack_t->next;
// 	}
// 	return (1);
// }



// void	sort_three(t_stack **stack_a)
// {
// 	int	index;

// 	if (!(*stack_a))
// 		return ;
// 	index = stack_node_ops(stack_a,2);
// 	while (!sort_checker(stack_a))
// 	{
// 		if ((*stack_a)->index == index)
// 			rot(stack_a, "ra\n",0);
// 		else
// 		stack_op(stack_a, stack_a, "sa\n",0);
// 	}
// }

int	do_for_three(t_stack **s, int op)
{
	t_stack	*t;
	int		idx;

	if (((op == 0) && (!s || !(*s)->next)) || (op == 1 && !(*s)))
			return (0);
	if (op == 0)
	{
		t = *s;
		while (t->next)
		{
			if (t->data > t->next->data)
				return (0);
			t = t->next;
		}
		return (1);
	}
	idx = stack_node_ops(s, 2);
	while (!do_for_three(s, 0))
	{
		if ((*s)->index == idx)
			rot(s, "ra\n", 0);
		else
			stack_op(s, s, "sa\n", 0);
	}
	return (1);
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
		stack_op(stack_b, stack_a, "pb\n",1);
		i++;
	}
	do_for_three(stack_a,1);
	while (stack_node_ops(stack_b,1))
	stack_op(stack_a, stack_b, "pa\n",1);
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
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			stack_t = *stack_a;
			if (((stack_t->index >> i) & 1))
				rot(stack_a, "ra\n",0);
			else
			stack_op(stack_b, stack_a, "pb\n",1);
		}
		while (stack_node_ops(stack_b,1))
		stack_op(stack_a, stack_b, "pa\n",1);
	}
}

