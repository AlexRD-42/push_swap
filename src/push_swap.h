/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/03 16:11:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int32_t	*bot;
	int32_t	*top;
	size_t	length;
}	t_stack;

typedef struct s_conditions
{
	uint8_t	src;
	uint8_t	dst;
}	t_thr;

typedef struct s_median
{
	int32_t	upper;
	int32_t	middle;
	int32_t	lower;
	int32_t	count;
}	t_median;

int64_t	ft_atoi(const char *num_str);
void	ft_putnbr(int64_t n, int fd);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length);
void	*ft_memset(void *dst_void, const uint8_t byte, size_t length);

size_t	ft_command(const char *cmd, t_stack *a, t_stack *b);
void	ft_optimize(uint8_t cmd[1024][3], size_t index);

void	ft_sort_three(t_stack *stack, size_t length);
void	ft_push_single(t_stack *dst, t_stack *src, int32_t target);
void	ft_binary_push(t_stack *sta, t_stack *stb, t_median med, uint8_t mode);
void	ft_shuffle(int32_t *array, size_t size, int32_t seed); // CAREFUL

uint8_t	ft_push_range_max(t_stack *dst, t_stack *src);

int64_t	ft_delta_sum(int32_t *array, size_t size);
int64_t	ft_delta_count(int32_t *array, size_t length);
t_median	ft_get_median(int32_t *array, size_t start, size_t end);
t_median	ft_get_median2(size_t start, size_t end);
uint8_t	ft_sort_status(t_stack *sta, t_stack *stb);
void	ft_insertion_sort(int32_t *array, size_t length);

int32_t	i32_abs(int32_t number);
int32_t	i32_abs_diff(int32_t number1, int32_t number2);
int32_t	i32_minrange(const int32_t *number, size_t length);
int32_t	i32_min(int32_t number1, int32_t number2);
int32_t	i32_max(int32_t number1, int32_t number2);
size_t	get_entropy(t_stack *sta, t_stack *stb);

#endif