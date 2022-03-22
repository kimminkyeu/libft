/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:58:52 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/22 16:11:36 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

extern void		*ft_calloc(size_t nmemb, size_t bytes);

static size_t	get_nbr_len(unsigned int n)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (n == 0)
		nbr_len = 1;
	else
	{
		while (n > 0)
		{
			n /= 10;
			++nbr_len;
		}
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	unsigned int	n_tmp;
	char			*pa_result;
	size_t			nbr_len;
	size_t			sign;

	sign = 0;
	n_tmp = n;
	if (n < 0)
	{
		n_tmp = -n;
		sign = 1;
	}
	nbr_len = get_nbr_len(n_tmp);
	pa_result = ft_calloc((nbr_len + sign + 1), sizeof(*pa_result));
	if (!pa_result)
		return (NULL);
	pa_result[nbr_len + sign] = '\0';
	if (sign == 1)
		pa_result[0] = '-';
	while (nbr_len > 0)
	{
		pa_result[(nbr_len--) + sign - 1] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	return (pa_result);
}
