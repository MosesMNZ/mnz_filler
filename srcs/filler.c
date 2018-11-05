/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:53:58 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/16 17:08:58 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	place_piece_a(t_map_piece *info, t_player *moses)
{
	while (info->p_y >= info->p_top_start)
	{
		info->flag = (info->map_row_temp -
				(info->p_bottom_end - info->p_top_start) < 0 ? 2 : 0);
		if (info->flag == 2)
			return ;
		info->m_x = info->map_col_temp;
		info->p_x = info->p_right_end;
		while (info->p_x >= info->p_left_start)
		{
			if ((info->map_col_temp - (info->p_right_end -
						info->p_left_start) < 0) && (info->flag = 1))
				return ;
			if (info->piece[info->p_y][info->p_x] != '.')
				info->temp_map[info->m_y][info->m_x] = moses->letter;
			info->x_coordinate = info->m_x - info->p_left_start;
			info->y_coordinate = info->m_y - info->p_top_start;
			info->m_x--;
			info->p_x--;
		}
		info->m_y--;
		info->p_y--;
	}
}

void	place_piece_b(t_map_piece *info, t_player *moses)
{
	while (info->p_y <= info->p_bottom_end)
	{
		info->flag = (info->map_row_min + (info->p_bottom_end -
					info->p_top_start + 1) > (info->map_row) ? 2 : 0);
		if (info->flag == 2)
			return ;
		info->m_x = info->map_col_temp;
		info->p_x = info->p_right_end;
		while (info->p_x >= info->p_left_start)
		{
			if ((info->map_col_temp - (info->p_right_end -
						info->p_left_start) < 0) && (info->flag = 1))
				return ;
			if (info->piece[info->p_y][info->p_x] != '.')
				info->temp_map[info->m_y][info->m_x] = moses->letter;
			info->x_coordinate = info->m_x - info->p_left_start;
			info->y_coordinate = info->map_row_min - info->p_top_start;
			info->m_x--;
			info->p_x--;
		}
		info->m_y++;
		info->p_y++;
	}
}

void	ft_count_p_stars(t_map_piece *p_info)
{
	int x;
	int y;
	int stars;

	y = 0;
	stars = 0;
	while (y < p_info->piece_row)
	{
		x = 0;
		while (x < p_info->piece_col)
		{
			if (p_info->piece[y][x] == '*')
				stars++;
			x++;
		}
		y++;
	}
	p_info->p_stars_nbr = stars;
}

void	ft_count_m_letters_before(t_map_piece *p_info)
{
	int x;
	int y;
	int os;
	int xs;

	y = 0;
	os = 0;
	xs = 0;
	while (y < p_info->map_row)
	{
		x = 0;
		while (x < p_info->map_col)
		{
			if (p_info->map[y][x] == 'O' || p_info->map[y][x] == 'o')
				os++;
			else if (p_info->map[y][x] == 'X' || p_info->map[y][x] == 'x')
				xs++;
			x++;
		}
		y++;
	}
	p_info->o_nbr = os;
	p_info->x_nbr = xs;
}

void	ft_count_m_letters_after(t_map_piece *p_info)
{
	int x;
	int y;
	int os;
	int xs;

	y = 0;
	os = 0;
	xs = 0;
	while (y < p_info->map_row)
	{
		x = 0;
		while (x < p_info->map_col)
		{
			if (p_info->temp_map[y][x] == 'O' || p_info->temp_map[y][x] == 'o')
				os++;
			else if (p_info->temp_map[y][x] == 'X' ||
					p_info->temp_map[y][x] == 'x')
				xs++;
			x++;
		}
		y++;
	}
	p_info->o_temp_nbr = os;
	p_info->x_temp_nbr = xs;
}
