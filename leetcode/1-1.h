/*
1.1: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

Breakdown:
We have a string (i.e. an array of characters). We want to see if any values are repeated. As soon as a value is repeated, we return false.

Solution 1:
Iterate through each character, adding it to a hash map of "known characters". As soon as we find a repeat, return false. Otherwise return true.
Space: O(2n) i.e. O(n)
Runtime: O(n)
On each character we're doing a search of the hash map and then an insertion. Those are both O(1).

Solution 2 (no additional data structures):
Compare each character to the rest of the string.
Space: O(n)
Runtime: O(n^2)

WHAT I MISSED:
 - If the length of the string exceeds the number of characters available (ASCII = 256), we can return false immediately
 - You don't actually need an unordered_set for this. An array of bool[256] works perfectly fine and is simpler to use.
 - A bool takes up 1 byte. You can actually use a vector of bits to reduce space needed by a factor of 8.

*/

#include <string>
#include <unordered_set>

class Solution
{
public:
	bool HashSolution(std::string word)
	{
		std::unordered_set<char> known;
		for (auto &character : word)
			if (known.find(character) == known.end())
				known.insert(character);
			else
				return false;
		return true;
	}

	bool UniqueString(std::string word)
	{
		for (int i = 0; i < word.length(); ++i)
			for (int j = i + 1; j < word.length(); ++j)
				if (word.at(i) == word.at(j))
					return false;
		return true;
	}
};