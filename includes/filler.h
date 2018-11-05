/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:59:22 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/18 12:25:21 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef	struct	s_player
{
	char		nbr;
	char		letter;
	char		temp_letter;
}				t_player;

typedef	struct	s_map_piece
{
	int			map_col;
	int			map_row;
	int			map_col_temp;
	int			map_row_temp;
	int			map_row_min;
	int			map_col_min;
	int			piece_col;
	int			piece_row;
	int			flag;
	int			mod;
	int			p_left_start;
	int			p_top_start;
	int			p_bottom_end;
	int			p_right_end;
	int			p_stars_nbr;
	int			o_nbr;
	int			x_nbr;
	int			o_temp_nbr;
	int			x_temp_nbr;
	char		**map;
	char		**piece;
	char		**temp_map;
	int			x_coordinate;
	int			y_coordinate;
	int			p_y;
	int			p_x;
	int			m_x;
	int			m_y;
}				t_map_piece;

void			ft_player_initializer(t_player *player);
void			struct_initializer(t_map_piece *info);
void			place_piece_initializer_a(t_map_piece *info);
void			place_piece_initializer_b(t_map_piece *info);
void			ft_m_size(t_map_piece *map);
void			ft_read_map(t_map_piece *read_map_into);
void			ft_read_piece(t_map_piece *read_piece_into);
void			ft_piece_size(t_map_piece *piece);
void			place_piece_a(t_map_piece *info, t_player *moses);
void			place_piece_b(t_map_piece *info, t_player *moses);
void			ft_count_m_letters_before(t_map_piece *p_info);
void			ft_count_m_letters_after(t_map_piece *p_info);
void			ft_count_p_stars(t_map_piece *p_info);
void			ft_copy_tmp_map(t_map_piece *read_tmp_into);
int				check_placement(t_map_piece *p_info, t_player *shape);
int				move_a(t_map_piece *info);
int				move_b(t_map_piece *info);
void			coordinate_transmitter(t_map_piece *info);
void			trim(t_map_piece *info);
void			algo_1(t_map_piece *info, t_player *moses);
void			algo_2(t_map_piece *info, t_player *moses);
void			algo_3(t_map_piece *info);
void			algo_4a(t_map_piece *info, t_player *moses);
void			algo_4_b(t_map_piece *info, t_player *moses);
void			opposite_place_piece_a(t_map_piece *info, t_player *me);
void			opposite_place_piece_b(t_map_piece *info, t_player *me);
int				opposite_move_a(t_map_piece *info);
int				opposite_move_b(t_map_piece *info);
void			opposite_algo_2_a(t_map_piece *info, t_player *me);
void			opposite_algo_2_b(t_map_piece *info, t_player *me);
void			opposite_algo_4_a(t_map_piece *info, t_player *me);
void			opposite_algo_4_b(t_map_piece *info, t_player *me);
void			ft_main_algo_a(t_map_piece *info, t_player *moses);
void			ft_main_algo_b(t_map_piece *info, t_player *moses);
int				main(void);
#endif
