/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 01:49:11 by abobas        #+#    #+#                 */
/*   Updated: 2020/06/04 22:37:47 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_three.h"

int		validator(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (error("Invalid argument"));
	if (!ft_isnumber(av[1]))
		return (error("Invalid argument"));
	if (!ft_isnumber(av[2]))
		return (error("Invalid argument"));
	if (!ft_isnumber(av[3]))
		return (error("Invalid argument"));
	if (!ft_isnumber(av[4]))
		return (error("Invalid argument"));
	if (av[5])
		if (!ft_isnumber(av[5]))
			return (error("Invalid argument"));
	return (1);
}
