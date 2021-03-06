/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utility_2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 01:28:16 by abobas        #+#    #+#                 */
/*   Updated: 2020/06/04 19:35:10 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_two.h"
#include <unistd.h>
#include <sys/time.h>

int			error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (0);
}

int			ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int			ft_isnumber(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if ((s1 && !s2) || (!s1 && s2))
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

uint64_t	get_time(void)
{
	struct timeval		time_value;

	if (gettimeofday(&time_value, 0) < 0)
	{
		error("Retrieving time failed");
		return (-1);
	}
	return (time_value.tv_sec * 1000 + (time_value.tv_usec / 1000));
}
