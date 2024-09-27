/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:46:34 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/27 13:35:24 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks the number of command line arguments (argc).

void	check_argc(int argc)
{
	if (argc == 1)
	{
		exit(1);
	}
}

// Checks if the string consists only of valid characters:
// numbers, spaces,	- and + signs.

void	is_valid(const char *str, t_argument_data *arg_data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-'
			&& str[i] != '+')
		{
			arg_data->error_flag = 1;
			print_error("some arguments aren’t integers\n");
			return ;
		}
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
		{
			arg_data->error_flag = 1;
			print_error("invalid sign usage\n");
			return ;
		}
		i++;
	}
}

// Checks if a string can be split into individual numbers by checking
// if they are separated by spaces.

int	is_splittable(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (ft_isdigit(str[i]))
		{
			i++;
		}
		if (str[i] != ' ' && str[i] != '\0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

// This function counts the total number of numbers passed via command
// line arguments. The arguments can contain either a single number or multiple
// numbers separated by spaces.

int	count_total_numbers(int argc, char *argv[])
{
	int		total_count;
	char	**split_args;
	int		count;
	int		arg;

	arg = 1;
	total_count = 0;
	while (arg < argc)
	{
		if (is_splittable(argv[arg]))
		{
			split_args = ft_split(argv[arg], ' ');
			count = 0;
			while (split_args[count] != NULL)
				count++;
			total_count += count;
			ft_free_arr(split_args);
		}
		else
			total_count++;
		arg++;
	}
	return (total_count);
}

// The function checks if the number n is a duplicate in
// the array buffer of length len.

int	ft_is_duplicate(int *buffer, int n, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (buffer[i] == n)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
