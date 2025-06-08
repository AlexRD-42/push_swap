#include <stdint.h>
#include <stddef.h>

int64_t	i64_min(int64_t number1, int64_t number2)
{
	if (number1 <= number2)
		return (number1);
	else
		return (number2);
}

int64_t	i64_max(int64_t number1, int64_t number2)
{
	if (number1 >= number2)
		return (number1);
	else
		return (number2);
}

int64_t	i64_abs(int64_t number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

int64_t	i64_absdiff(int64_t number1, int64_t number2)
{
	if (number1 >= number2)
		return (number1 - number2);
	else
		return (number2 - number1);
}
