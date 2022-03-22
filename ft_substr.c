/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:00:25 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/22 17:16:10 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

extern size_t	ft_strlen(const char *str);
extern void		*ft_calloc(size_t nmemb, size_t bytes);
extern size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cnt;
	char	*pa_str;

	cnt = 0;
	while (s[start + cnt] && (cnt < len) && (start < ft_strlen(s)))
		++cnt;
	pa_str = ft_calloc((cnt + 1), sizeof(*pa_str));
	if (!pa_str)
		return (NULL);
	ft_strlcpy(pa_str, s + start, cnt + 1);
	return (pa_str);
}
