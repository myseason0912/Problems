// Maze-Score.cpp : Defines the entry point for the console application.
//m*n的迷宫，>0表示可走的能量数量，0表示不可走，每通过一个格子可以收集能量，不能重复走，只能从左上角走到右下角，怎么使能量最多
//

#include <stdio.h>

void getMaxEnergy(int matrix[][4],int M,int N,int x,int y,int e,int& max_e)
{
	e += matrix[x][y];
	if (x == M-1 && y == N-1)
	{
		if (e > max_e)
			max_e = e;
		return;
	}
	int tmp = 	matrix[x][y];
	matrix[x][y] = 0;
	if (y != N-1 && matrix[x][y+1] != 0)
	{
		getMaxEnergy(matrix,M,N,x,y+1,e,max_e);
	}
	if (y != 0 && matrix[x][y-1] != 0)
	{
		getMaxEnergy(matrix,M,N,x,y-1,e,max_e);
	}
	if (x != M-1 && matrix[x+1][y] != 0)
	{
		getMaxEnergy(matrix,M,N,x+1,y,e,max_e);
	}
	if (x != 0 && matrix[x-1][y] != 0)
	{
		getMaxEnergy(matrix,M,N,x-1,y,e,max_e);
	}
	matrix[x][y] = tmp;
}

int main(int argc, char* argv[])
{
	int max_e = 0;
	int matrix[][4] = {{1,1,0,0},{2,1,1,0},{1,1,1,0},{1,1,1,1}};
	getMaxEnergy(matrix,4,4,0,0,0,max_e);
	printf("max energy %d\n",max_e);
	return 0;
}

