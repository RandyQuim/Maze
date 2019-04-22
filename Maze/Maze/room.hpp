#pragma once
#ifndef ROOM_HPP
#define ROOM_HPP
#include "passage.hpp"
#include<vector>
#include<string>

class Room {
public:
	Room();
	Room(std::string name, Passage*, Passage*, Passage*, Passage*);
	std::string GetName();
	Passage* GetNorthPassage();
	Passage* GetEastPassage();
	Passage* GetSouthPassage();
	Passage* GetWestPassage();

	void AddItem(std::string item);
	std::string AcquireNextItem();
private:
	std::string name;
	std::vector<std::string> items;
	Passage* northPassage;
	Passage* eastPassage;
	Passage* southPassage;
	Passage* westPassage;
};

#endif
