/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:33:30 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/16 11:48:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

typedef struct s_stack
{
	int32_t	*array;
	size_t	length;
}	t_stack;

typedef enum e_function_index
{
	CMD_SA,
	CMD_SB,
	CMD_SS,
	CMD_PA,
	CMD_PB,
	CMD_RA,
	CMD_RB,
	CMD_RR,
	CMD_RRA,
	CMD_RRB,
	CMD_RRR
}	t_fnindex;

void	sa(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	swap(a, *a_len);
}

void	sb(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	swap(b, *b_len);
}

void	ss(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	swap(a, *a_len);
	swap(b, *b_len);
}

void	pa(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	push(b, a, b_len, a_len);
}

void	pb(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	push(a, b, a_len, b_len);
}

void	ra(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	rotate(a, *a_len);
}

void	rb(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	rotate(b, *b_len);
}

void	rr(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	rotate(a, *a_len);
	rotate(b, *b_len);
}

void	rra(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	rrotate(a, *a_len);
}

void	rrb(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	rrotate(b, *b_len);
}

void	rrr(int32_t *a, int32_t *b, size_t *a_len, size_t *b_len)
{
	rrotate(a, *a_len);
	rrotate(b, *b_len);
}

void	swap(int32_t *stack, size_t length)
{
	int32_t	temp;

	if (length <= 1)
		return ;
	temp = stack[length - 1];
	stack[length - 1] = stack[length - 2];
	stack[length - 2] = temp;
}

void	push(int32_t *src, int32_t *dst, size_t *src_len, size_t *dst_len)
{
	if (*src_len == 0)
		return ;
	(*dst_len)++;
	dst[*dst_len - 1] = src[*src_len - 1];
	src[*src_len - 1] = 0;
	(*src_len)--;
}

void	rotate(int32_t *stack, size_t length)
{
	int32_t	temp;

	temp = stack[0];
	ft_memcpy(stack, stack + 1, (length - 1) * sizeof(int32_t));
	stack[length - 1] = temp;
}

void	rrotate(int32_t *stack, size_t length)
{
	int32_t	temp;

	temp = stack[length - 1];
	ft_memcpy(stack + 1, stack, (length - 1) * sizeof(int32_t));
	stack[0] = temp;
}

// To avoid multiple shift operations, top of the stack is end of array
void	ft_command(t_fnindex fn_index, t_stack *a, t_stack *b)
{
	static void	(* const fn_table[11])
		(int32_t *a, int32_t *b, size_t  *a_len, size_t  *b_len) =
		{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

	fn_table[fn_index](a->array, b->array, &(a->length), &(b->length));
}