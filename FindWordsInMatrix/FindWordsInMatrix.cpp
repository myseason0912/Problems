#include <stdio.h>
#include <string>

#define VISITED '#'
#define DIRECTION 4
const int x_inc[DIRECTION] = {0,0,-1,1};
const int y_inc[DIRECTION] = {-1,1,0,0};

int dfs(char** data,char* dst,int M,int N,int i,int j,int& index)
{
	if(data[i][j] != dst[index])
		return -1;
	if(data[i][j] == dst[index] && index == strlen(dst) - 1)
		return 0;
	index++;
	char old = data[i][j];
	data[i][j] = VISITED;
	int ret = -1;
	for (int p = 0;p < DIRECTION;p++)
	{
		int n_i = i + x_inc[p];
		int n_j = j + y_inc[p];
		if ( n_i >= 0 && n_i < M && n_j >=0 && n_j < N && data[n_i][n_j] != VISITED)
			if((ret = dfs(data,dst,M,N,n_i,n_j,index)) == 0)
				break;
	}
	data[i][j] = old;
	index--;
	return ret;
}

int find(char** data,int M,int N,char* dst)
{
	if(data == NULL || dst == NULL)
		return -1;
	int ret = -1;
	int index = 0;
	for(int i = 0;i < M;i++)
	{
		for(int j = 0;j < N;j++)
		{
			if((ret = dfs(data,dst,M,N,i,j,index)) == 0)
				break;
		}
		if(ret == 0)
			break;
	}
	return ret;
}

int main(int argc, char* argv[])
{
	if (freopen("test.txt", "r", stdin)==NULL)
	{
		printf("open input file error\n");
		return 0;
	}
	int M = 0;
	int N = 0;
	scanf("%d ",&M);
	scanf("%d ",&N);
	char** data = new char*[M];
	for (int i = 0;i < M;i++)
	{
		data[i] = new char[N];
		for(int j = 0;j < N;j++)
			scanf("%c ",&data[i][j]);
	}

	if(find(data,M,N,"YAHOO!") == 0)
		printf("found\n");
	else
		printf("not found\n");

	for(int i = 0;i < M;i++)
		delete[] data[i];
	delete[] data;
	fclose(stdin);
	return 0;
}

