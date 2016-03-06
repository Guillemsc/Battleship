#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"
 
void set_maps(int battlefield_size_a, int battlefield_size_b, char **map, char **enemy_map, char **second_map, char **second_enemy_map)
{
	for (int i = 0; i < battlefield_size_a; i++)
	{
		for (int y = 0; y < battlefield_size_b; y++)
		{
			map[i][y] = 'E';
			enemy_map[i][y] = 'E';
			second_map[i][y] = 'E';
			second_enemy_map[i][y] = 'E';
		}
	}
}


void print_map(int battlefield_size_a, int battlefield_size_b, char **map)
{
	printf("\n YOUR MAP\n");
	printf(" ");

	for (int z = 1; z <= battlefield_size_b; z++)
	{
		printf(" %d", z);
	}
	printf("\n");

	for (int i = 0; i < battlefield_size_a; i++)
	{
		printf("%c", i + 65);
		for (int y = 0; y < battlefield_size_b; y++)
		{
			printf(" %c", map[i][y]);
		}
		printf("\n");
	}
}

void print_second_map(int battlefield_size_a, int battlefield_size_b, char **second_map)
{
	printf("\n ENEMY REFERENCE MAP\n ");

	for (int z = 1; z <= battlefield_size_b; z++)
	{
		printf(" %d", z);
	}
	printf("\n");
	for (int i = 0; i < battlefield_size_a; i++)
	{
		printf("%c", i + 65);
		for (int y = 0; y < battlefield_size_b; y++)
		{
			printf(" %c", second_map[i][y]);
		}
		printf("\n");
	}
	for (int y = 0; y < battlefield_size_a; y++)
	{
		printf(" -");
	}
}

//ENEMY
void print_enemy_map(int battlefield_size_a, int battlefield_size_b, char **enemy_map)
{
	printf("\nENEMYMAP\n ");
	for (int z = 1; z <= battlefield_size_b; z++)
	{
		printf(" %d", z);
	}
	printf("\n");

	for (int i = 0; i < battlefield_size_a; i++)
	{
		printf("%c", i + 65);
		for (int y = 0; y < battlefield_size_b; y++)
		{
			printf(" %c", enemy_map[i][y]);
		}
		printf("\n");
	}
}
//-

int no_ships_function(int battlefield_size_a, int battlefield_size_b)
{
	int no_ships = 0;

	if (battlefield_size_a * battlefield_size_b <= 16){ no_ships = 2; }
	else if (battlefield_size_a * battlefield_size_b <= 25){ no_ships = 3; }
	else if (battlefield_size_a * battlefield_size_b <= 36){ no_ships = 4; }
	else if (battlefield_size_a * battlefield_size_b <= 49){ no_ships = 5; }
	else if (battlefield_size_a * battlefield_size_b <= 64){ no_ships = 5; }
	else if (battlefield_size_a * battlefield_size_b <= 81){ no_ships = 7; }
	else if (battlefield_size_a * battlefield_size_b > 81){ no_ships = 8; }
	return no_ships;
}

struct coords
{
public:
	int x;
	int y;
	int size;
	char orientation;
	bool state;
}*ships_coords;


