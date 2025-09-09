/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:00:26 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/09 20:04:12 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
		ft_exit_error("Usage: ./so_long <map.name>.ber");
	is_file_name_valid(argv[1]);
	ft_bzero(&game, sizeof(game));
	is_map_valid(argv[1], &game);
	ft_printf("%d\n%d\n", &game.map.cols, game.map.rows);
	/* -terminar de ler tudo com getnexline antes 
	de fechar rograma para nao ter eakes
	-usar split na linha pra contruir a matrix do jogo
	-strclen e a funccao
	- escrever ft_strcspn()
	code .*/
}
