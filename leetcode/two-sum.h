#include <vector>
#include <iostream>


class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		std::vector<int> useful;
		std::vector<int> solution;

		//For each number in nums
		for (int i = 0; i < nums.size(); ++i)
		{
			//Compare it with all the valid numbers so far
			for (auto& index : useful)
				//If a solution is found, return it
				if (nums[index] + nums[i] == target)
				{
					solution = { index, i };
					break;
				};
			//If not, add this index to the "potential solutions" list and go to the next number
			useful.push_back(i);
		}
		return solution;
	}
};