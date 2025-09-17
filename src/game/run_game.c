/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:43:17 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 11:05:19 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long get_timestamp_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

static void	render_map(t_game *game, int i, int j)
{
	t_img	*tile;
	
	tile = &game->img_1;
	while (++i < (int)game->map.rows)
	{
		j = -1;
		while (++j < (int)game->map.cols)
		{
			if (game->map.grid[i][j] == WALL)
			tile = &game->img_1;
			mlx_put_image_to_window(game->mlx, game->mlx_window, tile->img,
				j * TILE_SIZE, i * TILE_SIZE);
		}
	}
}

static void	put_tile(t_game *game)
{
	
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->img_P[game->player.img_index].img,
		game->player.current_pos.x * TILE_SIZE,
		game->player.current_pos.y * TILE_SIZE);
	}

static void	print_moves(t_game *game)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(++game->moves, 1);
	ft_putchar_fd('\n', 1);
}

static void	check_move(t_game *game, int x, int y)
{
    if (game->map.grid[y][x] == WALL)
		return ;
	print_moves(game);
	if (game->map.grid[y][x] == COLLECTIBLE)
	{
		game->map.grid[y][x] = SPACE;
		game->collectible_count--;
	}
	if (game->map.grid[y][x] == EXIT && !game->collectible_count)
	{
		game->win_time_start = get_timestamp_ms();
		render_map(game, -1, -1);
		game->time_now = get_timestamp_ms();
		if (game->time_now - game->win_time_start >= 1000)
			ft_exit_game("Congratulations! You have a friend to climb with! 🧗", game);
	}
	if (game->map.grid[y][x] == EXIT)
	{
		game->player.img_index = FALSE_EXIT_FACE;
		put_tile(game);
		ft_printf("You are not T'alex R'honnold\n");
	}
	game->player.next_pos = (t_player_pos){y, x};
	render_move(game, game->player.current_tile, PLAYER, &game->player);
	game->map.grid[game->player.current_pos.y][game->player.current_pos.x]
		= game->player.current_tile;
	game->player.current_pos = game->player.next_pos;
	game->player.current_tile = game->map.grid[y][x];
	game->map.grid[y][x] = PLAYER;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->player.img_index = PULLED_BY_ROPE;
		put_tile(game);
		check_move(game, game->player.current_pos.x, game->player.current_pos.y - 1);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{	
		game->player.img_index = RUN_LEFT + !(game->moves % 2);
		put_tile(game);	
		check_move(game, game->player.current_pos.x - 1, game->player.current_pos.y);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{	
		game->player.img_index = PULLED_BY_ROPE;
		put_tile(game);
		check_move(game, game->player.current_pos.x, game->player.current_pos.y + 1);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player.img_index = RUN_RIGHT + !(game->moves % 2);
		put_tile(game);
		check_move(game, game->player.current_pos.x + 1, game->player.current_pos.y);
	}
	else if (keycode == KEY_ESC)
		ft_exit_game("Don't give up. Try again. You're a great climber!", game);
	return(0);
}

void	run_game(t_game *game)
{
	mlx_hook(game->mlx_window, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_window, 17, 1L << 17, ft_exit_esc, game);
	mlx_loop(game->mlx);
}
