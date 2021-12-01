#include<set>
#include<vector>
#include"InputNum.h"
#include"OutputNum.h"

class Lottery{
public:

	Lottery();

	void setInput(InputNum* t_input);
	void setOutput(OutputNum* t_output);
	void print(std::string const& t_string);
	std::vector<int> getNumbers();

	bool isValid() const;

	
private:
	InputNum* input;
	OutputNum* out;
	bool correct;
};
