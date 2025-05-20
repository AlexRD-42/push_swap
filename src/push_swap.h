/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/20 12:52:18 by adeimlin         ###   ########.fr       */
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

typedef struct s_delta
{
	int64_t	a_;
	int64_t	swap;
	int64_t	q3;
	int64_t	q4;
}	t_delta;

typedef struct s_stats
{
	int32_t	min;
	int32_t	med;
	int32_t	max;
}	t_stats;

// See if it's better to define prototypes within files
int64_t	ft_atoi(const char *num_str);
void	ft_putnbr(int64_t n, int fd);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length);
void	ft_command(char *cmd, t_stack *a, t_stack *b);
int64_t	ft_delta_sum(int32_t *array, size_t size);

#endif