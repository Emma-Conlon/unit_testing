
#include <iostream>
#include "OutputNum.h"

class CmdOutput : public OutputNum
{
public:

	virtual void print(std::string const& t_string) override;

};
