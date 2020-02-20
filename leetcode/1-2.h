/*
1.2: Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string
Okay, so what we have is an array of characters: ['B', 'R', 'E', 'A', 'K', '\0']
How do we reverse them?
The best we're gonna do is probably O(n). We can't do all those swaps in O(1), especially since we don't know how long this string is until we've traversed it.
I think my best solution is to build the string backwards as we go... Hm.
I think we iterate until we find the null character so we know how long it is. Then we can swap bytes until it's reversed.

My naive solution:
Iterate through the char* until the null terminating character so we know how long it is. Then swap the first and last character on repeatedly smaller strings until it's reversed.
Runtime: O(n)
Space complexity: O(1)
Aside from some initial simple compiler errors related to not dereferencing when we should have, we made no mistakes! This is the right implementation.
*/

#include <string>

class Solution
{
public:
	void reverse(char *str)
	{
		int size = 0;
		char* temp = str;
		for (char* i = str; (*i) != '\0'; ++i)
			++size;
		//now 'size' contains the length of the string
		//iterate through the first floor(n/2) characters, swapping them with their equivalent on the other side.
		//Swap the first and last character
		for (int i = 0; i < floor(size / 2); ++i)
			swapChar(str + i, str + size - (i + 1));
	}

	void swapChar(char* str1, char* str2)
	{
		char temp = *str1;
		*str1 = *str2;
		*str2 = temp;
	}
};