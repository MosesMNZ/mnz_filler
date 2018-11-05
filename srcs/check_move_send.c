/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_send.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:53:39 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/16 16:51:04 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_copy_tmp_map(t_map_piece *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(info->temp_map = (char**)malloc(sizeof(char *) * info->map_row)))
		return ;
	while (y < info->map_row)
	{
		x = 0;
		info->temp_map[y] = (char *)malloc(sizeof(char) * info->map_col);
		while (x < info->map_col)
		{
			info->temp_map[y][x] = info->map[y][x];
			x++;
		}
		y++;
	}
}

int		check_placement(t_map_piece *p_info, t_player *shape)
{
	if (shape->letter == 'O')
	{
		if ((p_info->o_nbr + p_info->p_stars_nbr - 1) == p_info->o_temp_nbr &&
				(p_info->x_nbr == p_info->x_temp_nbr))
			return (0);
		else
			return (1);
	}
	else if (shape->letter == 'X')
	{
		if ((p_info->x_nbr + p_info->p_stars_nbr - 1) == p_info->x_temp_nbr &&
				(p_info->o_nbr == p_info->o_temp_nbr))
			return (0);
		else
			return (1);
	}
	return (-1);
}

int		move_a(t_map_piece *info)
{
	if (info->flag == 1)
	{
		info->map_row_temp--;
		info->map_col_temp = info->map_col - 1;
	}
	else if (info->flag == 2)
		return (1);
	else
		info->map_col_temp--;
	return (0);
}

int		move_b(t_map_piece *info)
{
	if (info->flag == 1)
	{
		info->map_row_min++;
		info->map_col_temp = info->map_col - 1;
	}
	else if (info->flag == 2)
		return (1);
	else
		info->map_col_temp--;
	return (0);
}

void	coordinate_transmitter(t_map_piece *info)
{
	ft_putnbr(info->y_coordinate);
	ft_putchar(' ');
	ft_putnbr(info->x_coordinate);
	ft_putchar('\n');
}
