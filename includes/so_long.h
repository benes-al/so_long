/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:53:19 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/11 22:24:50 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/******************************************************************************/
/*                              INCLUDES                                      */
/******************************************************************************/

// Standard libraries
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

//External libraries
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

/******************************************************************************/
/*                               MACROS                                       */
/******************************************************************************/

# define TILLES "01CEP"

/******************************************************************************/
/*                               STRUCTS                                      */
/******************************************************************************/

typedef enum e_tile
{
	WALL = '1',
	SPACE = '0',
	EXIT = 'E',
	COLLECTIBLE = 'C',
	PLAYER = 'P',
}	t_tile;

typedef struct s_player_position
{
	int	x;
	int	y;
}	t_player_position;

typedef struct s_map
{
	char		**grid;
	size_t		rows;
	size_t		cols;
}	t_map;
/* 
typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;
*/

typedef struct s_player
{
	t_player_position	current_position;
	char				current_tile;
	t_player_position	next_position;
	int					img_index;
	int					collect;
}	t_player;

typedef struct s_game
{
	//void		*mlx;
	//void		*win;
	t_map		map;
	//int			moves;
	t_player	player;
	//t_img		img_p[SP_LEN];
	int			player_count;
	int			exit_count;
	int			collectible_count;
	//int			spaces;
	//t_img		img_walls;
	//t_img		img_space;
	//t_img		img_exit;
	//t_img		img_collect;
	//int			x;
	//int			y;
}	t_game;

/******************************************************************************/
/*                               PARSER                                       */
/******************************************************************************/

void	are_valid_characters(t_game *game);
void	create_map(char *map_file, t_game *game);
void	is_map_enclosed_by_walls(t_game *game);
void	is_valid_path(t_game *game);
void	is_valid_file_name(char *map_file, t_game *game);
void	is_valid_grid_size(char *map_file, t_game *game);
void	is_valid_map(char *map_file, t_game *game);

/******************************************************************************/
/*                               UTILS                                        */
/******************************************************************************/

char	*file_in_one_line(char *map_file, t_game *game);
void	ft_exit_error(char *error_message, t_game *game);
void	ft_free_array(char **array);
size_t	ft_strclen(const char *str, const char c);

#endif