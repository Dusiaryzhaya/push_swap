/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:33:57 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/27 13:45:11 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_structnew(long value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
	{
		return (NULL);
	}
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_structadd_back(t_stack **head, long value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = ft_structnew(value);
	if (!new_node)
	{
		return ;
	}
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	last_node = *head;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = new_node;
	new_node->next = NULL;
	new_node->prev = last_node;
}

int	ft_structsize(t_stack *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		head = head->next;
		count++;
	}
	return (count);
}
