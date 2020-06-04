/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   messages.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 02:10:54 by abobas        #+#    #+#                 */
/*   Updated: 2020/06/04 16:20:30 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_one.h"

void	put_text(t_philosopher *philosopher, char *message_type)
{
	ft_putnbr(get_time() - philosopher->data->simulation_start);
	ft_putchar('\t');
	ft_putnbr(philosopher->position);
	if (!ft_strcmp(message_type, "fork"))
		ft_putstr(" has taken a fork\n");
	else if (!ft_strcmp(message_type, "eat"))
		ft_putstr(" is eating\n");
	else if (!ft_strcmp(message_type, "sleep"))
		ft_putstr(" is sleeping\n");
	else if (!ft_strcmp(message_type, "think"))
		ft_putstr(" is thinking\n");
	else if (!ft_strcmp(message_type, "death"))
		ft_putstr(" died\n");
}

void	message(t_philosopher *philosopher, char *message_type)
{
	static int		simulation_stopped = 0;

	if (pthread_mutex_lock(&philosopher->data->pencil) != 0)
		return ;
	if (!ft_strcmp(message_type, "enough"))
	{
		simulation_stopped = 1;
		ft_putnbr(get_time() - philosopher->data->simulation_start);
		ft_putchar('\t');
		ft_putstr("All philosophers have eaten enough\n");
	}
	if (simulation_stopped == 0)
	{
		if (!ft_strcmp(message_type, "death"))
			simulation_stopped = 1;
		put_text(philosopher, message_type);
	}
	if (pthread_mutex_unlock(&philosopher->data->pencil) != 0)
		return ;
}
