
#include "push_swap.h"

void	sa(t_stack **stack_a, char *str)
{
	t_stack	*stack_t;
	int		tmp;
	int		index;

	if (!stack_a ||!(*stack_a)->next)
		return ;
	stack_t = *stack_a;
	ft_putstr_fd(str, 1);
	tmp = stack_t->data;
	index = stack_t->index;
	stack_t->data = stack_t->next->data;
	stack_t->next->data = tmp;
	stack_t->index = stack_t->next->index;
	stack_t->next->index = index;
}

void	pa(t_stack **stack_a, t_stack **stack_b, char *str)
{
	t_stack	*stack_tmp;

	if (!(*stack_b))
		return ;
	stack_tmp = *stack_b;
	ft_putstr_fd(str, 1);
	*stack_b = (*stack_b)->next;
	stack_tmp->next = *stack_a;
	*stack_a = stack_tmp;
}

void	ra(t_stack **stack_a, char *str)
{
	t_stack	*stack_t;

	if (!stack_a)
		return ;
	stack_t = *stack_a;
	ft_putstr_fd(str, 1);
	while (stack_t->next)
	{
		sa(&stack_t, "");
		stack_t = stack_t->next;
	}
}

void	rra(t_stack **stack_a, char *str)
{
	t_stack	*stack_t;
	t_stack	*new_stack;
	t_stack	*last_node;

	stack_t = *stack_a;
	if (!stack_t || !stack_t->next)
		return ;
	ft_putstr_fd(str, 1);
	while (stack_t->next)
	{
		last_node = stack_t;
		stack_t = stack_t->next;
	}
	new_stack = stack_t;
	last_node->next = NULL;
	new_stack->next = *stack_a;
	*stack_a = new_stack;
}
