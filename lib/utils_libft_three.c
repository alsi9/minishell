/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:00:21 by ephantom          #+#    #+#             */
/*   Updated: 2022/03/29 12:17:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_count(int n, int len)
{
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_exclusion(int m, char *dst, int i)
{
	if (m == -2147483648)
	{
		dst[i] = '-';
		dst[i + 1] = '2';
		m = 147483648;
		return (m);
	}
	else if (m < 0)
	{
		dst[i] = '-';
		m = m * -1;
		return (m);
	}
	return (0);
}

char	*ft_itoa(int n, int len)
{
	char	*dst;
	int		i;
	int		m;

	i = 0;
	if (n <= 0)
		len = 1;
	m = n;
	len = ft_count(n, len);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		return (NULL);
	if (ft_exclusion(m, dst, i))
		m = ft_exclusion(m, dst, i);
	i = len - 1;
	while (m > 9)
	{
		dst[i--] = m % 10 + 48;
		m = m / 10;
	}
	dst[i] = m % 10 + 48;
	dst[len] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char) c)
		i++;
	if (s[i] == (unsigned char) c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0 && s[i] != (unsigned char) c)
		i--;
	if (s[i] == (unsigned char) c)
		return ((char *)&s[i]);
	return (NULL);
}
