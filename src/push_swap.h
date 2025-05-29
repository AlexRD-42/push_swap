/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/29 19:11:46 by adeimlin         ###   ########.fr       */
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
	int32_t	upper;
	int32_t	middle;
	int32_t	lower;
	int32_t	count;
}	t_median;

typedef struct s_chain
{
	size_t	start;
	size_t	end;
}	t_chain;

int64_t	ft_atoi(const char *num_str);
void	ft_putnbr(int64_t n, int fd);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length);
void	*ft_memset(void *dst_void, const uint8_t byte, size_t length);

size_t	ft_command(char *cmd, t_stack *a, t_stack *b);

void	ft_binary_push(t_stack *sta, t_stack *stb, t_median med, uint8_t mode);
void	ft_sort_three(t_stack *sta, t_stack *stb, size_t length);
int64_t	ft_delta_sum(int32_t *array, size_t size);
int64_t	ft_delta_count(int32_t *array, size_t length);
t_median	ft_get_median(int32_t *array, size_t start, size_t end);
uint8_t	ft_sort_status(t_stack *sta, t_stack *stb);
void	ft_insertion_sort(int32_t *array, size_t length);

#endif