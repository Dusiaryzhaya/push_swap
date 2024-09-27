/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:23:46 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/26 15:54:11 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip_whitespace(const char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= '\t' && str[*i] <= '\r'))
	{
		(*i)++;
	}
}

static void	ft_handle_sign(const char *str, int *i, int *sign)
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

static int	ft_convert_digits(const char *str, int *i, long *res)
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

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	ft_skip_whitespace(str, &i);
	ft_handle_sign(str, &i, &sign);
	ft_convert_digits(str, &i, &res);
	return (res * sign);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char *str = "-777klg";
// 	int res = ft_atoi(str);
// 	printf("%d\n", res);
// 	return (0);
// }