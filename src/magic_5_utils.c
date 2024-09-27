/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_5_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:33:33 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/26 14:58:45 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Performs the specified number of forward rotations of stack A.

void	rotate_forward(t_stack **head_a, int rotate_a)
{
	while (rotate_a != 0)
	{
		ra(head_a);
		rotate_a--;
	}
}

// Performs the specified number of backward rotations of stack A,

void	rotate_backward(t_stack **head_a, int r_rotate_a)
{
	while (r_rotate_a != 0)
	{
		rra(head_a);
		r_rotate_a--;
	}
}

// Calculates how many rotations need to be performed to insert element 
// from stack B into the correct position in stack A.
// If the element has an index greater than the maximum index in stack A,
// then the element must be moved to the end of the stack,
//	and the number of rotations required to do so is returned.
// If the element is smaller than the current element in the stack,
//	the necessary rotations are determined.

t_rotations	calculate_pos(t_stack **head, t_stack *elem, int len)
{
	t_rotations	rotations;
	t_stack		*cur;
	int			turn;

	turn = 0;
	cur = *head;
	rotations.rotate = 0;
	rotations.r_rotate = 0;
	while (cur != NULL)
	{
		if (elem->index < cur->index)
		{
			rotations.rotate = turn;
			rotations.r_rotate = len - turn;
			return (rotations);
		}
		cur = cur->next;
		turn++;
	}
	rotations.rotate = 0;
	rotations.r_rotate = len;
	return (rotations);
}

// Selects the minimum number of rotations between forward 
// rotation and reverse rotation

void	select_min_count(t_rotations rotations, int len, int *rotate,
		int *r_rotate)
{
	*rotate = rotations.rotate;
	*r_rotate = rotations.r_rotate;
	if (*rotate > len / 2)
	{
		*r_rotate = len - *rotate;
		*rotate = 0;
	}
	else
	{
		*r_rotate = 0;
	}
}

// Calculates the number of rotations to restore the position of the 
// minimum element on the top of stack A.

void	calculate_rotations_to_restore(t_stack *head_a, int min_index,
		int *count_ra, int *count_rra)
{
	t_stack	*tmp;
	int		len;

	tmp = head_a;
	len = ft_structsize(head_a);
	while (tmp != NULL && tmp->index != min_index)
	{
		tmp = tmp->next;
		(*count_ra)++;
	}
	*count_rra = len - *count_ra;
}
