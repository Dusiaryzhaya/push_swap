/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:28:19 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/26 16:15:45 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements

void	sa(t_stack **head_a)
{
	t_stack	*first;
	t_stack	*second;

	if (head_a == NULL || *head_a == NULL || (*head_a)->next == NULL)
	{
		return ;
	}
	first = *head_a;
	second = (*head_a)->next;
	first->next = second->next;
	if (second->next != NULL)
	{
		second->next->prev = first;
	}
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*head_a = second;
	ft_printf("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements

void	sb(t_stack **head_b)
{
	t_stack	*first;
	t_stack	*second;

	if (head_b == NULL || *head_b == NULL || (*head_b)->next == NULL)
	{
		return ;
	}
	first = *head_b;
	second = (*head_b)->next;
	first->next = second->next;
	if (second->next != NULL)
	{
		second->next->prev = first;
	}
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*head_b = second;
	ft_printf("sb\n");
}

// ss : sa and sb at the same time.

void	ss(t_stack **head_a, t_stack **head_b)
{
	sa(head_a);
	sb(head_b);
	ft_printf("ss\n");
}

// pa (push a): Take the first element at the top of b and put it
// at the top of a.
// Do nothing if b is empty.

void	pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	if (head_b == NULL || *head_b == NULL)
		return ;
	tmp = *head_b;
	*head_b = (*head_b)->next;
	if (*head_b != NULL)
	{
		(*head_b)->prev = NULL;
	}
	if (*head_a == NULL)
	{
		*head_a = tmp;
		(*head_a)->next = NULL;
		(*head_a)->prev = NULL;
	}
	else
	{
		tmp->next = *head_a;
		(*head_a)->prev = tmp;
		tmp->prev = NULL;
		*head_a = tmp;
	}
	ft_printf("pa\n");
}

// pb (push b): Take the first element at the top of a and put it
// at the top of b.
// Do nothing if a is empty

void	pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	if (head_a == NULL || *head_a == NULL)
		return ;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	if (*head_a != NULL)
	{
		(*head_a)->prev = NULL;
	}
	if (*head_b == NULL)
	{
		*head_b = tmp;
		(*head_b)->next = NULL;
		(*head_b)->prev = NULL;
	}
	else
	{
		tmp->next = *head_b;
		(*head_b)->prev = tmp;
		tmp->prev = NULL;
		*head_b = tmp;
	}
	ft_printf("pb\n");
}
