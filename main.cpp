#ifdef _WIN32
	#define CLEAR "cls"
#else 
	#define CLEAR "clear"
#endif

#include <iostream>
#include <limits>

const bool DEBUG = false;

using namespace std;

const int MAZE_X = 9, MAZE_Y = 9;
int playerX = 1, playerY = 8;
int goalX = 7, goalY = 8;
const char GOAL_SYMBOL = '%';
const char PLAYER_SYMBOL = '@';

/*

Optional: 
	read maze from a file
	time taken
		scoreboard
	moves taken
		scoreboard
	multiplayer
	menu
		settings
			change controls
*/
char maze[MAZE_Y][MAZE_X] = {
	'#','#' ,'#','#' ,'#','#','#' ,'#' ,'#',
	'#',' ' ,' ',' ' ,'#',' ',' ' ,' ', '#',
	'#',' ' ,'#',' ' ,'#',' ','#' ,' ', '#',
	'#',' ' ,'#',' ' ,'#',' ','#' ,' ', '#',
	'#',' ' ,'#',' ' ,'#',' ','#' ,' ', '#',
	'#',' ' ,'#',' ' ,'#',' ','#' ,' ', '#',	// @ = player
	'#',' ' ,'#',' ' ,'#',' ','#' ,' ', '#',	// % = end goal
	'#',' ' ,'#',' ' ,' ',' ','#' ,' ', '#',
	'#',' ' ,'#','#' ,'#','#','#' ,' ' ,'#'
};

int InitialiseMaze()
{
	int success = 0;
	if(maze[playerY][playerX] != ' ') 
	{
		cout << "Error placing player... not in an empty tile!\n";
		success = -1;	
	}
	else maze[playerY][playerX] = PLAYER_SYMBOL;
	if(maze[goalY][goalX] != ' ')
	{		
		cout << "Error placing goal... not in an empty tile!\n";
		success = -1;
	}	
	else maze[goalY][goalX] = GOAL_SYMBOL;
	return success;
}

void UpdatePlayerLocation(int y, int x)
{
	if(DEBUG) cout << "Old player: y=" << playerY << " x=" << playerX << "\nNew player: y=" << y << " x=" << x << "\n";
	maze[playerY][playerX] = ' ';
	maze[y][x] = PLAYER_SYMBOL;
	playerY = y;
	playerX = x;
}

void HandleInput()
{
	char ch;
	cin >> ch;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear and reset
	}
	else
	{
		switch(ch)
		{
			case 'w':
				if(maze[playerY - 1][playerX] == ' ' || maze[playerY - 1][playerX] == GOAL_SYMBOL) UpdatePlayerLocation(playerY - 1, playerX);
				else
				{
					if(DEBUG) cout << "Can't go from [" << playerY << "," << playerX << "] to [" << playerY - 1 << "," << playerX << "]\nValue in [" << playerY - 1 << "," << playerX << "]: " << maze[playerY -1][playerX] << "\n";
				}
				break;
			case 'a':
				if(maze[playerY][playerX - 1] == ' ' || maze[playerY][playerX - 1] == GOAL_SYMBOL) UpdatePlayerLocation(playerY, playerX - 1);
				else
				{
					if(DEBUG) cout << "Can't go from [" << playerY << "," << playerX << "] to [" << playerY << "," << playerX - 1 << "]\nValue in [" << playerY << "," << playerX - 1<< "]: " << maze[playerY][playerX - 1] << "\n";
				}
				break;
			case 's':
				if(maze[playerY + 1][playerX] == ' ' || maze[playerY + 1][playerX] == GOAL_SYMBOL) UpdatePlayerLocation(playerY + 1, playerX);
				else
				{
					if(DEBUG) cout << "Can't go from [" << playerY << "," << playerX << "] to [" << playerY + 1 << "," << playerX << "]\nValue in [" << playerY + 1 << "," << playerX << "]: " << maze[playerY +1][playerX] << "\n";
				}
				break;
			case 'd':
				if(maze[playerY][playerX + 1] == ' ' || maze[playerY][playerX + 1] == GOAL_SYMBOL) UpdatePlayerLocation(playerY, playerX + 1);
				else
				{
					if(DEBUG) cout << "Can't go from [" << playerY << "," << playerX << "] to [" << playerY << "," << playerX + 1 << "]\nValue in [" << playerY << "," << playerX + 1 << "]: " << maze[playerY][playerX+1] << "\n";
				}
				break;
		}
	}
}

int CheckState()
{
	if(playerX == goalX && playerY == goalY) return 2;
	return 1;
}

void DrawMaze()
{
	cout << "  ";
	for(int x = 0; x < MAZE_X; x++) 
	{
		cout << " ";
		cout << x;
	}
	cout << "\n";
	for(int y = 0; y < MAZE_Y; y++)
	{
		cout << y << " ";		
		for(int x = 0; x < MAZE_X; x++) 
		{	
			cout << " ";
			cout << maze[y][x];
		}
		cout << "\n";	
	} 
}

int main()
{
	if(InitialiseMaze() == -1) return 0;
	int state = 1;
	while(state == 1)
	{
		system(CLEAR);
		DrawMaze();
		HandleInput();
		state = CheckState();
	}
	system(CLEAR);
	DrawMaze();
	cout << "You won!\n";
}
