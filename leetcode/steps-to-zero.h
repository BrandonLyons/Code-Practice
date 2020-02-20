class Solution
{
public:
	int numberOfSteps(int num)
	{
		int count = 0;
		//Solution 1: Brute force
		/*
		while (num > 0)
		{
			if (num % 2 == 0)
				num = num / 2;
			else
				num--;
			count++;
		}
		return count;
		*/
		//Solution 2: Bitwise operations??
		//Step 1: Figure out how many bits this number takes up
		//N bits maxes out at (2^N - 1)
		//So... I dunno how that works out in a space efficient way
		//count = 2 * bi
		//n 
		//Basically we need to figure out how many times we can divide this number by 2 (and then subtract by 1 inbetween).
		//This sounds like a bitwise problem
		//14 = 2^3 + 2^2 + 2^1 = 1110 -> 6?
		//8 = 2^3 = 100 -> 4
		//123 = 2^6 + 2^5 + 2^4 + 2^3 + 0 + 2^1 + 2^0 = 1111011 = 12???
		//Step 1: 123 - 1 = 122 = 1111010
		//Step 2: 122 / 2 = 61  =  111101
		//Step 3: 61 - 1  = 60  =  111100
		//Step 4: 60 / 2  = 30  =   11110
		//Step 5: 30 / 2  = 15  =    1111
		//Step 6: 15 - 1  = 14  =    1110
		//Step 7: 14 / 2  = 7   =     111
		//Step 8: 7 - 1   = 6   =     110
		//Step 9: 6 / 2   = 3   =      11
	   //Step 10: 3 - 1   = 2   =      10
	   //Step 11: 2 / 2   = 1   =       1
	   //Step 12: 1 - 1   = 0   =       0
		//Algorithm: Each 1 in the input is +2 steps
		//			 Each 0 in the input is +1 step
		while (num) // while there are still non-zero bits(?)
		{
			//if the first number is a 1, add 2 and shift it out
			if (num & 1)
				count += 2;
			else
				count++;
			num = num >> 1;
		}
		--count;
		return count;
	}
};