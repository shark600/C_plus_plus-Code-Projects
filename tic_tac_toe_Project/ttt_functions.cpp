#include <iostream>
//#include <utility>

// defining functions
	
//Introduction and Instructions
void instructions()
{
	//Introduction
	std::cout << "=============\n";
	std::cout << "TIC-TAC-TOE: The Board Game\n";
	std::cout << "=============\n\n";
	//Instructions
	std::cout << "INSTRUCTIONS:\n";
	std::cout << "-------------\n\n";
	std::cout<< "X is assigned to Player 1\nO is assigned to Player 2\n";
	std::cout<< "\n\n"; 
	
	// Prompt to place 'X' or 'O' on a particlular grid on the board
	std::cout<< "To play on a particular grid on the board use the following prompts:\n\n";
	/* Top Grid */
	std::cout<< "For top-right grid of the board, enter:\t\ttr\n";
	std::cout<< "For top-middle grid of the board, enter:\ttm\n";
	std::cout<< "For top-left grid of the board, enter:\t\ttl\n";
	
	/* Middle Grid */
	std::cout<< "For middle-right grid of the board, enter:\tmr\n";
	std::cout<< "For middle-middle grid of the board, enter:\tmm\n";
	std::cout<< "For middle-left grid of the board, enter:\tml\n";
	
	/* Bottom Grid */
	std::cout<< "For bottom-right grid of the board, enter:\tbr\n";
	std::cout<< "For bottom-middle grid of the board, enter:\tbm\n";
	std::cout<< "For bottom-left grid of the board, enter:\tbl\n";
return;
}
	
// switching players
char switch_player(int num_of_plays)
{
	char input;
	
	if (num_of_plays == 0 || num_of_plays == 2 || num_of_plays == 4 || num_of_plays == 6 || num_of_plays == 8)
	{
		//assigning a varaible to Player 1
		std::cout<< "Player 1, choose a position on the grid to play:\t";
		input = 'X';
	}
	else
	{
		//assigning a varaible to Player 2
		std::cout<< "Player 2, choose a position on the grid to play:\t";
		input = 'O';
	}
return input;
}
	
	
// Choosing a grid location on the board to play
std::pair<int,int> grid_placement(std::string grid)
{
	int row;
	int col;
	
	// Top Grid
	if (grid == "tl")
	{
		row = 0;
		col = 0;
	}
	
	else if (grid == "tm")
	{
		row = 0;
		col = 1;
	}
	
	else if (grid == "tr")
	{
		row = 0;
		col = 2;
	}
		
	// Middle Grid
	else if (grid == "ml")
	{
		row = 1;
		col = 0;
	}
	
	else if (grid == "mm")
	{
		row = 1;
		col = 1;
	}	

	else if (grid == "mr")
	{
		row = 1;
		col = 2;	
	}		
	
	// Bottom Grid
	else if (grid == "bl")
	{
		row = 2;
		col = 0;
	}			
	
	else if (grid == "bm")
	{
		row = 2;
		col = 1;
	}				
	
	else if (grid == "br")
	{
		row = 2;
		col = 2;
	}			

	else
	{
		row = 3;
		col = 3;	
	}
return std::make_pair(row,col);
}
	
bool game_outcome(char ttt_grid[3][3])
{
	bool is_there_a_winner;
	
	// Display Live Board Play
	for (int ii = 0; ii < 3; ii++)
		{
			for (int jj = 0; jj < 3; jj++)
			{
			std::cout << ttt_grid[ii][jj]<<"\t";
			}
		std::cout <<"\n\n\n\n";
		}
	// Choose the winner	
	if (
	ttt_grid[0][0] == 'X' && ttt_grid[0][1] == 'X' && ttt_grid[0][2] == 'X' || ttt_grid[1][0] == 'X' && ttt_grid[1][1] == 'X' && ttt_grid[1][2] == 'X' || ttt_grid[2][0] == 'X' && ttt_grid[2][1] == 'X' && ttt_grid[2][2] == 'X' || ttt_grid[0][0] == 'X' && ttt_grid[1][0] == 'X' && ttt_grid[2][0] == 'X' || ttt_grid[0][1] == 'X' && ttt_grid[1][1] == 'X' && ttt_grid[2][1] == 'X' || ttt_grid[0][2] == 'X' && ttt_grid[1][2] == 'X' && ttt_grid[2][2] == 'X' || ttt_grid[0][0] == 'X' && ttt_grid[1][1] == 'X' && ttt_grid[2][2] == 'X' || ttt_grid[0][2] == 'X' && ttt_grid[1][1] == 'X' && ttt_grid[2][0] == 'X')
	{
		std::cout << ("Player 1 is the winner of this game\n");
		is_there_a_winner = true;
	}
	
	else if (	
	ttt_grid[0][0] == 'O' && ttt_grid[0][1] == 'O' && ttt_grid[0][2] == 'O' || ttt_grid[1][0] == 'O' && ttt_grid[1][1] == 'O' && ttt_grid[1][2] == 'O' || ttt_grid[2][0] == 'O' && ttt_grid[2][1] == 'O' && ttt_grid[2][2] == 'O' || ttt_grid[0][0] == 'O' && ttt_grid[1][0] == 'O' && ttt_grid[2][0] == 'O' || ttt_grid[0][1] == 'O' && ttt_grid[1][1] == 'O' && ttt_grid[2][1] == 'O' || ttt_grid[0][2] == 'O' && ttt_grid[1][2] == 'O' && ttt_grid[2][2] == 'O' || ttt_grid[0][0] == 'O' && ttt_grid[1][1] == 'O' && ttt_grid[2][2] == 'O' || ttt_grid[0][2] == 'O' && ttt_grid[1][1] == 'O' && ttt_grid[2][0] == 'O')
	{
		std::cout << ("Player 2 is the winner of this game\n");
		is_there_a_winner = true;
	}
	
	else
	{
	is_there_a_winner = false;
	}
	
return is_there_a_winner;
}