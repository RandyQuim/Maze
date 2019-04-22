#pragma once  // get rid of pragma once
#ifndef PASSAGE_HPP
#define PASSAGE_HPP
#include<iostream>

class Passage{
public:
	Passage();
	Passage(bool isOpen);
	Passage(bool isOpen, std::string key);
	bool IsOpen();
	bool RequiresKey();
	std::string GetRequiredKey();
	void Open();
private:
	bool isOpen;
	std::string key;
};

#endif