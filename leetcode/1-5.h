/*
1.5: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string.

This seems pretty simple. We're iterating through the string once. We maintain what the current character is and what the count of that character is. When we find a new character or the end of the string, we add that char+count combo and reset them. At the end of the function, return whichever is shorter.

So the book would count this solution as wrong because in Java strings are immutable and so my solution would have a runtime complexity of O(p + k^2), where p is the length of the string and k is the number of character sequences. But in C++, strings are mutable. So this solution is close to optimal.
The only thing is that the logic is a bit questionable; we're peeking at the next character to see if it's valid. The logic should be reversed: Compare the last character to the current one; If it's the same, increment the count. If it's not, add the last char/count, then set last = the current char and count = 1. Then we just start with last = str[0] and loop from i = 1.

*/

#include <string>

class Solution
{
public:
	std::string strCompress(std::string str)
	{
		std::string result;
		char current = '\0';
		int count = 0;
		for (size_t i = 0; i < str.length(); i++)
		{
			//if we've found a new character, adjust 'current' to that character and set the count to 1
			if (current != str[i])
			{

				current = str[i];
				count = 1;
			}
			else
				count++;
			//if the next character is something new, add the current stuff to the result string
			if (i == str.length() - 1 || i + 1 < str.length() && str[i + 1] != current)
				result += current + std::to_string(count);
		}

		if (result.length() < str.length())
			return result;
		return str;
	}
};