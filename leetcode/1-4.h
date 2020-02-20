
/*
1.4: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string.
Example:
Input: "Mr John Smith     ", 13
Output: "Mr%20John%20Smith"

So we're going to iterate through the first 'n' letters of the string, replacing white space with %20's. The problem is that if we do this in-place, we'll run into issues because we're switching 1 character for 3. So I think we'll use a separate "result" string that we build along the way.

My solution works, but I didn't consider how to do the editing in-place. The real solution is to pass through it once counting spaces, add spaceCount * 2 to the length we're given and set that byte as the string terminator '\0', and then go through the string backwards (since that's where we have blank space and won't be overwriting stuff) and add characters that way, changing the target index by 1 or 3 for real chars/spaces

*/

#include <string>

class Solution
{
public:
	std::string replaceWhitespace(std::string str, int len)
	{
		std::string result;
		//for every character in the input string up to the "true" length
		for (size_t i = 0; i < len; i++)
			if (str[i] == ' ')
				result += "%20";
			else
				result += str[i];
		return result;
	}
};