void set_ships(int battlefield_size_a, int battlefield_size_b, char **map)
{
	int no_ships = no_ships_function(battlefield_size_a, battlefield_size_b);

	//prova
	ships_coords = (struct coords*)malloc(sizeof(struct coords)*no_ships_function(battlefield_size_a, battlefield_size_b));
	
	for (int v = 0; v < no_ships; v++)
	{
		ships_coords->state = true;
		ships_coords++;
	}
	ships_coords -= no_ships;
	//-prova
	
	int ship_size = 2;
	int ship_counter = 0;

	printf("\nDue to the size of your map you can place %d ships\n", no_ships);

	while (ship_counter < no_ships)
	{	
	    if (ship_counter == 6){ ship_size++; }
		else if (ship_counter == 5){ ship_size++; }
		else if (ship_counter == 3){ ship_size++; }
		
		printf("\nThe ship number %d has a size of %d blocks\n", (ship_counter)+1, ship_size);

		ship_counter++;

		int placeX = 0;
		int placeY = 0;
		char orientation = 'n';

		int colocation = 0; //parts of the ship placed
		int correct = 1; //is the ship placed in another ship?
		
		bool out_of_the_matrix = true;
		while (out_of_the_matrix == true)
		{
			printf("Where do you want to place it? (Ex: A 3): "); getchar(); scanf_s(" %c", &placeY, 1); getchar(); scanf_s("%d", &placeX);
			printf("In what direction do you want the ship: n/s/e/w?: "); getchar(); scanf_s(" %c", &orientation, 1);
			
			//SEGURETAT - fora de matrix
			switch (orientation)
			{
			case 'n':
				while (colocation < ship_size)
				{
					if (placeY-64 - colocation + 1 > battlefield_size_a || placeY-64-colocation <= 0)
					{
						printf("\nYou are placing a ship out of the map\nPlease choose another position\n"); break;
						out_of_the_matrix = true;
					}
					else if ((colocation + 1) == ship_size)
					{out_of_the_matrix = false;}
					colocation++;
				}
				colocation = 0;
				break;
			case 's':
				while (colocation < ship_size)
				{
					if (placeY - 64 + colocation + 1 > battlefield_size_a || placeY - 64 + colocation <= 0)
					{
						printf("\nYou are placing a ship out of the map\nPlease choose another position\n"); break;
						out_of_the_matrix = true;
					}
					else if ((colocation + 1) == ship_size)
					{out_of_the_matrix = false;}
					colocation++;
				}
				colocation = 0;
				break;
			case 'e':
				while (colocation < ship_size)
				{
					if (placeX + colocation > battlefield_size_b|| placeX + colocation <= 0)
					{
						printf("\nYou are placing a ship out of the map\nPlease choose another position\n"); break;
						out_of_the_matrix = true;
					}
					else if ((colocation + 1) == ship_size)
					{out_of_the_matrix = false;}
					colocation++;
				}
				colocation = 0;
				break;
			case 'w':
				while (colocation < ship_size)
				{
					if (placeX + colocation > battlefield_size_b || placeX - colocation <= 0)
					{
						printf("\nYou are placing a ship out of the map\nPlease choose another position\n"); break;
						out_of_the_matrix = true;
					}
					else if ((colocation + 1) == ship_size)
					{out_of_the_matrix = false;}
					colocation++;
				}
				colocation = 0;
				break;
			}
			//-SEGURETAT - fora de la matrix
		}

		//Colocació
		switch (orientation)
		{
		case 'n':
			//SEGURETAT - Baixell damunt un altre -> North
			while (colocation < ship_size)
			{
				if (map[(placeY - 65) - colocation][(placeX - 1)] == 'S') 
				{correct = 0; printf("\nThis place is used by another ship or it's out of the map\n"); ship_counter--; break;}
				colocation++;
			}
			colocation = 0;
			//-
			if (correct == 1)
			{
				ships_coords->x = placeY - 65; ships_coords->y = placeX - 1; ships_coords->orientation = 'n'; ships_coords->size = ship_size; ships_coords++;
				
				while (colocation < ship_size)
				{map[(placeY - 65) - colocation][(placeX - 1)] = 'S'; colocation++;}
				
			}
			print_map(battlefield_size_a, battlefield_size_b, map);
			break;
		case 's':
			//SEGURETAT - Baixell damunt un altre -> South
			while (colocation < ship_size)
			{
				if (map[(placeY - 65) + colocation][(placeX - 1)] == 'S')
				{correct = 0; printf("\nThis place is used by another ship\n"); ship_counter--; break;}
				colocation++;
			}
			colocation = 0;
			//-
			if (correct == 1)
			{
				ships_coords->x = placeY - 65; ships_coords->y = placeX - 1; ships_coords->orientation = 's'; ships_coords->size = ship_size; ships_coords++;

				while (colocation < ship_size)
				{map[(placeY - 65) + colocation][(placeX - 1)] = 'S';
					colocation++;}
			}
			print_map(battlefield_size_a, battlefield_size_b, map);
			break;
		case 'e':
			//SEGURETAT - Baixell damunt un altre -> East
			while (colocation < ship_size)
			{
				if (map[(placeY - 65)][(placeX - 1) + colocation] == 'S')
				{correct = 0; printf("\nThis place is used by another ship\n"); ship_counter--; break; }
				colocation++;
			}
			colocation = 0;
			//-
			if (correct == 1)
			{
				ships_coords->x = placeY - 65; ships_coords->y = placeX - 1; ships_coords->orientation = 'e'; ships_coords->size = ship_size; ships_coords++;

				while (colocation < ship_size)
				{map[(placeY - 65)][(placeX - 1) + colocation] = 'S'; colocation++; }
			}
			print_map(battlefield_size_a, battlefield_size_b, map);
			break;
		case 'w':
			//SEGURETAT - Baixell damunt un altre -> West
			while (colocation < ship_size)
			{
				ships_coords->x = placeY - 65; ships_coords->y = placeX - 1; ships_coords->orientation = 'w'; ships_coords->size = ship_size; ships_coords++;

				if (map[(placeY - 65)][(placeX - 1) - colocation] == 'S')
				{correct = 0; printf("\nThis place is used by another ship\n"); ship_counter--; break; }
				colocation++;
			}
			colocation = 0;
			//-
			if (correct == 1)
			{
				while (colocation < ship_size)
				{map[(placeY - 65)][(placeX - 1) - colocation] = 'S'; colocation++;
				}
			}
			print_map(battlefield_size_a, battlefield_size_b, map);
			break;
		}
	}
}

