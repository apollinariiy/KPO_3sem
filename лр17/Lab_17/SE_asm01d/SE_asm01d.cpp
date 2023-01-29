#include <iostream>

	int getmax(int* mas, int size)
	{
		int max = 0;
		for (int i = 0; i < size; i++)
		{
			max = std::max(max, mas[i]);
		}
		return max;
	}

	int getmin(int* mas, int size)
	{
		int min = INT_MAX;
		for (int i = 0; i < size; i++)
		{
			min = std::min(min, mas[i]);
		}
		return min;
	}