/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:53:19 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/08 18:35:53 by benes-al         ###   ########.fr       */
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
/*                               STRUCTS                                      */
/******************************************************************************/


/* typedef struct s_point
{
	int	x;
	int	y;
}				t_point;
 */
typedef struct s_map
{
	int		fd;
	//char	**grid;
	//int		rows;
	int		cols;
}				t_map;
/* 
typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct s_dummies
{
	t_point	current;
	char	current_tile;
	t_point	next;
	int		img_index;
	int		collect;
}				t_dummies;
 */
typedef struct s_game
{
	//void		*mlx;
	//void		*win;
	t_map		map;
	//int			moves;
	//t_dummies	player;
	//t_img		img_p[SP_LEN];
	//int			player_count;
	//int			exit;
	//int			collect;
	//int			spaces;
	//t_img		img_walls;
	//t_img		img_space;
	//t_img		img_exit;
	//t_img		img_collect;
	//int			x;
	//int			y;
}				t_game;

/******************************************************************************/
/*                               PARSER                                       */
/******************************************************************************/

void	is_file_name_valid(char *map_file);
void	is_map_valid(char *map_file, t_game *game);
size_t	ft_strclen(const char *str, const char c);

/******************************************************************************/
/*                               UTILS                                        */
/******************************************************************************/

void	ft_exit_error(char *error_message);

#endif