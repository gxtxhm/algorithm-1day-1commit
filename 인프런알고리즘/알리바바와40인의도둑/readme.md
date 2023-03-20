## 아이디어

동적계획법을 이용해 최단경로를 구하는데 이 때, 갈 수 있는 방향이 오른쪽 또는 아래쪽 밖에 없다.
그래야 돌아가지 않기 때문이다. 이를 이용해 기존의 동적계획법 방식을 적용하면 된다. 


```cpp

#include<iostream>

using namespace std;

int arr[20][20];
int dy[20][20];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	dy[0][0] = arr[0][0];
	for (int i = 1; i < n; i++)
	{
		dy[i][0] = dy[i - 1][0] + arr[i][0];
		dy[0][i] = dy[0][i-1] + arr[0][i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dy[i][j] = min(dy[i - 1][j], dy[i][j - 1]) + arr[i][j];
		}
	}
	cout << dy[n - 1][n - 1];

	return 0;
}

```