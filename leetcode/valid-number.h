#include <regex>
#include <string>

class Solution
{
public:
	bool isNumber(std::string s)
	{
		//1: 0 or 1 sign (-/+)
		//2. Either: (xx), (xx.xx), or (.xx)
		//3. Optional exponent (e10) followed by end of line
		//std::regex sequence("^( *)(\+|-)?(\d*|\d*\.\d*|\.\d*)(e(\+|-)?\d*)?( *)$");
		std::regex sequence(R"(^( *)(\+|-)?(\d+\.?\d*|\d*\.?\d+)(e(\+|-)?\d+)?( *)$)");
		return std::regex_match(s, sequence);
	}
};