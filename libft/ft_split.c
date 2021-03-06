/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrha <hrha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:32:48 by hrha              #+#    #+#             */
/*   Updated: 2022/02/04 21:15:58 by hrha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			num++;
		i++;
	}
	if (i == 0)
		return (0);
	if (s[i - 1] != c)
		num++;
	if (!c)
		num--;
	return (num);
}

static size_t	split_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static char	**split_free(char	**dst, int n)
{
	while (n >= 0)
	{
		free(dst[n]);
		dst[n] = NULL;
		n--;
	}
	free(dst);
	dst = NULL;
	return (NULL);
}

static char	**split_put(char **dest, char const *s, char c, int num)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < num)
	{
		while (s[j] == c)
			j++;
		dest[i] = (char *)malloc(sizeof(char) * (split_strlen(s + j, c) + 1));
		if (!dest[i])
			return (split_free(dest, i - 1));
		ft_strlcpy(dest[i], s + j, split_strlen(s + j, c) + 1);
		j += split_strlen(s + j, c);
		i++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		num;

	if (!s)
		return (NULL);
	num = count(s, c);
	dest = (char **)malloc(sizeof(char *) * (num + 1));
	if (!dest)
		return (NULL);
	dest[num] = NULL;
	return (split_put(dest, s, c, num));
}
