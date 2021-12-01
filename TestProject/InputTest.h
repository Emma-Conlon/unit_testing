#pragma once
#include <vector>
#include "../ProductionProject/InputNum.h"
class InputTest : public InputNum
{
	public:

		void clearReturnValues();

		void setReturnValues(std::initializer_list<int> const& t_returnValues);

		virtual int getInt() override;

	private:

		std::vector<int> m_returnValues;


};

