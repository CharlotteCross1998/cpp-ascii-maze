[![Build Status](https://travis-ci.org/charlottecross1998/cpp-ascii-maze.svg?branch=master)](https://travis-ci.org/charlottecross1998/cpp-ascii-maze)

# cpp-ascii-maze
Simple ascii maze template in C++. 

# How you can contribute

- Add a function to read a maze from a file
	- Make the file a custom format which can read a maze, player & goal symbol & coordinates.
- Main menu
	- Settings
		- Controls
	- Highscores
		- Time taken
		- Moves done etc.
	- New Game
		- Load Game
		- Save State System
	- Multiplayer (Although I doubt anyone would implement this)
	- Change Map
		: Would probably use a vector instead of an array in that case
- Readable code that beginners can read.

# How it works

Make a maze in the maze char array (or optionally make it read in a maze from a file)

Set the player and the goal coordinates, the program will detect if they are invalid or not.

The program detects for a space and the end goal symbol when moving, so as long as the end goal and a free space aren't the same as the walls, the walls can be whatever symbol. I prefer to use '#' for the walls.

The player can move via wasd. 
