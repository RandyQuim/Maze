#pragma once
#ifndef GAME_HPP
#define GAME_HPP
#include "maze.hpp"
#include "player.hpp"
#include "room.hpp"

class Game {
public:
	Game(Maze*, Player*);
	void DisplayItems();
	void DisplayPassages();
	std::string GetCurrentRoomName();
	void LootRoom();
	bool ValidDirection(std::string direction);
	void MoveDirection(std::string direction);
	bool ExitFound();
private:
	Maze* maze;
	Player* player;
	Room* currentRoom;
	std::vector<std::string> currentItems;

	std::string GetPassageDescription(Passage*);
	void MoveNorth();
	void MoveEast();
	void MoveSouth();
	void MoveWest();
};
#endif
