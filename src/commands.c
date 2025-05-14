/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:20:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/14 12:29:39 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

void	swap(int32_t *stack, size_t length);
void	push(int32_t *src, int32_t *dst, size_t *src_len, size_t *dst_len);
void	rotate(int32_t *stack, size_t length, uint_fast8_t reverse);

void	sa(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	swap(a, a_len);
}

void	sb(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	swap(b, b_len);
}

void	ss(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	swap(a, a_len);
	swap(b, b_len);
}

void	pa(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	push(b, a, b, a);
}

void	pb(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	push(a, b, a, b);
}

void	ra(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	rotate(a, a_len, 0);
}

void	rb(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	rotate(b, b_len, 0);
}

void	rr(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	rotate(a, a_len, 0);
	rotate(b, b_len, 0);
}

void	rra(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	rotate(a, a_len, 1);
}

void	rrb(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	rotate(b, b_len, 1);
}

void	rrr(int32_t *a, int32_t *b, int32_t *a_len, int32_t *b_len)
{
	rotate(a, a_len, 1);
	rotate(b, b_len, 1);
}

