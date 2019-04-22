#include "pch.h"
#include "room.hpp"

Room::Room()
{
}

Room::Room(std::string name, Passage *north, Passage *east, Passage *south, Passage *west)
{
	this->name = name;
	this->northPassage = north;
	this->eastPassage = east;
	this->southPassage = south;
	this->westPassage = west;
}

std::string Room::GetName()
{
	return this->name;
}

Passage * Room::GetNorthPassage()
{
	return this->northPassage;
}

Passage * Room::GetEastPassage()
{
	return this->eastPassage;
}

Passage * Room::GetSouthPassage()
{
	return this->southPassage;
}

Passage * Room::GetWestPassage()
{
	return this->westPassage;
}

void Room::AddItem(std::string item)
{
	this->items.push_back(item);
}

std::string Room::AcquireNextItem()
{
	std::string item = "";
	if (!this->items.size() == 0) {
		item = this->items.back(); 
		this->items.pop_back();
	}
	return item;
}
