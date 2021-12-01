#include <iostream>
#include <assert.h>
#include"LottoTests.h"
#include "../ProductionProject/Production.h"

using namespace std;

int main()
{
	Lottery p;
	LotteryTest l;


	l.checkForInvalidInput();
	l.checkForRepeatingNumbers();
	l.checkForSixNumbers();
	l.checkNumberRange();
	l.checkForSixNumbersMixedInput();
	
	//assert(l.checkForInvalidInput() == 0);
	//assert(p.someMethod(a) == 1);
	cin.get();
}