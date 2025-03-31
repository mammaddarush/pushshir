
#include "push_swap.h"


// void	sa(t_stack **stack_a, char *str)
// {
// 	t_stack	*stack_t;
// 	int		tmp;
// 	int		index;

// 	if (!stack_a ||!(*stack_a)->next)
// 		return ;
// 	stack_t = *stack_a;
// 	ft_putstr_fd(str, 1);
// 	tmp = stack_t->data;
// 	index = stack_t->index;
// 	stack_t->data = stack_t->next->data;
// 	stack_t->next->data = tmp;
// 	stack_t->index = stack_t->next->index;
// 	stack_t->next->index = index;
// }
void	stack_op(t_stack **a, t_stack **b, char *str, int op)
{
	t_stack	*t;
	int		tmp[2];

	if ((op == 0 && (!a || !(*a)->next)) || (op == 1 &&  !(*b)))
		return ;
	ft_putstr_fd(str, 1);
	if (op == 0)
	{
		t = *a;
		tmp[0] = t->data;
		tmp[1] = t->index;
		t->data = t->next->data;
		t->next->data = tmp[0];
		t->index = t->next->index;
		t->next->index = tmp[1];
	}
	else if (op == 1)
	{
		t = *b;
		*b = (*b)->next;
		t->next = *a;
		*a = t;
	}
}
// stack_op(&a, &b, "sa\n", 0);  // sa(&a, "sa\n")
// stack_op(&a, &b, "pa\n", 1);  // pa(&a, &b, "pa\n")

// void	pa(t_stack **stack_a, t_stack **stack_b, char *str)
// {
// 	t_stack	*stack_tmp;

// 	if (!(*stack_b))
// 		return ;
// 	stack_tmp = *stack_b;
// 	ft_putstr_fd(str, 1);
// 	*stack_b = (*stack_b)->next;
// 	stack_tmp->next = *stack_a;
// 	*stack_a = stack_tmp;
// }





// void	rra(t_stack **stack_a, char *str)
// {
// 	t_stack	*stack_t;
// 	t_stack	*new_stack;
// 	t_stack	*last_node;

// 	stack_t = *stack_a;
// 	if (!stack_t || !stack_t->next)
// 		return ;
// 	ft_putstr_fd(str, 1);
// 	while (stack_t->next)
// 	{
// 		last_node = stack_t;
// 		stack_t = stack_t->next;
// 	}
// 	new_stack = stack_t;
// 	last_node->next = NULL;
// 	new_stack->next = *stack_a;
// 	*stack_a = new_stack;
// }


// void	ra(t_stack **stack_a, char *str)
// {
// 	t_stack	*stack_t;

// 	if (!stack_a)
// 		return ;
// 	stack_t = *stack_a;
// 	ft_putstr_fd(str, 1);
// 	while (stack_t->next)
// 	{
// 		sa(&stack_t, "");
// 		stack_t = stack_t->next;
// 	}
// }
// rot(&a, 0, "ra\n");   // ra(&a, "ra\n")
// rot(&a, 1, "rra\n");  // rra(&a, "rra\n")
void	rot(t_stack **s, char *str, int r)
{
	t_stack	*t1;
	t_stack	*t2;
	t_stack	*t3;

	if ((r==0 && !s) ||(r==1 && (!*s || !(*s)->next)))
		return ;
	ft_putstr_fd(str, 1);
	t1 = *s;
	if (r==0)
		while (t1->next)
				{
					stack_op(&t1,&t1, "",0);
					t1 = t1->next;
				}					
	else if (r==1)
	{
		while (t1->next && (t2 = t1))
			t1 = t1->next;
		t3 = t1;
		t3->next = *s;
		*s = t3;
		t2->next = NULL;
	}
}
