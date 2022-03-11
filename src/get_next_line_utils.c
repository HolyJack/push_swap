/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:24:45 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 21:03:30 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	const int	slen = ft_strlen(s);
	char		*tmp;

	tmp = (char *) malloc(sizeof(char) * slen + 1);
	if (tmp == NULL)
		return (NULL);
	ft_memcpy(tmp, s, slen + 1);
	return (tmp);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	dstlen = ft_strlen(dst);
	const size_t	srclen = ft_strlen(src);
	const size_t	appendlen = dstsize - dstlen - 1;
	char			*offset;

	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	offset = dst + dstlen;
	if (srclen < appendlen)
	{
		ft_memcpy(offset, src, srclen + 1);
	}
	else if (appendlen > 0)
	{
		ft_memcpy(offset, src, appendlen);
		*(offset + appendlen) = '\0';
	}
	return (dstlen + srclen);
}
