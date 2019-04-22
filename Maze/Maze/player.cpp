#include "pch.h"
#include "player.hpp"
#include<string>
#include<iostream>

Player::Player()
{
	this->row = 0;
	this->col = 0;
}

int Player::GetRow()
{
	return this->row;
}

int Player::GetCol()
{
	return this->col;
}

void Player::SetPosition(int row, int col)
{
	this->row = row;
	this->col = col;
}

void Player::AddItem(std::string item)
{
	this->items.push_back(item);
}

bool Player::HasItem(std::string item)
{
	for (int i = 0; i < items.size(); i++) {
		if (this->items.at(i) == item) {
			return true;
		}
	}
	return false;
}

void Player::UseItem(std::string item)
{
	for (int i = 0; i < items.size(); i++) {
		if (this->items.at(i) == item) {

			for (int j = i; j < (items.size() - i - 1); j++) {
				items.at(j) = items.at(j + 1);
			}
			
			items.pop_back();
		}
	}
}

int Player::GetMoveCount()
{
	return this->moves;
}

void Player::IncrementMoves()
{
	++this->moves;
}
