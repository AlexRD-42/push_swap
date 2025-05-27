/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/26 16:26:38 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

typedef struct s_stack
{
	int32_t	*bot;
	int32_t	*top;
	size_t	length;
}	t_stack;

typedef struct s_median
{
	int32_t	a;
	int32_t	mid;
	int32_t	b;
}	t_median;

typedef struct s_chain
{
	size_t	start;
	size_t	end;
}	t_chain;

int64_t	ft_atoi(const char *num_str);
void	ft_putnbr(int64_t n, int fd);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length);
void	ft_command(char *cmd, t_stack *a, t_stack *b);

int64_t	ft_delta_sum(int32_t *array, size_t size);
int64_t	ft_delta_count(int32_t *array, size_t length);
t_median	ft_get_median(int32_t *array, size_t length);
uint8_t	ft_sort_status(t_stack *sta, t_stack *stb);
void	ft_insertion_sort(int32_t *array, size_t length);

#endif