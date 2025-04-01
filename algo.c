
#include "push_swap.h"



void	stack_op(t_stack **a, t_stack **b, char *str, int op)
{
	t_stack	*t;
	int		tmp[2];

	if ((op == 0 && (!a || !(*a)->next)) || (op == 1 &&  !(*b)))
		return ;
	is_sort_print(1, NULL, str, 2);
	// ft_putstr_fd(str, 1);
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


// rot(&a, 0, "ra\n");   // ra(&a, "ra\n")
// rot(&a, 1, "rra\n");  // rra(&a, "rra\n")
void	rot(t_stack **s, char *str, int r)
{
	t_stack	*t1;
	t_stack	*t2;
	t_stack	*t3;

	if ((r==0 && !s) ||(r==1 && (!*s || !(*s)->next)))
		return ;
	is_sort_print(1, NULL, str, 2);
	// ft_putstr_fd(str, 1);
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


void	sort_algo_med(t_stack **a, t_stack **b,int params[4], int algo)
{
	t_stack	*cur;

	if (!(*a))
		return ;
	while ((algo == 0 && stack_node_ops(a, 1) > 3 && (cur = *a)) )
	{
		params[3]=0;	
		while (cur->index != params[0] && ++params[3])
				cur = cur->next;
		stack_manage(a, 1, params[3]);
		if (algo == 0)
			stack_op(b, a, "pb\n", 1);
		++params[0];
	}
	if (algo == 0)
		do_for_three(a, 1);
	while (stack_node_ops(b, 1))
		stack_op(a, b, "pa\n", 1);
}

void	sort_algo_radix(t_stack **a, t_stack **b,int params[4], int algo)
{
	t_stack	*cur;

	while ( ++params[0] < params[1])
	{
		params[3]=-1 ; // j
		while (++params[3] < params[2])
		{
			if (algo == 1 )
				cur = *a;
			if (((cur->index >> params[0]) & 1))
				rot(a, "ra\n", 0);
			else
				stack_op(b, a, "pb\n", 1);
		}
		while (stack_node_ops(b, 1))
			stack_op(a, b, "pa\n", 1);
	}
}
