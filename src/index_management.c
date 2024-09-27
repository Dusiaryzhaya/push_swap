/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:40:48 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/26 13:50:22 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_stack_c(t_stack **head, int len)
{
	int		*stack_c;
	t_stack	*cur;
	int		i;

	i = 0;
	cur = *head;
	stack_c = malloc(len * sizeof(int));
	if (!stack_c)
	{
		ft_structclear(head);
		exit(EXIT_FAILURE);
	}
	while (cur != NULL && i < len)
	{
		stack_c[i] = cur->value;
		cur = cur->next;
		i++;
	}
	return (stack_c);
}

void	sort_stack_c(int *stack_c, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		if (stack_c[i] > stack_c[i + 1])
		{
			tmp = stack_c[i];
			stack_c[i] = stack_c[i + 1];
			stack_c[i + 1] = tmp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

void	assign_indexes(t_stack **head, int *stack_c, int len)
{
	t_stack	*cur;
	int		i;

	cur = *head;
	while (cur != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (stack_c[i] == cur->value)
			{
				cur->index = i;
				break ;
			}
			i++;
		}
		cur = cur->next;
	}
}

int	find_min_index(t_stack *head)
{
	int	min_index;

	min_index = INT_MAX;
	while (head != NULL)
	{
		if (head->index < min_index)
		{
			min_index = head->index;
		}
		head = head->next;
	}
	return (min_index);
}

int	find_max_index(t_stack *head)
{
	int	max_index;

	max_index = INT_MIN;
	while (head != NULL)
	{
		if (head->index > max_index)
		{
			max_index = head->index;
		}
		head = head->next;
	}
	return (max_index);
}
