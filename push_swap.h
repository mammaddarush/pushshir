
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
void	ft_putstr_fd(char *s, int fd);
int	stack_node_ops(t_stack **s, int op);
void	stack_manage(t_stack **s, int op, int idx);

// algo1.c
void 	stack_op(t_stack **a, t_stack **b, char *str, int op);
void	rot(t_stack **s, char *str, int r);

//algo2.c
int	do_for_three(t_stack **stack_a, int op);
void	sort_med(t_stack **stack_a, t_stack **stack_b);
void	index_sort(t_stack **stack_a);
void	radix(t_stack **stack_a, t_stack **stack_b);
int		find_smallest(t_stack **stack_a);


#endif
