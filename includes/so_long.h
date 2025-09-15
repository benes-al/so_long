/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:53:19 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/15 19:19:35 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/******************************************************************************/
/*                              Standard libraries                            */
/******************************************************************************/

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

/******************************************************************************/
/*                              External libraries                            */
/******************************************************************************/

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

/******************************************************************************/
/*                               MACROS                                       */
/******************************************************************************/

# define TILE_SIZE	64
# define TILES		"01CEP"
# define W_XPM		"textures/1.xpm"
# define S_XPM		"textures/0.xpm"
# define E_XPM		"textures/E.xpm"
# define C_XPM		"textures/C.xpm"
# define P1_XPM		"textures/P1.xpm"
# define P2_XPM		"textures/P2.xpm"
# define P3_XPM		"textures/P3.xpm"

/******************************************************************************/
/*                               ENUMS                                        */
/******************************************************************************/

typedef enum e_tile
{
	WALL        = '1',
	SPACE       = '0',
	EXIT        = 'E',
	COLLECTIBLE = 'C',
	PLAYER      = 'P',
	VISITED     = 'V'
}	t_tile;

typedef enum e_key
{
	KEY_W		= 119,
	KEY_A		= 97,
	KEY_S		= 115,
	KEY_D		= 100,
	KEY_ESC		= 65307,
	KEY_UP		= 65362,
	KEY_LEFT	= 65361,
	KEY_DOWN	= 65364,
	KEY_RIGHT	= 65363,
}	t_key;

typedef enum e_img_index
{
	RUN_RIGHT		= 0,
	RUN_LEFT		= 1,
	PULLED_BY_ROPE	= 2
}	t_img_index;

/******************************************************************************/
/*                               STRUCTS                                      */
/******************************************************************************/

typedef struct s_player_pos
{
	int	y;
	int	x;
}	t_player_pos;

typedef struct s_map
{
	char		**grid;
	size_t		rows;
	size_t		cols;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;


typedef struct s_player
{
	t_player_pos	current_pos;
	t_player_pos	next_pos;
	char			current_tile;
	int				img_index;
	int				collect;
}	t_player;

typedef struct s_game
{
	char		*map_file;
	void		*mlx;
	void		*mlx_window;
	t_map		map;
	int			moves;
	t_player	player;
	int			player_count;
	int			exit_count;
	int			collectible_count;
	//int		spaces;
	t_img		img_1;
	t_img		img_0;
	t_img		img_E;
	t_img		img_C;
	t_img		img_P[3];
	int			x;
	int			y;
}	t_game;

/******************************************************************************/
/*                               GAME                                         */
/******************************************************************************/

void	init_game(t_game *game);
void	render_move(t_game *game, char current, char next, t_player *player);
void	run_game(t_game *game);

/******************************************************************************/
/*                               PARSER                                       */
/******************************************************************************/

void	are_valid_characters(t_game *game);
void	check_args(int argc);
void	create_map(t_game *game);
void	is_map_enclosed_by_walls(t_game *game);
void	is_valid_file_name(t_game *game);
void	is_valid_grid_size(t_game *game);
void	is_valid_map(t_game *game);
void	is_valid_path(t_game *game, t_player_pos current_pos);
void	parse_map(char *map_file, t_game *game);

/******************************************************************************/
/*                               UTILS                                        */
/******************************************************************************/

char	*file_in_one_line(char *map_file, t_game *game);
int		ft_exit_error(char *error_message, t_game *game);
int		ft_exit_esc(t_game *game);
int		ft_exit_game(char *message, t_game *game);
void	ft_free_array(char **array);
void	ft_free_game(t_game *game);
size_t	ft_strclen(const char *str, const char c);
#endif