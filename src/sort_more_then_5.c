/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_then_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:06:34 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/27 13:11:50 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates the number of bits required to represent
// the maximum index in binary.

int	max_index_to_binary(int max_index)
{
	int	count;

	count = 0;
	if (max_index == 0)
		return (1);
	while (max_index != 0)
	{
		max_index = max_index / 2;
		count++;
	}
	return (count);
}

// The main part of the Radix Sort method. Iterates through the index
// bits of each stack element and sorts them depending on the bit values:
// if the bit is 0, the element is moved to stack B; if it is 1,
// stack A is rotated.

void	radix_sort(t_stack **head_a, t_stack **head_b, int max_bits)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (i < max_bits)
	{
		size = ft_structsize(*head_a);
		j = 0;
		while (j < size)
		{
			if ((((*head_a)->index >> i) & 1) == 0)
				pb(head_a, head_b);
			else
				ra(head_a);
			j++;
		}
		while (*head_b)
			pa(head_a, head_b);
		i++;
	}
}

// Sorting function for a stack. First creates an array of element indices,
// sorts it, then assigns each element its index. Then calls main_sort
// to sort using the Radix Sort method.

void	sorting_more_then_5(t_stack **head_a, int len)
{
	int		max_index;
	int		max_bits;
	int		*stack_c;
	t_stack	*head_b;

	head_b = NULL;
	stack_c = create_stack_c(head_a, len);
	sort_stack_c(stack_c, len);
	assign_indexes(head_a, stack_c, len);
	free(stack_c);
	max_index = find_max_index(*head_a);
	max_bits = max_index_to_binary(max_index);
	radix_sort(head_a, &head_b, max_bits);
}
