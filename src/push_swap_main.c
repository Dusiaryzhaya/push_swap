/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:35:03 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/27 12:45:24 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// commands:
// ARG="1 5 2 4 3" && ./push_swap $ARG | ./checker_linux $ARG
// ARG="1 5 2 4 3" && ./push_swap $ARG | wc -l

// debug function

// void	ft_lstprint(t_stack *head)
// {
// 	t_stack	*current;

// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("list value: %d\n", current->value);
// 		current = current->next;
// 	}
// }

int	is_sorted(t_stack *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	main_process(t_stack **head)
{
	int		len;
	t_stack	*cur;
	int		case_num;

	case_num = 0;
	if (is_sorted(*head) == 1)
	{
		return ;
	}
	len = ft_structsize(*head);
	cur = *head;
	if (len <= 3)
	{
		sorting_3(head, len);
	}
	else if (len > 3 && len <= 5)
	{
		sorting_5(head, len);
	}
	else
	{
		sorting_more_then_5(head, len);
	}
}

int	main(int argc, char *argv[])
{
	int				total_count;
	t_argument_data	arg_data;
	t_stack			*head;

	head = NULL;
	check_argc(argc);
	total_count = count_total_numbers(argc, argv);
	arg_data.buffer = malloc(sizeof(int) * total_count);
	if (!arg_data.buffer)
		return (1);
	arg_data.buffer_size = 0;
	arg_data.error_flag = 0;
	if (main_checker(argc, argv, &arg_data))
	{
		free(arg_data.buffer);
		return (1);
	}
	fill_stack_with_buffer(arg_data.buffer, arg_data.buffer_size, &head);
	free(arg_data.buffer);
	main_process(&head);
	ft_structclear(&head);
	return (0);
}
