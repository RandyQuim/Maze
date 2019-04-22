#include "pch.h"
#include "game.hpp"
#include<string>

Game::Game(Maze *maze, Player *player)
{
	this->maze = maze;
	this->player = player;
	this->player->SetPosition(0, 0);
	this->currentRoom = maze->GetRoom(0, 0);
}

void Game::DisplayItems()
{
	int counter = 0;
	std::string pickUp = "";
	if (currentItems.empty()) {
		std::cout << "There are no objects";
	}
	else {
		pickUp = " You picked up the item(s)!";
		while (!this->currentItems.empty()) {
			if (counter < 1) {
				std::cout << "There is a(n) " << currentItems.back();
				currentItems.pop_back();
			}
			else {
				std::cout << " and a(n) " << currentItems.back();
				currentItems.pop_back();
				break;
			}

			++counter; 
		}
	}

	std::cout << " in this room." << pickUp << std::endl;
}

void Game::DisplayPassages()
{
	std::cout << GetPassageDescription(currentRoom->GetNorthPassage()) << " to the North." << std::endl;
	std::cout << GetPassageDescription(currentRoom->GetEastPassage()) << " to the East." << std::endl;
	std::cout << GetPassageDescription(currentRoom->GetSouthPassage()) << " to the South." << std::endl;
	std::cout << GetPassageDescription(currentRoom->GetWestPassage()) << " to the West." << std::endl;
}

std::string Game::GetCurrentRoomName()
{
	return this->currentRoom->GetName();
}

void Game::LootRoom()
{
	std::string item = this->currentRoom->AcquireNextItem();
	while (item != "") {
		player->AddItem(item);
		currentItems.push_back(item);
		item = currentRoom->AcquireNextItem();
	}
}

bool Game::ValidDirection(std::string direction)
{
	if ((direction == "N" && this->currentRoom->GetNorthPassage()->IsOpen())
		|| (direction == "E" && this->currentRoom->GetEastPassage()->IsOpen())
		|| (direction == "S" && this->currentRoom->GetSouthPassage()->IsOpen())
		|| (direction == "W" && this->currentRoom->GetWestPassage()->IsOpen())) 
	{  
		return true;
	}
	return false;
}

void Game::MoveDirection(std::string direction)
{
	if (direction == "N" && (ValidDirection(direction) || player->HasItem(currentRoom->GetNorthPassage()->GetRequiredKey()))) {
		MoveNorth();
	}
	else if (direction == "E" && (ValidDirection(direction) || player->HasItem(currentRoom->GetEastPassage()->GetRequiredKey()))) {
		MoveEast();
	} 
	else if (direction == "S" && (ValidDirection(direction) || player->HasItem(currentRoom->GetSouthPassage()->GetRequiredKey()))) {
		MoveSouth();
	}
	else if (direction == "W" && (ValidDirection(direction) || player->HasItem(currentRoom->GetWestPassage()->GetRequiredKey()))) {
		MoveWest();
		
	}
	else if (direction == "Q") {
		std::cout << "Better luck next time!" << std::endl;
	} 
	else
		std::cout << "You can't go that way!" << std::endl;
}

bool Game::ExitFound()
{
	if (((player->GetCol() + 1 == maze->GetNumberCols()) && ValidDirection("E"))
		|| ((player->GetCol()  == 0) && ValidDirection("W"))
		|| ((player->GetRow() + 1 == maze->GetNumberRows()) && ValidDirection("S"))
		|| ((player->GetRow() == 0) && ValidDirection("N"))) 
	{
		return true;  
	}
	
	return false;
}

std::string Game::GetPassageDescription(Passage *passage)
{
	std::string description = "There is a(n) ";
	if (passage->RequiresKey()) {
		description += "doorway that requires a(n) " + passage->GetRequiredKey();
	}
	else if (passage->IsOpen()) { 
		description += "open doorway";
	}
	else {
		description += "solid wall";
	}
	return description;
}

void Game::MoveNorth()
{
	player->IncrementMoves();
	player->UseItem(currentRoom->GetNorthPassage()->GetRequiredKey());
	player->SetPosition(player->GetRow() - 1, player->GetCol());
	this->currentRoom = maze->GetRoom(player->GetRow(), player->GetCol());
	this->currentRoom->GetSouthPassage()->Open();
}

void Game::MoveEast()
{
	player->IncrementMoves();
	player->UseItem(currentRoom->GetEastPassage()->GetRequiredKey());
	player->SetPosition(player->GetRow(), player->GetCol() + 1);
	this->currentRoom = maze->GetRoom(player->GetRow(), player->GetCol());
	this->currentRoom->GetWestPassage()->Open();
}

void Game::MoveSouth()
{
	player->IncrementMoves();
	player->UseItem(currentRoom->GetSouthPassage()->GetRequiredKey());
	player->SetPosition(player->GetRow() + 1, player->GetCol());
	this->currentRoom = maze->GetRoom(player->GetRow(), player->GetCol());
	this->currentRoom->GetNorthPassage()->Open();
}

void Game::MoveWest()
{
	player->IncrementMoves();
	player->UseItem(currentRoom->GetWestPassage()->GetRequiredKey());
	player->SetPosition(player->GetRow(), player->GetCol() - 1);
	this->currentRoom = maze->GetRoom(player->GetRow(), player->GetCol());
	this->currentRoom->GetEastPassage()->Open();
}
