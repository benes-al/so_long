#include <stdio.h>

void flood_fill(char map[5][6], int x, int y)
{
    if (map[y][x] != '0')
        return;

    map[y][x] = 'F'; // Fill

    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

void print_map(char map[5][6])
{
    for (int i = 0; i < 5; i++)
        printf("%s\n", map[i]);
}

int main()
{
    char map[5][6] = {
        "11111",
        "1PEC1",
        "11111",
        "10001",
        "11111"
    };

    printf("Before:\n");
    print_map(map);

    flood_fill(map, 1, 1); // Start flood fill from inside

    printf("\nAfter:\n");
    print_map(map);

    return 0;
}
