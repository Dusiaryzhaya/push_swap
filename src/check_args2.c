/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:16:05 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/27 12:44:44 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Skips all spaces and control characters ('\t' - '\r') in the string.

static void	ft_skip_whitespaces(const char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= '\t' && str[*i] <= '\r'))
	{
		(*i)++;
	}
}

// Processes the sign of a number ('-' or '+').

static void	ft_handle_signs(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		(*i)++;
	}
}

// Converts numeric characters from a string to a numeric value.

static int	ft_convert_digit(const char *str, int *i, long *res)
{
	int	digit;

	while (ft_isdigit(str[*i]))
	{
		digit = str[*i] - '0';
		*res = *res * 10 + digit;
		(*i)++;
	}
	return (0);
}

// The main function that converts a string to a long number by skipping spaces,
// handling the sign, checking for digits,
//	and converting characters to a number.

long	ft_str_to_long(const char *str)
{
	int		sign;
	long	res;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	if (str == NULL || *str == '\0')
	{
		print_error("string is NULL or empty\n");
		exit(1);
	}
	ft_skip_whitespaces(str, &i);
	ft_handle_signs(str, &i, &sign);
	ft_convert_digit(str, &i, &res);
	return (res * sign);
}

// Converts a string to a long and checks that the result is within
// the range of an int. If the value is out of range, throws an error.
// The function converts a string to a long number in order to handle and
// check values ​​that may be outside the range of the int type.

int	check_and_convert(char *str, int *error_flag)
{
	long	res;

	res = ft_str_to_long(str);
	if (res > INT_MAX || res < INT_MIN)
	{
		*error_flag = 1;
		print_error("some arguments are bigger or smaller than an integer\n");
		return (0);
	}
	return ((int)res);
}
