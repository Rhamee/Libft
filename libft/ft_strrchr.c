/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrha <hrha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:30:59 by hrha              #+#    #+#             */
/*   Updated: 2022/02/03 16:25:52 by hrha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (1)
	{
		if (*(s + i) == (unsigned char)c)
			return ((char *)(s + i));
		if (i == 0)
			break ;
		i--;
	}
	return (0);
}
