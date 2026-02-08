#include <iostream>
//#include <utility>
#include "ttt_functions.hpp"

int main()
{
	int num_of_plays = 0; 
	char input;
	std::string grid;
	
	char ttt_grid[3][3]= 
	{
	{' ',' ',' '},
	{' ',' ',' '},
	{' ',' ',' '}
	};
	
	// Introduction and Instructions to the game
	instructions();
	std::cout<< "\n\n";
	
	while (num_of_plays < 9)
	{
	// Switch Players
	input = switch_player(num_of_plays);
	
	// live player grid selection and board placement
	std::cin >> grid;
	std::cout << "\n\n";
	
	if (grid_placement(grid).first && grid_placement(grid).second == 3)
	{
		std::cout << "GRID DOES NOT EXIST\n\n";
		num_of_plays--;	
	}
	
	else if (ttt_grid[grid_placement(grid).first][grid_placement(grid).second] != ' ')
	{
		std::cout << "GRID ALREADY OCCUPIED\nTRY ANOTHER GRID\n\n";
		num_of_plays--;		
	}
	
	else 
	{
		ttt_grid[grid_placement(grid).first][grid_placement(grid).second] = input;
	}
	
	// Display Live Board Play and Choosing Game Winner
	if (game_outcome(ttt_grid) == true)
	{
		break;
	}
	
	else
	{
		num_of_plays++;
	}
	
	if (num_of_plays == 9)
	{
		std::cout << ("This game is a draw\n");
		break;
	}
	}
return 0;
}