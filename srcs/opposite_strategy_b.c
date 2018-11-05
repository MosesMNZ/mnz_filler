/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opposite_strategy_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:10:33 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/16 18:10:43 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	opposite_place_piece_b(t_map_piece *info, t_player *moses)
{
	while (info->p_y <= info->p_bottom_end)
	{
		info->flag = (info->map_row_min +
				(info->p_bottom_end - info->p_top_start + 1) >
				info->map_row ? 2 : 0);
		if (info->flag == 2)
			return ;
		info->m_x = info->map_col_min;
		info->p_x = info->p_left_start;
		while (info->p_x <= info->p_right_end)
		{
			if ((info->map_col_min + (info->p_right_end -
							info->p_left_start + 1) >
						info->map_col) && (info->flag = 1))
				return ;
			if (info->piece[info->p_y][info->p_x] != '.')
				info->temp_map[info->m_y][info->m_x] = moses->letter;
			info->x_coordinate = info->map_col_min - info->p_left_start;
			info->y_coordinate = info->map_row_min - info->p_top_start;
			info->m_x++;
			info->p_x++;
		}
		info->m_y++;
		info->p_y++;
	}
}

int		opposite_move_b(t_map_piece *info)
{
	if (info->flag == 1)
	{
		info->map_row_min++;
		info->map_col_min = 0;
	}
	else if (info->flag == 2)
		return (1);
	else
		info->map_col_min++;
	return (0);
}

void	opposite_algo_2_b(t_map_piece *info, t_player *moses)
{
	ft_copy_tmp_map(info);
	ft_count_p_stars(info);
	place_piece_initializer_b(info);
	opposite_place_piece_b(info, moses);
	ft_count_m_letters_before(info);
	ft_count_m_letters_after(info);
}

void	opposite_algo_4_b(t_map_piece *info, t_player *moses)
{
	opposite_algo_2_b(info, moses);
	if (!(check_placement(info, moses)))
	{
		coordinate_transmitter(info);
		info->mod++;
		info->map_row_min = 0;
		algo_3(info);
	}
	else
	{
		if (!opposite_move_b(info))
			ft_copy_tmp_map(info);
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}
