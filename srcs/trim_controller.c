/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:55:25 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/16 18:08:50 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	void	ft_piece_left_side(t_map_piece *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->piece_col)
	{
		y = 0;
		while (y < info->piece_row)
		{
			if (info->piece[y][x] == '*')
			{
				info->p_left_start = x;
				return ;
			}
			y++;
		}
		x++;
	}
}

static	void	ft_piece_top_side(t_map_piece *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->piece_row)
	{
		x = 0;
		while (x < info->piece_col)
		{
			if (info->piece[y][x] == '*')
			{
				info->p_top_start = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static	void	ft_piece_right_side(t_map_piece *info)
{
	int	x;
	int	y;

	x = info->piece_col - 1;
	while (x >= 0)
	{
		y = info->piece_row - 1;
		while (y >= 0)
		{
			if (info->piece[y][x] == '*')
			{
				info->p_right_end = x;
				return ;
			}
			y--;
		}
		x--;
	}
}

static	void	ft_piece_bottom_side(t_map_piece *info)
{
	int	x;
	int	y;

	y = info->piece_row - 1;
	while (y >= 0)
	{
		x = info->piece_col - 1;
		while (x >= 0)
		{
			if (info->piece[y][x] == '*')
			{
				info->p_bottom_end = y;
				return ;
			}
			x--;
		}
		y--;
	}
}

void			trim(t_map_piece *info)
{
	ft_piece_bottom_side(info);
	ft_piece_left_side(info);
	ft_piece_right_side(info);
	ft_piece_top_side(info);
}
