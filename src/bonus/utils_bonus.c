/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:34:46 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 16:34:22 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

// Could make it more robust (add a string for INT64 MAX
// and a loop to check if any is greater)
int64_t	ft_atoi(const char *num_str)
{
	int64_t	number;
	int64_t	sign;

	number = 0;
	sign = -1;
	while (*num_str == ' ' || (*num_str >= '\t' && *num_str <= '\v'))
		num_str++;
	if (*num_str == '-')
	{
		num_str++;
		sign = -sign;
	}
	else if (*num_str == '+')
		num_str++;
	while (*num_str >= '0' && *num_str <= '9')
		number = number * 10 - (*num_str++ - '0');
	return (sign * number);
}

static
void	*ft_memrcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = ((const char *) src_void) + length;

	dst = ((char *) dst_void) + length;
	while (length > sizeof(int *) && ((uintptr_t)dst & (sizeof(int *) - 1)))
	{
		*--dst = *--src;
		length--;
	}
	while (length >= sizeof(int *))
	{
		dst -= sizeof(int *);
		src -= sizeof(int *);
		length -= sizeof(int *);
		*((uintptr_t *)dst) = *((uintptr_t *)src);
	}
	while (length-- > 0)
		*--dst = *--src;
	return (dst_void);
}

// Possibly check for src and dst alignment
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	if ((uintptr_t) dst_void > (uintptr_t) src_void)
		return (ft_memrcpy(dst_void, src_void, length));
	else if ((uintptr_t) dst_void < (uintptr_t) src_void)
	{
		dst = (char *) dst_void;
		while (length > sizeof(int *) && ((uintptr_t)dst & (sizeof(int *) - 1)))
		{
			*dst++ = *src++;
			length--;
		}
		while (length >= sizeof(int *))
		{
			*((uintptr_t *)dst) = *((uintptr_t *)src);
			dst += sizeof(int *);
			src += sizeof(int *);
			length -= sizeof(int *);
		}
		while (length-- > 0)
			*dst++ = *src++;
	}
	return (dst_void);
}

void	*ft_memset(void *dst_void, const uint8_t byte, size_t length)
{
	char	*dst;
	size_t	word_byte;

	dst = (char *) dst_void;
	if (length >= 16)
	{
		word_byte = (0x0101010101010101 & UINTPTR_MAX) * byte;
		while (((uintptr_t)dst & (sizeof(void *) - 1)) && length-- > 0)
			*dst++ = byte;
		while (length >= sizeof(void *))
		{
			*((uintptr_t *)dst) = word_byte;
			dst += sizeof(void *);
			length -= sizeof(void *);
		}
	}
	while (length > 0)
	{
		*dst++ = byte;
		length--;
	}
	return (dst_void);
}
