#include "Production.h"


Lottery::Lottery() :
	input{ nullptr },
	out{ nullptr }
{
}

void Lottery::setInput(InputNum* t_input)
{
	input = t_input;
}

void Lottery::setOutput(OutputNum* t_output)
{
	out = t_output;
}

std::vector<int> Lottery::getNumbers()
{
	std::vector<int> numbers;

	if (input)
	{
		std::set<int> validNumbers;
		correct = true;

		while (validNumbers.size() < 6)
		{
			// Prompts for a number and takes an input.
			//print("Please enter a number between 1 and 46: ");
			int number = input->getInt();

			// Breaks if the inputted number is negative one.
			if (number == -1)
			{
				correct = false;
				print("\"-1\" Recieved, input cancelled.\n");
				break;
			}

			// If the number is within an acceptable range, adds it to the numbers.
			else if (number >= 1 && number <= 46)
			{
				int size = validNumbers.size();
				validNumbers.insert(number);

				// If the number is a duplicate, displays an error.
				if (validNumbers.size() == size)
					print("Duplicate number.\n");
			}

			// If the number is outside the range, displays an error.
			else print("Number out of Range.\nPlease select between 1 and 46\n");
		}

		// Adds all the valid numbers to the vector.
		for (int number : validNumbers)
			numbers.push_back(number);
	}

	return numbers;
}

bool Lottery::isValid() const
{
	return correct;
}

void Lottery::print(std::string const& t_string)
{
	if (out)
		out->print(t_string);
}
