# cpp-ascii-maze
Simple ascii maze template in C++. 

# How it works

Make a maze in the maze char array (or optionally make it read in a maze from a file)

Set the player and the goal coordinates, the program will detect if they are invalid or not.

The program detects for a space and the end goal symbol when moving, so as long as the end goal and a free space aren't the same as the walls, the walls can be whatever symbol. I prefer to use '#' for the walls.

The player can move via wasd. 
