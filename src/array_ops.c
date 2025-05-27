/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:20:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/26 16:54:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

static void	ft_swap(char type, t_stack *a, t_stack *b)
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
}

static void	ft_push(char type, t_stack *a, t_stack *b)
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
}

// First becomes Last (1234 -> 2341)
static void	ft_rotate(char type, t_stack *a, t_stack *b)
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
}

// Last becomes First (1234 -> 4123)
static void	ft_rrotate(char type, t_stack *a, t_stack *b)
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
}

// Should have a write buffer
// Could add load operation to have the stack as a static member
// if cmd[0] == 'L' && cmd[1] == 'A', t_stack = 
// Double instructions can be optimized later (optimize commands)
void	ft_command(char *cmd, t_stack *a, t_stack *b)
{
	static char		print_buffer[1024];
	static size_t	index = 0;

	// write(1, cmd, 2 + (cmd[2] != 0));
	// write(1, "\n", 1);
	if (cmd[0] == 'S')
		return (ft_swap(cmd[1], a, b));
	if (cmd[0] == 'P')
		return (ft_push(cmd[1], a, b));
	if (cmd[0] == 'R' && cmd[2] < 'A')
		return (ft_rotate(cmd[1], a, b));
	else if (cmd[0] == 'R')
		return (ft_rrotate(cmd[2], a, b));
}
