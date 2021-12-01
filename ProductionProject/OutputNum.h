#pragma once

#include <string>

/// <summary>
/// outputs the number
/// </summary>
class OutputNum
{
public:
	virtual void print(std::string const& t_string) = 0;//pure virtual function
};