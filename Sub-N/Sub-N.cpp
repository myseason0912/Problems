// Sub-N.cpp : Defines the entry point for the console application.
//均为正数的无序数组，是否存在子段和为N
//

#include <stdio.h>

bool isExist(int* sour,int len,int N)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	while (i <= j && j < len)
	{
		if (sum > N)
		{
			if (i == j)
			{
				i++;
				j++;
			}
			else
			{
				i++;
				sum -= sour[i];
			}
		}
		else
		{
			if (sum < N)
			{
				j++;
				sum += sour[j];
			}
			else
			{
				return true;
			}
		}

	}
	return false;
}

int main(int argc,char* argv[])
{
	int sour[] = {1,2,3,4,5,6,7,8};
	int len = sizeof(sour)/sizeof(sour[0]);
	if (isExist(sour,len,17))
		printf("exist\n");
	else
		printf("not exist\n");
	return 0;
}
