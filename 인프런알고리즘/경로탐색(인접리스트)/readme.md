## 아이디어
DFS를 통해 경로탐색하는 문제를 행렬대신 리스트를 가지고 풀어보는 문제이다.
행렬은 n의 크기만큼 2차원배열을 생성해야하지만 리스트는 간선의 수만큼만 할당하면 되기 때문에
메모리 낭비 측면에서 좋은 성능을 보인다. 


```cpp
#include<iostream>
#include<vector>
using namespace std;

int n, m, cnt = 0;
vector<int> map[21];
int ch[21];

void DFS(int v)
{
	if (v == n)
	{
		cnt++;
		return;
	}
	else
	{
		for (int i = 0; i < map[v].size(); i++)
		{
			if (ch[map[v][i]] == 0)
			{
				ch[map[v][i]] = 1;
				DFS(map[v][i]);
				ch[map[v][i]] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a].push_back(b);
	}
	ch[1] = 1;
	DFS(1);
	cout << cnt;
	return 0;
}
```