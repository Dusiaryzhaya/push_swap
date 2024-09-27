/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:47:42 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/27 12:45:31 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PUSH_SWAP_H
#ifdef PUSH_SWAP_H

# include "../libft/src/ft_printf.h"
# include "../libft/src/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_rotations
{
	int				rotate;
	int				r_rotate;
}					t_rotations;

typedef struct s_argument_data
{
	int				*buffer;
	int				buffer_size;
	int				error_flag;
}					t_argument_data;

/* ************************************************************************** */
/*                               Check args                                   */
/* ************************************************************************** */

int					check_and_convert(char *str, int *error_flag);
int					ft_is_duplicate(int *buffer, int n, int len);
void				is_valid(const char *str, t_argument_data *arg_data);
int					is_splittable(const char *str);
void				check_argc(int argc);
int					*split_and_check(char *str, int *count, int *error_flag);
int					count_total_numbers(int argc, char *argv[]);
int					process_splittable_argument(char *arg, int *buffer,
						int *buffer_size, int *error_flag);
int					main_checker(int argc, char *argv[],
						t_argument_data *arg_data);
void				fill_stack_with_buffer(int *buffer, int buffer_size,
						t_stack **head);

/* ************************************************************************** */
/*                                Error_msg                                   */
/* ************************************************************************** */

void				print_error(const char *msg);

/* ************************************************************************** */
/*                                Cleanup                                     */
/* ************************************************************************** */

void				ft_structclear(t_stack **head);
void				ft_free_arr(char **arr);

/* ************************************************************************** */
/*                             List management                                */
/* ************************************************************************** */

t_stack				*ft_structnew(long value);
void				ft_structadd_back(t_stack **head, long value);
void				ft_structadd_front(t_stack **head, long value);
int					ft_structsize(t_stack *head);

/* ************************************************************************** */
/*                                Push-swap                                   */
/* ************************************************************************** */

void				sa(t_stack **head_a);
void				sb(t_stack **head_b);
void				ss(t_stack **head_a, t_stack **head_b);
void				pa(t_stack **head_a, t_stack **head_b);
void				pb(t_stack **head_a, t_stack **head_b);

/* ************************************************************************** */
/*                                  Rotate                                    */
/* ************************************************************************** */

void				ra(t_stack **head_a);
void				rb(t_stack **head_b);
void				rr(t_stack **head_a, t_stack **head_b);

/* ************************************************************************** */
/*                               Reverse rotate                               */
/* ************************************************************************** */

void				rra(t_stack **head_a);
void				rrb(t_stack **head_b);
void				rrr(t_stack **head_a, t_stack **head_b);

/* ************************************************************************** */
/*                                  Magic 3                                   */
/* ************************************************************************** */

void				sorting_3(t_stack **head, int len);

/* ************************************************************************** */
/*                                  Magic 5                                   */
/* ************************************************************************** */

void				sorting_5(t_stack **head_a, int len);

/* ************************************************************************** */
/*                             Magic 5 utils                                  */
/* ************************************************************************** */

void				rotate_forward(t_stack **head_a, int rotate_a);
void				rotate_backward(t_stack **head_a, int r_rotate_a);
t_rotations			calculate_pos(t_stack **head, t_stack *elem, int len);
void				select_min_count(t_rotations rotations_a, int len_a,
						int *rotate_a, int *r_rotate_a);
void				calculate_rotations_to_restore(t_stack *head_a,
						int min_value, int *count_ra, int *count_rra);

/* ************************************************************************** */
/*                           Sort many elements                               */
/* ************************************************************************** */

void				sorting_more_then_5(t_stack **head_a, int len);

/* ************************************************************************** */
/*                            Index management                                */
/* ************************************************************************** */

int					*create_stack_c(t_stack **head, int len);
void				sort_stack_c(int *stack_c, int len);
void				assign_indexes(t_stack **head, int *stack_c, int len);
int					find_min_index(t_stack *head);
int					find_max_index(t_stack *head);

#endif