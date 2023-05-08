## 아이디어
DFS를 이용한 문제이다. DFS재귀함수를 조금만 응용하면 문제를 풀 수 있다.


```cpp
#include<iostream>

using namespace std;

int map[8][8];
int ch[8][8];
int cnt = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void DFS(int x, int y)
{
	if (x == 7 && y == 7)
	{
		cnt++;
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 1 || xx>7 || yy < 1 || yy>7)
				continue;
			if (map[xx][yy] == 0 && ch[xx][yy] == 0)
			{
				ch[xx][yy] = 1;
				DFS(xx, yy);
				ch[xx][yy] = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			cin >> map[i][j];
		}
	}
	ch[1][1] = 1;
	DFS(1,1);
	cout << cnt;
	return 0;
}
```