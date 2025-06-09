/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:20:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 19:20:52 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "push_swap.h"

static
uint8_t	ft_swap(char type, t_stack *a, t_stack *b)
{
	int32_t	temp;
	uint8_t	return_value;

	return_value = 0;
	if ((type == 'a' || type == 's') && a->length > 1)
	{
		temp = *a->top;
		*a->top = *(a->top - 1);
		*(a->top - 1) = temp;
		return_value = 1;
	}
	if ((type == 'b' || type == 's') && b->length > 1)
	{
		temp = *b->top;
		*b->top = *(b->top - 1);
		*(b->top - 1) = temp;
		return_value = 1;
	}
	return (return_value);
}

static
uint8_t	ft_push(char type, t_stack *a, t_stack *b)
{
	uint8_t	return_value;

	return_value = 0;
	if (type == 'a' && b->length > 0)
	{
		(a->length)++;
		a->bot[a->length - 1] = b->bot[b->length - 1];
		b->bot[b->length - 1] = 0;
		(b->length)--;
		return_value = 1;
	}
	if (type == 'b' && a->length > 0)
	{
		(b->length)++;
		b->bot[b->length - 1] = a->bot[a->length - 1];
		a->bot[a->length - 1] = 0;
		(a->length)--;
		return_value = 1;
	}
	a->top = a->bot + a->length - (a->length != 0);
	b->top = b->bot + b->length - (b->length != 0);
	return (return_value);
}

// First becomes Last (1234 -> 2341)
static
uint8_t	ft_rotate(char type, t_stack *a, t_stack *b)
{
	int32_t	temp;
	uint8_t	return_value;

	return_value = 0;
	if ((type == 'a' || type == 'r') && a->length > 1)
	{
		temp = *a->top;
		ft_memcpy(a->bot + 1, a->bot, (a->length - 1) * sizeof(int32_t));
		*a->bot = temp;
		return_value = 1;
	}
	if ((type == 'b' || type == 'r') && b->length > 1)
	{
		temp = *b->top;
		ft_memcpy(b->bot + 1, b->bot, (b->length - 1) * sizeof(int32_t));
		*b->bot = temp;
		return_value = 1;
	}
	return (return_value);
}

// Last becomes First (1234 -> 4123)
static
uint8_t	ft_rrotate(char type, t_stack *a, t_stack *b)
{
	int32_t	temp;
	uint8_t	return_value;

	return_value = 0;
	if ((type == 'a' || type == 'r') && a->length > 1)
	{
		temp = *a->bot;
		ft_memcpy(a->bot, a->bot + 1, (a->length - 1) * sizeof(int32_t));
		*a->top = temp;
		return_value = 1;
	}
	if ((type == 'b' || type == 'r') && b->length > 1)
	{
		temp = *b->bot;
		ft_memcpy(b->bot, b->bot + 1, (b->length - 1) * sizeof(int32_t));
		*b->top = temp;
		return_value = 1;
	}
	return (return_value);
}

size_t	ft_command(const char *cmd, t_stack *sta, t_stack *stb)
{
	static size_t	index = 0;
	uint8_t			op;

	op = 0;
	if (cmd[0] == '_')
		cmd++;
	if (cmd[0] == 'C' && cmd[1] == 'L' && cmd[2] == 'R')
		index = 0;
	else if (cmd[0] == 's')
		op = ft_swap(cmd[1], sta, stb);
	else if (cmd[0] == 'p')
		op = ft_push(cmd[1], sta, stb);
	else if (cmd[0] == 'r' && cmd[2] != 0)
		op = ft_rrotate(cmd[2], sta, stb);
	else if (cmd[0] == 'r' && (cmd[1] == 'a' || cmd[1] == 'b' || cmd[1] == 'r'))
		op = ft_rotate(cmd[1], sta, stb);
	if (op != 0 && cmd[0] != '_')
	{
		write(1, cmd, 2 + (cmd[2] != 0));
		write(1, "\n", 1);
		index++;
	}
	return (index);
}
