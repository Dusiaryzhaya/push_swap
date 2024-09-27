/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:15:58 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/27 12:45:46 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Splits the string into substrings.

int	*split_and_check(char *str, int *count, int *error_flag)
{
	int		i;
	char	**split_args;
	int		*buf;

	split_args = ft_split(str, ' ');
	*count = 0;
	i = 0;
	while (split_args[*count] != NULL)
		(*count)++;
	buf = malloc(*count * sizeof(int));
	if (!buf)
		exit(1);
	while (split_args[i] != NULL)
	{
		buf[i] = check_and_convert(split_args[i], error_flag);
		if (*error_flag)
		{
			ft_free_arr(split_args);
			free(buf);
			return (0);
		}
		i++;
	}
	ft_free_arr(split_args);
	return (buf);
}

// Splits the argument into numbers and checks each number for duplicates

int	process_splittable_argument(char *arg, int *buffer, int *buffer_size,
		int *error_flag)
{
	int	buf_count;
	int	*buf;
	int	i;

	i = 0;
	buf = split_and_check(arg, &buf_count, error_flag);
	if (!buf)
	{
		return (0);
	}
	while (i < buf_count)
	{
		if (ft_is_duplicate(buffer, buf[i], *buffer_size))
		{
			print_error("some arguments are duplicates\n");
			free(buf);
			return (1);
		}
		buffer[(*buffer_size)++] = buf[i];
		i++;
	}
	free(buf);
	return (0);
}

// The main function for processing program arguments.
// Checks the validity of each argument using is_valid.
// If the argument contains multiple numbers (for example,
// a string with spaces), processes it using process_splittable_argument.
// If the argument is a single number,
// checks it for duplicates and adds it to the buffer.

int	process_argument(char *arg, t_argument_data *arg_data)
{
	int	value;

	if (is_splittable(arg))
	{
		if (process_splittable_argument(arg, arg_data->buffer,
				&arg_data->buffer_size, &arg_data->error_flag))
			return (1);
	}
	else
	{
		value = check_and_convert(arg, &arg_data->error_flag);
		if (arg_data->error_flag)
			return (1);
		if (ft_is_duplicate(arg_data->buffer, value, arg_data->buffer_size))
		{
			print_error("some arguments are duplicates\n");
			return (1);
		}
		arg_data->buffer[arg_data->buffer_size++] = value;
	}
	return (0);
}

int	main_checker(int argc, char *argv[], t_argument_data *arg_data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		is_valid(argv[i], arg_data);
		if (arg_data->error_flag == 1)
		{
			return (1);
		}
		if (process_argument(argv[i], arg_data))
			return (1);
		i++;
	}
	return (0);
}

// Fills the t_stack stack with numbers from the buffer array.

void	fill_stack_with_buffer(int *buffer, int buffer_size, t_stack **head)
{
	int	i;

	i = 0;
	while (i < buffer_size)
	{
		if (i == 0)
		{
			*head = ft_structnew(buffer[i]);
		}
		else
		{
			ft_structadd_back(head, buffer[i]);
		}
		i++;
	}
}
