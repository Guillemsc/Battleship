#ifndef _HEAD_
#define _HEAD_

int no_ships_function(int battlefield_size_a, int battlefield_size_b);

void set_maps(int battlefield_size_a, int battlefield_size_b, char **map, char **enemy_map, char **second_map, char **second_enemy_map);

void print_map(int battlefield_size_a, int battlefield_size_b, char **map);
void print_second_map(int battlefield_size_a, int battlefield_size_b, char **second_map);

void set_ships(int battlefield_size_a, int battlefield_size_b, char **map);
void set_enemy_ships(int battlefield_size_a, int battlefield_size_b, char **enemy_map);

void battle(int battlefield_size_a, int battlefield_size_b, char **map, char **enemy_map, char **second_map, char **second_enemy_map);


void print_enemy_map(int battlefield_size_a, int battlefield_size_b, char **enemy_map); //provisional

#endif
