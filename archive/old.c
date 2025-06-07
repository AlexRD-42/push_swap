uint8_t	ft_swap(t_stack *sta, t_stack *stb, int32_t *sorted)
{
	uint8_t	swap;
	size_t	i;

	swap = 0;
	if (*sta->top < *(sta->top - 1))
	{
		i = 0;
		while (sorted[i] != *sta->top)
			i++;
		if (*sta->bot != sorted[i + 1])
			swap += 1;
	}
	if (*stb->top > *(stb->top - 1))
	{
		i = 0;
		while (sorted[i] != *stb->top)
			i++;
		if (*stb->bot != sorted[i - 1])
			swap += 2;
	}
	return (swap);
}

void	ft_push_end(t_stack *sta, t_stack *stb, int32_t *sorted)
{
	uint8_t	swap;
	uint8_t	status;

	status = ft_sort_status(sta, stb);
	while (status != 0)
	{
		swap = ft_swap(sta, stb, sorted);
		if (swap == 3)
			ft_command("SS", sta, stb);
		else if (swap == 2)
			ft_command("SB", sta, stb);
		else if (swap == 1)
			ft_command("SA", sta, stb);
		status = ft_sort_status(sta, stb);
		if (status == 3)
			ft_command("RR", sta, stb);
		else if (status == 2)
			ft_command("RB", sta, stb);
		else if (status == 1)
			ft_command("RA", sta, stb);
	}
	while (stb->length > 0)
		ft_command("PA", sta, stb);
}

void	ft_push_start(t_stack *sta, t_stack *stb, t_median median)
{
	const size_t	length = sta->length / 2 - (sta->length & 1);

	while (stb->length < length)
	{
		if (*sta->top > median.mid)
			ft_command("PB", sta, stb);
		else
		{
			if (ft_delta_count(sta->bot, sta->length) < 0)
				while (*sta->top < median.mid)
					ft_command("RA", sta, stb);
			else
				while (*sta->top < median.mid)
					ft_command("RRA", sta, stb);
		}
	}
}

// Could add double instructions as soon as B.length > 2
// Would require only a check to see if length is bigger than the other
// Sort both arrays while they are 

// Pushes should always be done when valid
// Swaps should be done if top belongs in h2
	// Or if both numbers belong in h1 AND top - 1 > top

// Rotates should be done if the bottom belongs in top
// R. Rotates should be done if top belongs in bottom

// Another heuristic here could be a weight where the further away it is,
// the less valuable it is, to make it less likely that it spends multiple operations
void	ft_push_start(t_stack *sta, t_stack *stb, t_median median)
{
	const size_t	length = sta->length / 2 - (sta->length & 1);

	while (stb->length < length)
	{
		if (*sta->top > median.mid)
			ft_command("PB", sta, stb);
		else
		{
			if (ft_delta_count(sta->bot, sta->length) < 0)
				while (*sta->top < median.mid)
					ft_command("RA", sta, stb);
			else
				while (*sta->top < median.mid)
					ft_command("RRA", sta, stb);
		}
	}
}


void	ft_sort_mid(t_stack *sta, t_stack *stb, int32_t *array)
{
	t_median	median;
	size_t		count;
	size_t		length;
	size_t		i;

	i = 0;
	ft_print(sta, stb);
	while (sta->length > 3)
	{
		median = ft_get_median(array, 0, sta->length);
		ft_binary_push(sta, stb, median, 'B');
		ft_print(sta, stb);
	}
	ft_sort_three(sta, 3);
	i = 90 * stb->length / 100;
	while (stb->length > i)
		ft_push_single(sta, stb, array[i++]);
	ft_print(sta, stb);
	ft_command("XX", sta, stb);
}

// void	ft_mid_sort(t_stack *sta, t_stack *stb, t_median median)
// {
// 	if (*sta->top > *sta->bot && *stb->top < *stb->bot)
// 		ft_command("RR", &sta, &stb);
// }