void set_enemy_ships(int battlefield_size_a, int battlefield_size_b, char **enemy_map)
{
	int no_ships = no_ships_function(battlefield_size_a, battlefield_size_b);

	int ship_size = 2;
	int ship_counter = 0;

	srand(time(NULL));

	while (ship_counter < no_ships)
	{
		if (ship_counter == 6){ ship_size++; }
		else if (ship_counter == 5){ ship_size++; }
		else if (ship_counter == 3){ ship_size++; }
		
		ship_counter++;

		int placeX = 0;
		int placeY = 0;
		char orientation = 'n';

		int colocation = 0; //parts of the ship placed
		int correct = 1; //is the ship placed in another ship?

		bool out_of_the_matrix = true;

		while (out_of_the_matrix == true)
		{
			//random values
			placeY = 65 + rand() % battlefield_size_a;

			placeX = 1 + rand() % battlefield_size_b;

			int orient = 1 + rand() % 4;
			//

			if (orient <= 1)
			{
				orientation = 'n';
			}
			else if (orient <= 2)
			{
				orientation = 's';
			}
			else if (orient <= 3)
			{
				orientation = 'e';
			}
			else if (orient <= 4)
			{
				orientation = 'w';
			}

			//SEGURETAT - fora de matrix
			switch (orientation)
			{
			case 'n':
				while (colocation < ship_size)
				{
					if (placeY - 65 - colocation + 1 > battlefield_size_a || placeY - 64 - colocation <= 0)
					{
						/*printf("\nYou are placing a ship out of the map\nPlease choose another position\n");*/ break;
						out_of_the_matrix = true;
					}
					else if ((colocation + 1) == ship_size)
					{out_of_the_matrix = false;} colocation++;
				}
				colocation = 0;
				break;
			case 's':
				while (colocation < ship_size)
				{
					if (placeY - 65 + colocation + 1 > battlefield_size_a || placeY - 64 + colocation <= 0)
					{
						/*printf("\nYou are placing a ship out of the map\nPlease choose another position\n");*/ break;
						out_of_the_matrix = true;
					}
					else if ((colocation + 1) == ship_size)
					{out_of_the_matrix = false;} colocation++;
				}
				colocation = 0;
				break;
			case 'e':
				while (colocation < ship_size)
				{
					if (placeX + colocation > battlefield_size_b || placeX + colocation <= 0)
					{
						/*printf("\nYou are placing a ship out of the map\nPlease choose another position\n");*/ break;
						out_of_the_matrix = true;
					}
					else if ((colocation + 1) == ship_size)
					{out_of_the_matrix = false;} colocation++;
				}
				colocation = 0;
				break;
			case 'w':
				while (colocation < ship_size)
				{
					if (placeX + colocation > battlefield_size_b || placeX - colocation <= 0)
					{
						/*printf("\nYou are placing a ship out of the map\nPlease choose another position\n"); */break;
						out_of_the_matrix = true;
					}
					else if ((colocation + 1) == ship_size)
					{out_of_the_matrix = false;}
					colocation++;
				}
				colocation = 0;
				break;
			}
			//-SEGURETAT - fora de la matrix
		}
		switch (orientation)
		{
		case 'n':
			//SEGURETAT - Baixell damunt un altre
			while (colocation < ship_size)
			{
				if (enemy_map[(placeY - 65) - colocation][(placeX - 1)] == 'S')
				{
					correct = 0;/* printf("\nThis place is used by another ship or it's out of the map\n"); */ship_counter--; break;
				}
				colocation++;
			}
			colocation = 0;
			//-
			if (correct == 1)
			{
				while (colocation < ship_size)
				{
					enemy_map[(placeY - 65) - colocation][(placeX - 1)] = 'S'; colocation++;
				}
			}
			break;
		case 's':
			//SEGURETAT - Baixell damunt un altre
			while (colocation < ship_size)
			{
				if (enemy_map[(placeY - 65) + colocation][(placeX - 1)] == 'S')
				{
					correct = 0; /*printf("\nThis place is used by another ship\n"); */ship_counter--; break;
				}
				colocation++;
			}
			colocation = 0;
			//-
			if (correct == 1)
			{
				while (colocation < ship_size)
				{
					enemy_map[(placeY - 65) + colocation][(placeX - 1)] = 'S';
					colocation++;
				}
			}
			break;
		case 'e':
			//SEGURETAT - Baixell damunt un altre
			while (colocation < ship_size)
			{
				if (enemy_map[(placeY - 65)][(placeX - 1) + colocation] == 'S')
				{
					correct = 0; /*printf("\nThis place is used by another ship\n");*/ ship_counter--; break;
				}
				colocation++;
			}
			colocation = 0;
			//-
			if (correct == 1)
			{
				while (colocation < ship_size)
				{
					enemy_map[(placeY - 65)][(placeX - 1) + colocation] = 'S'; colocation++;
				}
			}
			break;
		case 'w':
			//SEGURETAT - Baixell damunt un altre
			while (colocation < ship_size)
			{
				if (enemy_map[(placeY - 65)][(placeX - 1) - colocation] == 'S')
				{
					correct = 0;/* printf("\nThis place is used by another ship\n");*/ ship_counter--; break;
				}
				colocation++;
			}
			colocation = 0;
			//-
			if (correct == 1)
			{
				while (colocation < ship_size)
				{
					enemy_map[(placeY - 65)][(placeX - 1) - colocation] = 'S'; colocation++;
				}
			}
			break;
		}	
	}
}

