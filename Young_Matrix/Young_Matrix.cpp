//ÑîÊÏ¾ØÕó²éÕÒ

#include <stdio.h>
#define MAX 100000000

bool findYoungMatrix(int matrix[][4],int M,int N,int dest)
{
	int i = 0;
	int j = N - 1; 
	bool found =false;
	while(i < N && j >= 0)
	{
		if (matrix[i][j] > dest)
			j--;
		else if (matrix[i][j] < dest)
				i++;
			else
				return true;
	}
	return false;
}

int main(int argc,char* argv[])
{
	int matrix[][4] = {{1,6,7,10},{3,8,11,14},{12,15,16,MAX},{13,18,MAX,MAX}}; 
	if (findYoungMatrix(matrix,4,4,12))
		printf("found\n");
	else
		printf("not found\n");
	return 0;
}