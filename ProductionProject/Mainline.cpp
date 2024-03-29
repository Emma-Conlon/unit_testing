
#include <iostream>
#include <limits>
#include <vector>

#include "Production.h"
#include "CmdInput.h"
#include "CmdOutput.h"

const auto LineLimit = std::numeric_limits<std::streamsize>::max();

int main()
{
	std::cout << "Please select your Lotto Numbers between 1 and 46: ";
	// Creates and sets up the input, output, and lottery.
	CmdInput input;
	CmdOutput output;
	Lottery lottery;
	lottery.setInput(&input);
	lottery.setOutput(&output);

	// Gets and prints the lotto numbers.
	std::vector<int> numbers = lottery.getNumbers();

	system("cls");
	std::cout << "The lotto numbers are: ";

	for (int number : numbers)
		std::cout << number << " ";

	// Prints whether the lotto is valid or not (got enough inputs).
	if (lottery.isValid())
		std::cout << "\nThe lotto is valid.";
	else
		std::cout << "\nThe lotto is invalid.";

	// Pauses for input.
	std::cout << "\n\nPress enter to exit...";
	std::cin.ignore(LineLimit, '\n');
	std::cin.get();

	return 0;
}