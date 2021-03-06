// Maze.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "maze.hpp"
#include "player.hpp"
#include "game.hpp"
#include <iostream>
#include<string>

using namespace std;

int main()
{
	string fileName = "";
	string direction = "";
	bool quit = false;
	cout << "Welcome to the maze!" << endl;
	cout << "Please enter the filename of your maze: ";
	cin >> fileName;
	cout << "\nEnter 'Q' to quit at any time." << endl;

	Maze* newMaze = new Maze(fileName);
	Player* newPlayer = new Player();
	newPlayer->SetPosition(0, 0);
	Game newGame(newMaze, newPlayer);
	cout << endl;

	while (!quit) {
		std::cout << "You are in " << newGame.GetCurrentRoomName() << "!" << std::endl;
		newGame.LootRoom();
		newGame.DisplayItems();
		newGame.DisplayPassages();
		cout << "Which way would you like to move? ";
		cin >> direction;
		if (direction == "Q") {
			quit = true;
		}
		else if (newGame.ValidDirection(direction) && newGame.ExitFound()) {
			// After ensuring the room is an exit room (done above), the following checks the user's chosen
			// direction and whether it exceeds the total number of columns/rows (meaning legal exit)
			if (direction == "E" && newPlayer->GetCol() + 1 == newMaze->GetNumberCols()
				|| direction == "W" && newPlayer->GetCol() == 0
				|| direction == "N" && newPlayer->GetRow() == 0
				|| direction == "S" && newPlayer->GetRow() + 1 == newMaze->GetNumberRows()) 
			{
				cout << "It took you " << newPlayer->GetMoveCount() << " moves, but your free!" << endl;
				break;
			}							
		}				
		newGame.MoveDirection(direction);
		cout << endl;
	}
}