void battle(int battlefield_size_a, int battlefield_size_b, char **map, char **enemy_map, char **second_map, char **second_enemy_map)
{
	srand(time(NULL));
	
	//general
	bool end = false;

	//IA
	bool normal_state = true;
	bool atack_state = false;
	bool found_ship = false;
	int atack_position_x;
	int atack_position_y;

	//player
	char word = 'a'; int number = 0;
	
	while (end == false)
	{
		for (int i = 0;; i++)
		{
			//Player Turn
			if (i % 2 == 0)
			{
				word = 'a'; number = 0;

				printf("\nIt's your turn\nChoose the coordenates(Ex: A 3): ");
				scanf_s(" %c", &word, 1); scanf_s("%d", &number);

				if (enemy_map[word - 65][number - 1] == 'H' || second_map[word - 65][number - 1] == 'M')
				{
					printf("\n You: have already shoot here\n");
				}
				if (enemy_map[word - 65][number - 1] == 'S')
				{
					printf("\n You: HIT\n");
					enemy_map[word - 65][number - 1] = 'H';
					second_map[word - 65][number - 1] = 'H';
				}
				else if (enemy_map[word - 65][number - 1] == 'E')
				{
					printf("\n You: FAIL\n"); 
					second_map[word - 65][number - 1] = 'M';
				}

				print_second_map(battlefield_size_a, battlefield_size_b, second_map);
				print_map(battlefield_size_a, battlefield_size_b, map);
			}

			//IA Turn
			else if (i % 2 == 1)
			{
				char word = 'c';
				int number = 0;
				printf("\nIt's the IA's turn\n");
				
				if (normal_state == true)
				{
					word = 65 + rand() % battlefield_size_a;
					number = 1 + rand() % battlefield_size_b;
				}
				else if (atack_state == true)
				{
					word = atack_position_x;
					number = atack_position_y;
					
					for (int i = -1; i < 2; i++)
					{
						for (int y = -1; y < 2; y++)
						{
							//fora del mapa?
							if ((word - 65 + i) <= battlefield_size_a && (word - 65 + i) >= 0 && number + i <= battlefield_size_b && number + i >= 0)
							{
								//ja esta ocupat?
								if (map[word - 65 + i][number - 1 + y] == 'S' && i != 2 && y != 2)
								{
									word += i;
									number += y;
									found_ship = true;
									break;
								}
							}
							
							if (found_ship == true){ break; }
						}
						if (found_ship == true){ break; }
					}
					if (found_ship == false)
					{
						word = 65 + rand() % battlefield_size_a;
						number = 1 + rand() % battlefield_size_b;
					}
					atack_state = false;
				}
				printf("IA's missile goes to %c %d\n", word, number);

				//printing
				if (map[word - 65][number - 1] == 'S')
				{
					printf("\n IA: HIT\n");
					map[word - 65][number - 1] = 'H';
					second_enemy_map[word - 65][number - 1] = 'H';
					
					atack_position_x = word;
					atack_position_y = number;

					normal_state = false;
					atack_state = true;
					found_ship = false;

					//ShipDead?
					ships_coords -= no_ships_function(battlefield_size_a, battlefield_size_b);

					int counter1 = 1;
					int counter2 = 0;
					int counter3 = 0;

					while (counter1 <= no_ships_function(battlefield_size_a, battlefield_size_b))
					{
						if (ships_coords->state == true)
						{
							switch (ships_coords->orientation)
							{
							case 'n':
								while (counter2 <= ships_coords->size)
								{
									if (map[(ships_coords->x) - counter2][(ships_coords->y)] == 'H')
									{
										counter3++;
									}
									counter2++;
								}
								break;
							case 's':
								while (counter2 <= ships_coords->size)
								{
									if (map[(ships_coords->x) + counter2][(ships_coords->y)] == 'H')
									{
										counter3++;
									}
									counter2++;
								}
								break;
							case 'e':
								while (counter2 <= ships_coords->size)
								{
									if (map[(ships_coords->x)][(ships_coords->y) + counter2] == 'H')
									{
										counter3++;
									}
									counter2++;
								}
								break;
							case 'w':
								while (counter2 <= ships_coords->size)
								{
									if (map[(ships_coords->x)][(ships_coords->y) - counter2] == 'H')
									{
										counter3++;
									}
									counter2++;
								}
								break;
							}
						}

						if (counter3 == ships_coords->size){ printf("\nIA: Ship destroyed\n"); ships_coords->state = false; }
						ships_coords++;
						counter1++;
					}
					//-Ship dead?

				}
				else if (map[word - 65][number - 1] == 'E')
				{
					printf("\n IA: FAIL\n"); 
					second_enemy_map[word - 65][number - 1] = 'M';

					normal_state = true;
					atack_state = false;
					found_ship = false;
				}

			

				print_second_map(battlefield_size_a, battlefield_size_b, second_map);
				print_map(battlefield_size_a, battlefield_size_b, map);
			}

			

			//EndState
			int count1 = 0;
			int count2 = 0;
			for (int i = 0; i < battlefield_size_a; i++)
			{
				for (int y = 0; y < battlefield_size_b; y++)
				{
					if (enemy_map[i][y] != 'S')
						count1++;
					if (map[i][y] != 'S')
						count2++;
				}
			}
			if (count1 == battlefield_size_a* battlefield_size_b)
			{
				printf("\nCongrats, you win\n");
				system("pause");
				end = true;
				break;
			}
			if (count2 == battlefield_size_a* battlefield_size_b)
			{
				printf("\nSorry, the IA wins\n");
				system("pause");
				end = true;
				break;
			}
			//-EndState

			system("pause"); printf("\n");
		}
	}
}

