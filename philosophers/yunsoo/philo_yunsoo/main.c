/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:07:49 by suhyun            #+#    #+#             */
/*   Updated: 2023/08/02 01:09:16 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_phil	*phil;

	if (check_arg(ac, av))
		return (ERROR);
	data = init_data(ac, av);
	if (data == NULL)
		return (ERROR);
	phil = init_phil(data);
	if (phil == NULL)
		return (ERROR);
	if (create_phil(data, phil))
		return (ERROR);
	return (0);
}
