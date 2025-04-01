

#include "push_swap.h"




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
				rot(s, "ra\n",0);
		else
			while (idx++ < count)
				rot(s, "rra\n",1);
	}
}


int is_sort_print(int a, char **v, char *str1, int op) 
{
    int nums[3]; // nums[0] = i1, nums[1] = c, nums[2] = n
  
    if (op == 2) 
    {
        while (*str1) 
            write(a, str1++, 1);
        return (1);
    } 
    else if (op == 1)
    {
        if (a < 3)
            return (1);
        nums[0] = 1;
        while (nums[0] < a - 1 )
        {
            nums[1] = ft_atoi(v[nums[0]]);
			nums[2] = ft_atoi(v[nums[0] + 1]);
			if (nums[1] > nums[2])
				return (0);
			nums[0]++;
        }
        return (1);
    }
    return (0);
}


// int is_sort_print(int a, char **v, char *str1, int op) 
// {
// 	int i1;
// 	int c;
// 	int n;
  
// 	if (op == 2) 
// 	{
// 	  while (*str1) 
// 		write(a, str1++, 1);
// 	  return (1);
// 	} 
// 	else if (op == 1)
// 	 {
// 	  if (a < 3)
// 		return (1);
// 	  i1 = 1;
// 	  while (i1 < a - 1 && (c = ft_atoi(v[i1])) <= (n = ft_atoi(v[i1 + 1])))
// 		{
// 			i1++;
// 		}
// 	  if (i1 == a - 1)
// 		return (1);
// 	  else
// 		return (0);
// 	}
// 	return (0);
// }






// int	is_sort_print(int a, char **v, char *str1, int op)
// {
// 	int	i1;

// 	if (op == 2)
// 			while (*str1)
// 				write(a, str1++, 1);
// 	else if (op == 1)
// 	{
// 		if (a < 3)
// 			return (1);
// 		i1 = 1;
// 		while (i1 < a - 1 )
// 		{
// 			if (( ft_atoi(v[i1])) <= ( ft_atoi(v[i1 + 1])))
// 				i1++;
// 		}		
// 		if (i1 == a - 1)
// 			return (1);
// 		else
// 			return (0);
// 	}
// 	return (0);
// }





