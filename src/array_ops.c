/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:20:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/14 12:35:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

void	*ft_memcpy(void *dst_void, const void *src_void, size_t length);

void	swap(int32_t *stack, size_t length)
{
	int32_t	temp;

	if (length <= 1)
		return ;
	temp = stack[length - 1];
	stack[length - 1] = stack[length - 2];
	stack[length - 2] = temp;
}

// To avoid multiple shift operations, top of the stack is end of array
void	push(int32_t *src, int32_t *dst, size_t *src_len, size_t *dst_len)
{
	if (*src_len == 0)
		return ;
	dst[*dst_len - 1] = src[*src_len - 1];
	*src_len--;
	*dst_len++;
}

void	rotate(int32_t *stack, size_t length, uint_fast8_t reverse)
{
	int32_t	temp;

	if (reverse == 0)
	{
		temp = stack[0];
		ft_memcpy(stack, stack + 1, length - 1);
		stack[length - 1] = temp;
	}
	else
	{
		temp = stack[length - 1];
		ft_memcpy(stack + 1, stack, length - 1);
		stack[0] = temp;
	}
}

void	ft_command(char cmd[3])