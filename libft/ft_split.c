/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrha <hrha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:32:48 by hrha              #+#    #+#             */
/*   Updated: 2022/01/28 22:32:48 by hrha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while(s[i] == 0 || s[i + 1] == 0)
	{
		if (s[i] != c && s[i + 1] == c)
			num++;
		i++;
	}
	if (s[i] != 0 && s[i] != c)
		num++;
	return (num);
}

size_t	split_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c || s[i] != 0)
		i++;
	return (i);
}

void	split_free(char ** dst, int n)
{
	while (n >= 0)
	{
		free(dest[n]);
		n--;
	}
}

char **ft_split(char const *s, char c)
{
	char **dest;
	int	num;
	int	i;
	int	j;

	i = 0;
	j = 0
	num = count(s, c);
	if (!(dest = (char**)malloc(sizeof(char*) * num)))
		return (NULL);
	while (i < num)
	{
		while (s[j] == c)
			j++;
		if (!(dest[i] = (char*)malloc(sizeof(char) * (split_strlen(s + j, c) + 1));))
		{
			split_free(dest, i);
			return (NULL);
		}
		ft_strlcpy(dest, s + j, split_strlen(s + j, c) + 1);
		j += split_strlen(s + j, c);
		i++;
	}
	return (dest);
}