/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanota <tanota@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:36:00 by tanota            #+#    #+#             */
/*   Updated: 2023/10/13 18:36:45 by tanota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_compt(long n)
{
	int	res;

	res = 0;
	if (!n)
		return (1);
	if (n < 0)
		return (ft_compt(-n));
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*ft_strrev(char *s)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < ft_strlen(s) / 2)
	{
		tmp = s[i];
		s[i] = s[ft_strlen(s) - 1 - i];
		s[ft_strlen(s) - 1 - i] = tmp;
		i++;
	}
	return (s);
}

static void	ft_alloc(int n, char **res)
{
	if (n >= 0)
		*res = malloc (sizeof(**res) * (ft_compt(n) + 1));
	else
		*res = malloc (sizeof(**res) * (ft_compt(n) + 2));
	if (!*res)
		return ;
}

static void	ft_loop(int n, int *i, unsigned long long *begin, char **res)
{
	while (ft_compt(n) != *i)
	{
		*(*res + *i) = *begin % 10 + '0';
		*i += 1;
		*begin /= 10;
	}
}

char	*ft_itoa(t_ull n)
{
	char	*res;
	int		i;
	t_ull	begin;

	begin = n;
	i = 0;
	ft_alloc(n, &res);
	if (!res)
		return (0);
	ft_loop(n, &i, &begin, &res);
	res[i] = 0;
	res = ft_strrev(res);
	return (res);
}
