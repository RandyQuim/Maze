#include "pch.h"
#include "maze.hpp"

Maze::Maze(std::string mazeFile)
{
	this->mazeFile.open(mazeFile);
	if (!this->mazeFile.is_open()) {
		std::cout << "Unable to open file!" << std::endl;
	}
	LoadMaze();
}

Maze::~Maze()
{
	for (int i = 0; i < rows; i++) {
		delete[] rooms[i];
	}
	delete[] rooms;
}

Room * Maze::GetRoom(int row, int col)
{
	return &this->rooms[row][col];
}

int Maze::GetNumberRows()
{
	return this->rows;
}

int Maze::GetNumberCols()
{
	return this->cols;
}

void Maze::LoadMaze()
{
	std::string fileInput = "";
	std::string field = "";
	std::vector<std::string> v;
	
	this->mazeFile >> this->rows;
    rooms = new Room*[this->rows];
	this->mazeFile >> this->cols;
	// Get rid of nextline character
	std::getline(this->mazeFile, fileInput);

	for (int i = 0; i < this->rows; i++) {
		rooms[i] = new Room[this->cols];

		for (int j = 0; j < this->cols; j++) {
			std::getline(this->mazeFile, fileInput);
			std::istringstream line(fileInput);

			while (std::getline(line, field, ',')) {
				v.push_back(field);
			}

			rooms[i][j] = Room(v.at(0), CreatePassage(v.at(1)), CreatePassage(v.at(2)), CreatePassage(v.at(3)), CreatePassage(v.at(4)));

			if (!(v.back() == "+" || v.back() == "-")) {
				std::istringstream items(v.back());
				v.pop_back();
				while (items >> field) {
					rooms[i][j].AddItem(field);
				}
			}
			v.erase(v.begin(), v.end());
		}		
	}
}

Passage * Maze::CreatePassage(std::string type)
{
	Passage* passage;
	if (type == "-") {
		passage = new Passage(false);
	}
	else if (type == "+"){
		passage = new Passage(true);
	}
	else {
		passage = new Passage(false, type);
	}

	return passage;
}
