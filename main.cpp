#include <iostream>
#include <limits>
#include <ncurses.h>

const bool DEBUG = false;

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

bool InitialiseMaze()
{
	if(maze[playerY][playerX] != ' ') 
	{
		printw("Error placing player... not in an empty tile!\n");
		return false;
	}
	else maze[playerY][playerX] = PLAYER_SYMBOL;
	if(maze[goalY][goalX] != ' ')
	{		
		printw("Error placing goal... not in an empty tile!\n");
		return false;
	}	
	else maze[goalY][goalX] = GOAL_SYMBOL;
	return true;
}

void UpdatePlayerLocation(int y, int x)
{
	if(DEBUG) printw("Old player: y=%d x=%d\nNew player: y=%d x=%d\n", playerY, playerX, y, x);
	maze[playerY][playerX] = ' ';
	maze[y][x] = PLAYER_SYMBOL;
	playerY = y;
	playerX = x;
}

void HandleInput()
{
	char ch = getch();
	switch(ch)
	{
		case 'w':
			if(maze[playerY - 1][playerX] == ' ' || maze[playerY - 1][playerX] == GOAL_SYMBOL) UpdatePlayerLocation(playerY - 1, playerX);
			else
			{
				if(DEBUG) printw("Can't go from [%d,%d] to [%d,%d]\nValue in [%d,%d]: %c\n", playerY, playerX, playerY - 1, playerX, playerY - 1, playerX, maze[playerY - 1][playerX]);
			}
			break;
		case 'a':
			if(maze[playerY][playerX - 1] == ' ' || maze[playerY][playerX - 1] == GOAL_SYMBOL) UpdatePlayerLocation(playerY, playerX - 1);
			else
			{
				if(DEBUG) printw("Can't go from [%d,%d] to [%d,%d]\nValue in [%d,%d]: %c\n", playerY, playerX, playerY, playerX - 1, playerY, playerX - 1, maze[playerY][playerX - 1]);
			}
			break;
		case 's':
			if(maze[playerY + 1][playerX] == ' ' || maze[playerY + 1][playerX] == GOAL_SYMBOL) UpdatePlayerLocation(playerY + 1, playerX);
			else
			{
				if(DEBUG) printw("Can't go from [%d,%d] to [%d,%d]\nValue in [%d,%d]: %c\n", playerY, playerX, playerY + 1, playerX, playerY + 1, playerX, maze[playerY + 1][playerX]);
			}
			break;
		case 'd':
			if(maze[playerY][playerX + 1] == ' ' || maze[playerY][playerX + 1] == GOAL_SYMBOL) UpdatePlayerLocation(playerY, playerX + 1);
			else
			{
				if(DEBUG) printw("Can't go from [%d,%d] to [%d,%d]\nValue in [%d,%d]: %c\n", playerY, playerX, playerY, playerX + 1, playerY, playerX + 1, maze[playerY][playerX + 1]);
			}
			break;
	}
}

bool CheckState()
{
	if(playerX == goalX && playerY == goalY) return true;
	return false;
}

void DrawMaze()
{
	printw("  ");
	for(int x = 0; x < MAZE_X; x++) 
	{
		printw(" %d", x);
	}
	printw("\n");
	for(int y = 0; y < MAZE_Y; y++)
	{
		printw("%d ", y);		
		for(int x = 0; x < MAZE_X; x++) 
		{	
			printw(" %c", maze[y][x]);
		}
		printw("\n");
	} 
	refresh();
}

int main()
{
	if(!InitialiseMaze()) return 0;
	initscr();
	raw();
	noecho();
	while(!CheckState())
	{
		clear();
		DrawMaze();
		HandleInput();
	}
	clear();
	DrawMaze();
	endwin();
	std::cout << "You won!\n";
	return 1;
}
