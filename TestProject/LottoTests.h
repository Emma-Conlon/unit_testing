#pragma once
#include <set>
#include <assert.h>
//#include <TestFixture.h>
//#include <TestSuite.h>
//#include <TestAssert.h>
//#include <TestCase.h>
//#include <TestCaller.h>
#include "../ProductionProject/Production.h"//Lottory class :D 
#include "InputTest.h"

class LotteryTest  
{
public:

  

    void setUp();
    void tearDown();

    void checkForSixNumbers();
    void checkForSixNumbersMixedInput();
    void checkForInvalidInput();
    void checkNumberRange();
    void checkForRepeatingNumbers();

private:

    InputTest* input;
    Lottery* m_lottery;

};