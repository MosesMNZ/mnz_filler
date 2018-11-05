/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:54:36 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/09 14:54:41 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_m_size(t_map_piece *map)
{
	char	*line;
	char	*x_pos;
	char	*y_pos;

	get_next_line(0, &line);
	while (ft_strncmp(line, "Plateau ", 8))
		get_next_line(0, &line);
	if (!(ft_strncmp(line, "Plateau ", 8)))
	{
		y_pos = ft_strchr(line, ' ');
		map->map_row = ft_atoi(y_pos);
		map->map_row_temp = map->map_row - 1;
		map->map_row_min = 0;
		y_pos++;
		x_pos = ft_strchr(y_pos, ' ');
		map->map_col = ft_atoi(x_pos);
		map->map_col_temp = map->map_col - 1;
		free(line);
		return ;
	}
}

void	ft_read_map(t_map_piece *info)
{
	char	**map;
	char	*begin;
	int		i;
	int		x;

	i = 0;
	info->map = (char**)malloc(sizeof(*map) * info->map_row);
	get_next_line(0, &begin);
	while (ft_strncmp(begin, "000 ", 4))
		get_next_line(0, &begin);
	while (i < (info->map_row))
	{
		x = 0;
		info->map[i] = (char *)malloc(sizeof(char) * info->map_col + 1);
		while (x < info->map_col)
		{
			info->map[i][x] = begin[x + 4];
			x++;
		}
		info->map[i][x] = '\0';
		if (i < (info->map_row - 1))
			get_next_line(0, &begin);
		i++;
	}
}

void	ft_read_piece(t_map_piece *info)
{
	char	**piece;
	char	*begin;
	int		i;
	int		x;

	i = 0;
	if (!(info->piece = (char**)malloc(sizeof(*piece) * info->piece_row)))
		return ;
	get_next_line(0, &begin);
	while (ft_strncmp(begin, ".", 1) && ft_strncmp(begin, "*", 1))
		get_next_line(0, &begin);
	while (i < (info->piece_row))
	{
		x = 0;
		info->piece[i] = (char *)malloc(sizeof(char) * info->piece_col + 1);
		while (x < info->piece_col)
		{
			info->piece[i][x] = begin[x];
			x++;
		}
		info->piece[i][x] = '\0';
		if (i < (info->piece_row - 1))
			get_next_line(0, &begin);
		i++;
	}
}

void	ft_piece_size(t_map_piece *piece)
{
	char	*line;
	char	*x_pos;
	char	*y_pos;

	get_next_line(0, &line);
	while (ft_strncmp(line, "Piece ", 6))
		get_next_line(0, &line);
	if (!(ft_strncmp(line, "Piece ", 6)))
	{
		y_pos = ft_strchr(line, ' ');
		piece->piece_row = ft_atoi(y_pos);
		y_pos++;
		x_pos = ft_strchr(y_pos, ' ');
		piece->piece_col = ft_atoi(x_pos);
		free(line);
		return ;
	}
}
