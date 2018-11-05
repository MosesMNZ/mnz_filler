/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:53:13 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/16 16:48:29 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	algo_1(t_map_piece *info, t_player *moses)
{
	ft_player_initializer(moses);
	ft_m_size(info);
	ft_read_map(info);
	ft_piece_size(info);
	ft_read_piece(info);
	trim(info);
	ft_copy_tmp_map(info);
}

void	algo_2(t_map_piece *info, t_player *moses)
{
	ft_copy_tmp_map(info);
	ft_count_p_stars(info);
	if (info->mod % 2)
	{
		place_piece_initializer_a(info);
		place_piece_a(info, moses);
	}
	else
	{
		place_piece_initializer_b(info);
		place_piece_b(info, moses);
	}
	ft_count_m_letters_before(info);
	ft_count_m_letters_after(info);
}

void	algo_3(t_map_piece *info)
{
	free(info->map);
	ft_read_map(info);
	info->piece_col = 0;
	info->piece_row = 0;
	ft_piece_size(info);
	free(info->piece);
	ft_read_piece(info);
	trim(info);
}

void	algo_4a(t_map_piece *info, t_player *moses)
{
	algo_2(info, moses);
	if (!(check_placement(info, moses)))
	{
		coordinate_transmitter(info);
		info->mod++;
		info->map_row_temp = info->map_row - 1;
		algo_3(info);
	}
	else
	{
		if (!move_a(info))
		{
			ft_copy_tmp_map(info);
		}
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}

void	algo_4_b(t_map_piece *info, t_player *moses)
{
	algo_2(info, moses);
	if (!(check_placement(info, moses)))
	{
		coordinate_transmitter(info);
		info->mod++;
		info->map_row_min = 0;
		algo_3(info);
	}
	else
	{
		if (!move_b(info))
		{
			ft_copy_tmp_map(info);
		}
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}
