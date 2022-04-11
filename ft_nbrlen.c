/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:32:48 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/11 21:38:49 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_nbrlen(int num_pos)
{
	size_t	len;

	len = 0;
	if (num_pos == 0)
		return (1);
	while (num_pos != 0)
	{
		num_pos /= 10;
		len += 1;
	}
	return (len);
}
