#include "pch.h"
#include "passage.hpp"
#include<iostream>

Passage::Passage()
{
	this->isOpen = false;
	this->key = "";
}

Passage::Passage(bool isOpen)
{
	this->isOpen = isOpen;
}

Passage::Passage(bool isOpen, std::string key)
{
	this->isOpen = isOpen;
	this->key = key;
}

bool Passage::IsOpen()
{
	return this->isOpen;
}

bool Passage::RequiresKey()
{
	if (this->key == "") {
		return false;
	}
	return true;
}

std::string Passage::GetRequiredKey()
{
	return this->key;
}

void Passage::Open()
{
	this->isOpen = true;
}
