// Dup-Element.cpp : Defines the entry point for the console sourpplicsourtion.
//��СΪN���������1����N-1���Ƿ�����ظ�������ʱ��O(N)���ռ�O(1)
//

#include <stdio.h>

bool isDuplicate(int* sour,int N)
{
	int tmp = 0;
	for(int i = 0;i < N;i++)
	{
		if (sour[i] > 0)
		{
			tmp = sour[i];
			if (sour[tmp] < 0)
				return true;
			else
				sour[tmp] -= N;
		}
		else
		{
			tmp = sour[i] + N;
			if (sour[tmp] < 0)
				return true;
			else
				sour[tmp] -= N;
		}
	}
	return false;
}

int main(int argc, char* argv[])
{
	int sour[] = {2,1,1,3,4};
	if(isDuplicate(sour,sizeof(sour)/sizeof(sour[0])))
		printf("duplicate\n");
	else
		printf("not duplicate\n");

	return 0;
}

