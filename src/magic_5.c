/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:23:08 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/26 16:15:24 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Moves the first len ​​- 3 elements from stack A to stack B.
// Then sorts the remaining three elements in stack A.

void	first_move_and_sort(t_stack **head_a, t_stack **head_b, int len)
{
	int	i;

	i = 0;
	while (i < len - 3 && *head_a != NULL)
	{
		pb(head_a, head_b);
		i++;
	}
	sorting_3(head_a, 3);
}

// Calculates how many rotations are needed to move an element
// from stack B to stack A and rotate stack_a.

void	calculate_and_rotate(t_stack **head_a, t_stack **head_b)
{
	t_rotations	rotations;
	int			rotate;
	int			r_rotate;
	int			len;

	len = ft_structsize(*head_a);
	rotations = calculate_pos(head_a, *head_b, len);
	select_min_count(rotations, len, &rotate, &r_rotate);
	if (rotate > 0)
	{
		rotate_forward(head_a, rotate);
	}
	else if (r_rotate > 0)
	{
		rotate_backward(head_a, r_rotate);
	}
}

// Restores the order of elements in stack A by rotating
// it until the minimum element is on top.

void	restore_position_a(t_stack **head_a, int min_index)
{
	int	count_ra;
	int	count_rra;

	count_ra = 0;
	count_rra = 0;
	calculate_rotations_to_restore(*head_a, min_index, &count_ra, &count_rra);
	if (count_ra <= count_rra)
	{
		while ((*head_a)->index != min_index)
		{
			ra(head_a);
		}
	}
	else
	{
		while ((*head_a)->index != min_index)
		{
			rra(head_a);
		}
	}
}

// The main function for sorting a stack of 5 elements.
// Moves some elements to stack B, sorts stack A and gradually
// moves elements back from stack B, restoring order in stack A.

void	sorting_5(t_stack **head_a, int len)
{
	t_stack	*head_b;
	int		min_index;
	int		*stack_c;

	head_b = NULL;
	stack_c = create_stack_c(head_a, len);
	sort_stack_c(stack_c, len);
	assign_indexes(head_a, stack_c, len);
	free(stack_c);
	first_move_and_sort(head_a, &head_b, len);
	while (head_b != NULL)
	{
		calculate_and_rotate(head_a, &head_b);
		pa(head_a, &head_b);
		if (head_b != NULL && (*head_a)->index == head_b->index + 1)
		{
			pa(head_a, &head_b);
		}
		min_index = find_min_index(*head_a);
		if ((*head_a)->index != min_index)
		{
			restore_position_a(head_a, min_index);
		}
	}
}
