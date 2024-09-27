/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:28:25 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/26 16:08:38 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// case 1: 2 1 3
// case 2: 1 3 2
// case 3: 3 1 2
// case 4: 2 3 1
// case 5: 3 2 1

void	perform_operations(t_stack **head, int case_num)
{
	if (case_num == 1)
	{
		sa(head);
	}
	else if (case_num == 2)
	{
		sa(head);
		ra(head);
	}
	else if (case_num == 3)
	{
		ra(head);
	}
	else if (case_num == 4)
	{
		rra(head);
	}
	else if (case_num == 5)
	{
		sa(head);
		rra(head);
	}
}

int	get_case(t_stack **head)
{
	t_stack	*cur;
	int		a;
	int		b;
	int		c;

	cur = *head;
	a = cur->value;
	b = cur->next->value;
	c = cur->next->next->value;
	if (a > b && b < c && a < c)
		return (1);
	else if (a < b && b > c && a < c)
		return (2);
	else if (a > b && b < c && a > c)
		return (3);
	else if (a < b && b > c && a > c)
		return (4);
	else if (a > b && b > c)
		return (5);
	return (0);
}

void	sorting_3(t_stack **head, int len)
{
	int	case_num;

	if (len == 3)
	{
		case_num = get_case(head);
		if (case_num != 0)
		{
			perform_operations(head, case_num);
		}
		return ;
	}
	else if (len == 2)
	{
		if ((*head)->value > (*head)->next->value)
		{
			sa(head);
		}
		return ;
	}
	else
	{
		return ;
	}
}
