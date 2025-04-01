
#include "push_swap.h"

int	verify_digit(int a, char **v)
{
	long long	num1;
	int			i;
	int			j;

	i = 0;
	while (++i < a  )
	{
		num1 = ft_atoi(v[i]);
		if (num1 > 2147483647 || num1 < -2147483648)
			return (0);
		j = (v[i][0] == '-');
		while (v[i][j] && v[i][j] >= '0' && v[i][j] <= '9')
			j++;
		if (v[i][j])
			return (0);
	}
	return (1);
}

void	sort_indx(t_stack **st_a, int i1, int len, int value)
{
	t_stack	*cur;

	if (!(*st_a))
		return ;
	len = stack_node_ops(st_a, 1);
	while (++i1 < len)
	{
		cur = *st_a;
		while (cur->index != -1)
			cur = cur->next;
		value = cur->data;
		cur = *st_a;
		while (cur->next)
		{
			if (value > cur->next->data && cur->next->index == -1)
				value = cur->next->data;
			cur = cur->next;
		}
		cur = *st_a;
		while (cur->data != value)
			cur = cur->next;
		cur->index = i1;
	}
}



int	check_dup(int a, char **v)
{
	int	d[4];

	if (a < 3)
		return (0);
	d[0] = 1;
	while (d[0] < a)
	{
		d[2] = ft_atoi(v[d[0]]);
		d[1] = d[0] + 1;
		while (d[1] < a)
		{
			d[3] = ft_atoi(v[d[1]]);
			if (d[3] == d[2])
				return (1);
			d[1]++;
		}
		d[0]++;
	}
	return (0);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;
	int		params[4];

	size = stack_node_ops(a, 1);
	// 
	params[3] = 0; 
	if (size <= 3)
		do_for_three(a, 1);
	else if (size <= 50)
		{
			params[0] = 0; 
			params[1] = 0;
			params[2] =0; 
			sort_algo_med(a, b, params, 0);
		}	
	else
		{
			params[0] = -1; 
			params[1] = stack_node_ops(a, 0); 
			params[2] = stack_node_ops(a, 1); 
			sort_algo_radix(a, b, params, 1);
		}
}

int	main(int args, char **argv)
{
	t_stack	*s1;
	t_stack	*s2;

	s1 = NULL;
	s2 = NULL;
	if ((check_dup(args, argv) == 1) || (verify_digit(args, argv) == 0))
	{
		is_sort_print(1, NULL, "Error\n", 2);
		// ft_putstr_fd("Error\n", 1);
		return (0);
	}
	if (is_sort_print(args, argv, NULL, 1) == 1)
		return (0);
	build_list(args, argv, &s1);
	sort_indx(&s1, -1, 0, 0);
	sort_stack(&s1, &s2);
	stack_manage(&s1,0,0);
	stack_manage(&s2,0,0);
}


//linux: chmod +x checker_linux && ARG=$(shuf -i 0-10000 -n 500 | tr '\n' ' '); RESULT=$(./push_swap $ARG); echo "$RESULT" | ./checker_linux $ARG && echo "Instruction count: $(echo "$RESULT" | wc -l)"
//Mac: chmod +x checker_Mac && ARG=$(jot -r 500 0 10000 | tr '\n' ' '); RESULT=$(./push_swap $ARG); echo "$RESULT" | ./checker_Mac $ARG && echo "Instruction count: $(echo "$RESULT" | wc -l)"

// for leak check
//linux: chmod +x checker_linux && ARG=$(shuf -i 0-10000 -n 500 | tr '\n' ' '); RESULT=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $ARG); echo "$RESULT" | ./checker_linux $ARG && echo "Instruction count: $(echo "$RESULT" | wc -l)"
//Mac: chmod +x checker_Mac && ARG=$(jot -r 500 0 10000 | tr '\n' ' '); RESULT=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $ARG); echo "$RESULT" | ./checker_Mac $ARG && echo "Instruction count: $(echo "$RESULT" | wc -l)"
// Instruction count: 6784
