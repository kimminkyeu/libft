/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:49:28 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/22 15:58:36 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

extern size_t	ft_strlen(const char *str);
extern void		*ft_calloc(size_t count, size_t size);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*pa_str;
	char	*tmp;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	pa_str = ft_calloc((total_len + 1), sizeof(*pa_str));
	if (!pa_str)
		return (NULL);
	tmp = pa_str;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (pa_str);
}
