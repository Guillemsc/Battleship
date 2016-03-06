#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main()
{
	int battlefield_size_a = 11; int battlefield_size_b = 11;

	printf("\nWELCOME TO BATTLESHIP\n1. First, choose the size of the battlefield(Max: 10x10, Min: 4x4):");
	while (battlefield_size_a > 10 || battlefield_size_b > 10 || battlefield_size_a < 4 || battlefield_size_b < 4)
	{
		printf("\nWidth:  "); scanf_s("%d", &battlefield_size_a); printf("Lenght: "); scanf_s("%d", &battlefield_size_b);
		if (battlefield_size_a > 10 || battlefield_size_b > 10){ printf("\nThe battlefield is bigger than 10x10, please choose another size.\n"); }
		else if (battlefield_size_a < 4 || battlefield_size_b < 4){printf("\nThe battlefield is smaller than 4x4, please choose another size.\n");}
	}
	
	//dinamic allocation maps
	char **map = (char**)malloc(sizeof(char)*battlefield_size_a*battlefield_size_b);
	for (int i = 0; i < battlefield_size_a; i++)
	{map[i] = (char*)malloc(sizeof(char)*battlefield_size_b);}

	char **second_map = (char**)malloc(sizeof(char)*battlefield_size_a*battlefield_size_b);
	for (int i = 0; i < battlefield_size_a; i++)
	{
		second_map[i] = (char*)malloc(sizeof(char)*battlefield_size_b);
	}

	//dinamic allocation enemy maps
	char **enemy_map = (char**)malloc(sizeof(char)*battlefield_size_a*battlefield_size_b);
	for (int i = 0; i < battlefield_size_a; i++)
	{
		enemy_map[i] = (char*)malloc(sizeof(char)*battlefield_size_b);
	}

	char **second_enemy_map = (char**)malloc(sizeof(char)*battlefield_size_a*battlefield_size_b);
	for (int i = 0; i < battlefield_size_a; i++)
	{
		second_enemy_map[i] = (char*)malloc(sizeof(char)*battlefield_size_b);
	}
	

	set_maps(battlefield_size_a, battlefield_size_b, map, enemy_map, second_map, second_enemy_map);
	print_map(battlefield_size_a, battlefield_size_b, map);
	set_ships(battlefield_size_a, battlefield_size_b, map);

	set_enemy_ships(battlefield_size_a, battlefield_size_b, enemy_map);
	print_enemy_map(battlefield_size_a, battlefield_size_b, enemy_map);
	
	printf("\nYou are ready.\nThe enemy is ready.\nThe battle has started.\n");

	battle(battlefield_size_a, battlefield_size_b, map, enemy_map, second_map, second_enemy_map);
	
	return 0;
}