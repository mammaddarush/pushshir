
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct t_stack
{
	int				data;
	int				index;
	struct t_stack	*next;
}	t_stack;

// stack_managing.c
void	build_list(int argc, char **arguments, t_stack **head);
long long	ft_atoi(char *str);
int	stack_node_ops(t_stack **s, int op);
void	stack_manage(t_stack **s, int op, int idx);
int	is_sort_print(int a, char **v, char *str1, int op);



//algo2.c
void 	stack_op(t_stack **a, t_stack **b, char *str, int op);
void	rot(t_stack **s, char *str, int r);
int	do_for_three(t_stack **stack_a, int op);
void	sort_algo_med(t_stack **a, t_stack **b,int params[4], int algo);
void	sort_algo_radix(t_stack **a, t_stack **b,int params[4], int algo);


#endif
