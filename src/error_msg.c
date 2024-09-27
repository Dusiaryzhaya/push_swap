/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:47:15 by anilchen          #+#    #+#             */
/*   Updated: 2024/09/26 16:51:03 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(const char *msg)
{
	write(STDERR_FILENO, "Error:\n", 7);
	write(STDERR_FILENO, msg, ft_strlen(msg));
}
