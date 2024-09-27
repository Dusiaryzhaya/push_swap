/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:46:23 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/26 16:16:10 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

void	rra(t_stack **head_a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (head_a == NULL || *head_a == NULL || (*head_a)->next == NULL)
	{
		return ;
	}
	last = *head_a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	before_last = last->prev;
	before_last->next = NULL;
	last->next = *head_a;
	last->prev = NULL;
	(*head_a)->prev = last;
	*head_a = last;
	ft_printf("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

void	rrb(t_stack **head_b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (head_b == NULL || *head_b == NULL || (*head_b)->next == NULL)
	{
		return ;
	}
	last = *head_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	before_last = last->prev;
	before_last->next = NULL;
	last->next = *head_b;
	last->prev = NULL;
	(*head_b)->prev = last;
	*head_b = last;
	ft_printf("rrb\n");
}

// rrr : rra and rrb at the same time.

void	rrr(t_stack **head_a, t_stack **head_b)
{
	rra(head_a);
	rrb(head_b);
	ft_printf("rrr\n");
}
