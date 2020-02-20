#include <vector>
#include <numeric>
/* Problem 1281.
Given an integer number n, return the difference between the product of its digits and the sum of its digits.

*/


class Solution
{
public:
	int subtractProductAndSum(int n)
	{
		//Step 1: Get all of the digits into a vector
		std::vector<int> digits;
		while (n > 0)
		{
			digits.push_back(n % 10);
			n /= 10;
		}
		//Step 2: Find product of all digits
		int product = digits[0];
		for (int i = 1; i < digits.size(); ++i)
		{
			product *= digits[i];
		}
		//Step 3: Find the sum of all the digits
		int sum = std::accumulate(digits.begin(), digits.end(), 0);
		//Step 4: Return the difference
		return product - sum;
	}
};