/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:20:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/07 15:09:29 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

static uint8_t	ft_swap(char type, t_stack *a, t_stack *b)
{
	int32_t	temp;

	if ((type == 'A' || type == 'S') && a->length > 1)
	{
		temp = *a->top;
		*a->top = *(a->top - 1);
		*(a->top - 1) = temp;
	}
	if ((type == 'B' || type == 'S') && b->length > 1)
	{
		temp = *b->top;
		*b->top = *(b->top - 1);
		*(b->top - 1) = temp;
	}
	return (((type == 'A' || type == 'S') && a->length > 1) ||
			((type == 'B' || type == 'S') && b->length > 1));
}

static uint8_t	ft_push(char type, t_stack *a, t_stack *b)
{
	if (type == 'A' && b->length > 0)
	{
		(a->length)++;
		a->bot[a->length - 1] = b->bot[b->length - 1];
		b->bot[b->length - 1] = 0;
		(b->length)--;
	}
	if (type == 'B' && a->length > 0)
	{
		(b->length)++;
		b->bot[b->length - 1] = a->bot[a->length - 1];
		a->bot[a->length - 1] = 0;
		(a->length)--;
	}
	a->top = a->bot + a->length - (a->length != 0);
	b->top = b->bot + b->length - (b->length != 0);
	return ((type == 'A' && b->length > 0) || (type == 'B' && a->length > 0));
}

// First becomes Last (1234 -> 2341)
static uint8_t	ft_rotate(char type, t_stack *a, t_stack *b)
{
	int32_t	temp;

	if ((type == 'A' || type == 'R') && a->length > 1)
	{
		temp = *a->bot;
		ft_memcpy(a->bot, a->bot + 1, (a->length - 1) * sizeof(int32_t));
		*a->top = temp;
	}
	if ((type == 'B' || type == 'R') && b->length > 1)
	{
		temp = *b->bot;
		ft_memcpy(b->bot, b->bot + 1, (b->length - 1) * sizeof(int32_t));
		*b->top = temp;
	}
	return (((type == 'A' || type == 'R') && a->length > 1) ||
			((type == 'B' || type == 'R') && b->length > 1));
}

// Last becomes First (1234 -> 4123)
static uint8_t	ft_rrotate(char type, t_stack *a, t_stack *b)
{
	int32_t	temp;

	if ((type == 'A' || type == 'R') && a->length > 1)
	{
		temp = *a->top;
		ft_memcpy(a->bot + 1, a->bot, (a->length - 1) * sizeof(int32_t));
		*a->bot = temp;
	}
	if ((type == 'B' || type == 'R') && b->length > 1)
	{
		temp = *b->top;
		ft_memcpy(b->bot + 1, b->bot, (b->length - 1) * sizeof(int32_t));
		*b->bot = temp;
	}
	return (((type == 'A' || type == 'R') && a->length > 1) ||
			((type == 'B' || type == 'R') && b->length > 1));
}

// Have the functions return CMD, to see if NOP to prune useless instructions
size_t	ft_command(const char *cmd, t_stack *sta, t_stack *stb)
{
	static uint8_t	buffer[8192][3];
	static size_t	index = 0;
	uint8_t			op;

	op = 0;
	if (cmd[0] == 'X')
		ft_optimize(buffer, index);
	if (cmd[0] == 'S')
		op = ft_swap(cmd[1], sta, stb);
	else if (cmd[0] == 'P')
		op = ft_push(cmd[1], sta, stb);
	else if (cmd[0] == 'R' && cmd[2] != 0)
		op = ft_rrotate(cmd[2], sta, stb);
	else if (cmd[0] == 'R' && (cmd[1] == 'A' || cmd[1] == 'B' || cmd[1] == 'R'))
		op = ft_rotate(cmd[1], sta, stb);
	if (op != 0 && cmd[2] != 'X')
		ft_memcpy(buffer[index++], cmd, 3);
	else
		// write(1, "\nBAD\n", 5);
	return (index);
}
