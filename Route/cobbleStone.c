#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define		HEIGHT			3	
#define		WIDTH			3	

#define		TRUE			1
#define		FALSE			0


int g_Table[HEIGHT][WIDTH] =
{
	{2,7,8},
	{7,0,4},
	{6,4,0}
};


int Pebble(int i, int curPattern);
int Together(int curPattern, int nextPattern);
int PatternPoint(int i, int curPattern);

int main(void)
{
	int high = (-1) * _CRT_INT_MAX;


	int value;
	int curPattern;


	for (curPattern = 1; curPattern <= 4; curPattern++)
	{
		value = Pebble(WIDTH - 1, curPattern);

		if (value > high)
			high = value;
	}

	printf("MAX : %d\n", high);

	return 0;
}


int Pebble(int i, int curPattern)
{
	int nextPattern;

	int high = (-1) * _CRT_INT_MAX;

	int value;


	if (i == 0)
		return PatternPoint(0, curPattern);


	for (nextPattern = 1; nextPattern <= 4; nextPattern++)
	{

		if (Together(curPattern, nextPattern) == TRUE)
		{

			value = Pebble(i - 1, nextPattern);


			if (value > high)
				high = value;
		}
	}

	return high + PatternPoint(i, curPattern);
}


int Together(int curPattern, int nextPattern)
{

	if (curPattern == nextPattern)
		return FALSE;

	if (curPattern == 4)
	{
		if (nextPattern == 2)
			return TRUE;
	}
	else if (curPattern == 3)
	{
		if (nextPattern == 1 || nextPattern == 2)
			return TRUE;
	}
	else if (curPattern == 2)
	{
		if (nextPattern != 2)
			return TRUE;
	}
	else if (curPattern == 1)
	{
		if (nextPattern == 3 || nextPattern == 2)
			return TRUE;
	}

	return FALSE;
}


int PatternPoint(int i, int curPattern)
{
	if (curPattern == 1)
		return g_Table[0][i];

	else if (curPattern == 2)
		return g_Table[1][i];

	else if (curPattern == 3)
		return g_Table[2][i];

	else if (curPattern == 4)
		return g_Table[0][i] + g_Table[2][i];

	return 0;
}

