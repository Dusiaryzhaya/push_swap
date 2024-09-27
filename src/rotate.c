/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:03:02 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/26 16:16:00 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ra(t_stack **head_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (head_a == NULL || *head_a == NULL || (*head_a)->next == NULL)
	{
		return ;
	}
	tmp = *head_a;
	*head_a = (*head_a)->next;
	(*head_a)->prev = NULL;
	last = *head_a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	ft_printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one

void	rb(t_stack **head_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (head_b == NULL || *head_b == NULL || (*head_b)->next == NULL)
	{
		return ;
	}
	tmp = *head_b;
	*head_b = (*head_b)->next;
	(*head_b)->prev = NULL;
	last = *head_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	ft_printf("rb\n");
}

// rr : ra and rb at the same time

void	rr(t_stack **head_a, t_stack **head_b)
{
	ra(head_a);
	rb(head_b);
	ft_printf("rr\n");
}
