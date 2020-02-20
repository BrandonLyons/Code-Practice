#include <vector>
class Solution
{
public:
	/*
	Problem:
	We are given a list 'nums' of integers representing a list compressed with run-length encoding.

	Consider each adjacent pair of elements [a, b] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are a elements with value b in the decompressed list.

	Return the decompressed list.

	Input: nums = [1,2,3,4]
	Output: [2,4,4,4]
	Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
	The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
	At the end the concatenation [2] + [4,4,4,4] is [2,4,4,4]. <-- this seems like a typo, should be [2] + [4,4,4] = [2,4,4,4]

	*/
	std::vector<int> decompressRLElist(std::vector<int>& nums)
	{
		std::vector<int> result;
		for (int i = 0; i < nums.size(); i += 2)
			for (int j = 0; j < nums[i]; ++j)
				result.push_back(nums[i + 1]);
		return result;
	}
};