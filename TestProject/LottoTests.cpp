#include "LottoTests.h"

void LotteryTest::setUp()
{
		// Creates the test input.
	   input = new InputTest();

		// Creates a new lottery object and initialises it with the test input.
		m_lottery = new Lottery();
		m_lottery->setInput(input);
}

void LotteryTest::tearDown()
{
	delete m_lottery;
	delete input;
}

void LotteryTest::checkForSixNumbers()
{
	input->setReturnValues({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
	
	// Checks that the size is equal to 6.
	assert(m_lottery->getNumbers().size() == 6);
	assert(m_lottery->isValid() == true);
}

void LotteryTest::checkForSixNumbersMixedInput()
{
	input->setReturnValues({ 1, -5, 2, 0, 4, 100, 8, 420, 7, 9 });

	// Checks that the size is equal to 6.
	assert(m_lottery->getNumbers().size() == 6);
	assert(m_lottery->isValid() == true);
}

void LotteryTest::checkForInvalidInput()
{
	// Initialises the test input with less than 6 values.
	input->setReturnValues({ 1, 2, 3 });

	// Checks that the size is equal to 3.
	assert(m_lottery->getNumbers().size() == 3);
	assert(m_lottery->isValid() == false);

}

void LotteryTest::checkNumberRange()
{

input->setReturnValues({ -5, 2, 0, 4, 100, 420, 7, 8, 9, 10 });

	// Gets the lotto numbers.
	std::vector<int> numbers = m_lottery->getNumbers();

	
	for (int number : numbers)
		assert(number >= 0 && number <= 46);

	assert(m_lottery->isValid() == true);
}

void LotteryTest::checkForRepeatingNumbers()
{
	// Initialises the test input with 6 valid values + duplicates.
	input->setReturnValues({ 1, 1, 1, 10, 4, 4, 7, 40, 34, 40, 9, 10 });

	// Gets the lotto numbers.
	std::vector<int> numbers = m_lottery->getNumbers();

	// Asserts that all returned numbers are unique.
	std::set<int> checkedNumbers;
	for (int number : numbers)
	{
		// Adds the number to the set and check that the size increased.
		// Sets can only have one of each number, if a duplicate is added, the 
		//		size will not increase.
		size_t numCheckedNumbers = checkedNumbers.size();
		checkedNumbers.insert(number);
		assert(numCheckedNumbers + 1 == checkedNumbers.size());
	}

	assert(m_lottery->isValid() == true);
}
