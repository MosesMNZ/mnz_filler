/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:11:06 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/16 18:11:13 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_main_algo_a(t_map_piece *info, t_player *moses)
{
	while (1)
	{
		if (info->map_row == 15 || info->map_row == 24)
		{
			if (moses->letter == 'O')
			{
				if (info->mod % 2)
					algo_4a(info, moses);
				else
					algo_4_b(info, moses);
			}
			else
			{
				if (info->mod % 2)
					opposite_algo_4_a(info, moses);
				else
					opposite_algo_4_b(info, moses);
			}
		}
		else
			ft_main_algo_b(info, moses);
	}
}

void	ft_main_algo_b(t_map_piece *info, t_player *moses)
{
	if (moses->letter == 'X')
	{
		if (info->mod % 2)
			algo_4a(info, moses);
		else
			opposite_algo_4_b(info, moses);
	}
	else
	{
		if (info->mod % 2)
			opposite_algo_4_a(info, moses);
		else
			algo_4_b(info, moses);
	}
}

int		main(void)
{
	t_player	*moses;
	t_map_piece *map_size;

	moses = (t_player *)malloc(sizeof(*moses));
	map_size = (t_map_piece *)malloc(sizeof(*map_size));
	algo_1(map_size, moses);
	ft_main_algo_a(map_size, moses);
	return (0);
}
