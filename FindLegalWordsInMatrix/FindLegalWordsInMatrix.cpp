#include <stdio.h>
#include <string>
using namespace std;

/*����һ�������ھ����в��Ҹ��������Ƿ���ڣ��ο�FindWordsInMatrix*/
/*��������ʹ��ǰ׺������ÿ��λ��dfsʱ������Ƿ�Ϊǰ׺�򵥴�*/
#define VISITED '#'
#define DIRECTION 4
const int x_inc[DIRECTION] = {0,0,-1,1};
const int y_inc[DIRECTION] = {-1,1,0,0};

int dfs(char** data,int M,int N,int i,int j,string& str)
{
	/*����Ƿ�Ϊǰ׺�򵥴�*/
	char old = data[i][j];
	data[i][j] = VISITED;
	str += old;
	int ret = -1;
	for (int p = 0;p < DIRECTION;p++)
	{
		int n_i = i + x_inc[p];
		int n_j = j + y_inc[p];
		if ( n_i >= 0 && n_i < M && n_j >=0 && n_j < N && data[n_i][n_j] != VISITED)
			if((ret = dfs(data,M,N,n_i,n_j,str)) == 0)
				break;
	}
	data[i][j] = old;
	str = str.substr(0,str.length()-1);
	return ret;
}

int find(char** data,int M,int N)
{
	if(data == NULL)
		return -1;
	int ret = -1;
	int index = 0;
	for(int i = 0;i < M;i++)
	{
		for(int j = 0;j < N;j++)
		{
			string str = "";
			if((ret = dfs(data,M,N,i,j,str)) == 0)
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
	
	/*����ǰ׺��*/


	for(int i = 0;i < M;i++)
		delete[] data[i];
	delete[] data;
	fclose(stdin);
	return 0;
}

