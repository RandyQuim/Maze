#pragma once
#ifndef MAZE_HPP
#define MAZE_HPP
#include "room.hpp"
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

class Maze {
public:
	Maze(std::string mazeFile);
	~Maze();
	Room* GetRoom(int row, int col);
	int GetNumberRows();
	int GetNumberCols();
private:
	Room** rooms;
	int rows;
	int cols;
	std::ifstream mazeFile;

	void LoadMaze();
	Passage* CreatePassage(std::string type);
};

#endif
