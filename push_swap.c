
#include "push_swap.h"

int	main(int args, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_args(args, argv))
		return (0);
	build_list(args, argv, &stack_a);
	index_sort(&stack_a);
	if (stack_node_ops(&stack_a,1) <= 3)
		sort_three(&stack_a);
	else if (stack_node_ops(&stack_a,1) <= 50)
		sort_med(&stack_a, &stack_b);
	else
		radix(&stack_a, &stack_b);
	stack_manage(&stack_a,0,0);
	stack_manage(&stack_b,0,0);
}

// chmod +x checker_linux && ARG=$(shuf -i 0-10000 -n 500 | tr '\n' ' '); RESULT=$(./push_swap $ARG); echo "$RESULT" | ./checker_linux $ARG && echo "Instruction count: $(echo "$RESULT" | wc -l)"
// Instruction count: 6784