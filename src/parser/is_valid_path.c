/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:24:23 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/11 22:24:26 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void is_valid_path(t_game *game)
{
	
}


void	floodfill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'V')
		return ;
	else
		map[y][x] = 'V';
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

void	print_map(int argc, char **map)
{
	int	x;
	int	y;

	y = 1;
	write(1, "F\n", 2);
	while (y < argc)
	{
		x = 0;
		while (map[y][x])
		{
			write(1, &map[y][x], 1);
			x++;
		}
	y++;
	write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	y = 1;
	write(1, "map before\n", 11);
	print_map(argc, argv);
	floodfill(argv, 1, 1);
	write(1, "map after\n", 10);
	print_map(argc, argv);
	while (y < argc)
	{
		x = 0;
		while (argv[y][x])
		{
			if (argv[y][x] == 'C' || argv[y][x] == 'E')
			{
				write(1, "invalid map", 11);
				return(0);
			}
			x++;
		}
		y++;
	}
	write(1, "valid map", 9);
	return (0);
}
#if 0

1111
10P1
1C11
1111


#endif