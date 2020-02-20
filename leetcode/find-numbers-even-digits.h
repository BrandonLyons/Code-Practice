#include <vector>
/* Problem 1295:
Given an array 'nums' of integers, return how many of them contain an even number of digits
*/


class Solution
{
public:
	int findNumbers(std::vector<int>& nums)
	{
		int count = 0;
		int digits = 0;
		//Step 1: For each number in the list
		for (auto& num : nums)
		{
			digits = 0;
			//Step 2: Find the number of digits
			while (num > 0)
			{
				digits++;
				num /= 10;
			}
			//Step 3: If it has an even number of digits, increment the list
			if (digits % 2 == 0)
				count++;
		}

		return count;
	}
};