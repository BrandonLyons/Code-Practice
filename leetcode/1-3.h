
/*
1.3: Given two strings, write a method to decide if one is a permutation of the other.

Okay, first off, what constitutes a permutation? I'd say it's that they have the same amount and types of characters.

Solution:
We'll use an unordered_map (i.e. hash map) pointing from characters to integers (amounts). Iterate through the first string, adding 1 to the appropriate character index of the unordered_map for each character. Then for the second string, we remove those same characters from the map 1 by 1 until we've finished the string.
There's one optimization we can make - for one string to be a permutation of the other, they need to have the same length. If they don't we can just return false.
One requirement I should've clarified at first - does capitalization matter?

Actual solution:
This! Exactly this! Line for line. I made some stupid mistakes with the indices that would've given me a bug, but I was exactly right. I also didn't consider whether white space was significant, but I assumed it was, and so did the book. I did realize that capitalization might matter, but not until I was nearly done. That should've come up when clarifying requirements in the beginning. But good job!

*/

#include <string>

class Solution
{
public:
	bool isPermutation(std::string s1, std::string s2)
	{
		if (s1.length() != s2.length()) return false;
		int count[256] = {0};
		for (int i = 0; i < s1.length(); ++i)
			count[s1[i] - '0']++;
		for (int i = 0; i < s2.length(); ++i)
		{
			count[s2[i] - '0']--;
			if (count[s2[i] - '0'] < 0)
				return false;
		}
		return true;
	}
};