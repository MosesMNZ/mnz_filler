/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:56:09 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/16 17:37:12 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	struct_initializer(t_map_piece *info)
{
	info->map_col_temp = 0;
	info->map_row_temp = 0;
	info->map_row_min = 0;
	info->mod = 0;
	info->flag = 0;
	info->p_stars_nbr = 0;
	info->o_nbr = 0;
	info->x_nbr = 0;
	info->o_temp_nbr = 0;
	info->x_temp_nbr = 0;
	info->x_coordinate = 0;
	info->y_coordinate = 0;
}

void	ft_player_initializer(t_player *player)
{
	char	*line;

	get_next_line(0, &line);
	if ((!(ft_strncmp(line, "$$$ exec p", 10))))
	{
		if (line[10] == '1')
		{
			player->nbr = '1';
			player->letter = 'O';
			player->temp_letter = 'o';
		}
		else
		{
			player->nbr = '2';
			player->letter = 'X';
			player->temp_letter = 'x';
		}
		ft_strdel(&line);
		return ;
	}
	return ;
}

void	place_piece_initializer_a(t_map_piece *info)
{
	info->flag = 0;
	info->p_y = info->p_bottom_end;
	info->m_y = info->map_row_temp;
}

void	place_piece_initializer_b(t_map_piece *info)
{
	info->flag = 0;
	info->p_y = info->p_top_start;
	info->m_y = info->map_row_min;
}
