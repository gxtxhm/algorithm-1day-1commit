## 아이디어

dy[i]가 i까지의 수열 중 가장 긴 증가부분수열의 길이를 나타낸다고 정의한다.
for문을 돌며 i-1까지의 수 중 가장 긴 수열을 찾아 +1을 한다.

```cpp

#include<iostream>

using namespace std;

int arr[1001];
int dy[1001];

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		int max = 0;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[i] > arr[j] && max < dy[j])
			{
				max = dy[j];
			}
		}
		dy[i] = max + 1;
		if (res < dy[i])res = dy[i];
	}
	cout << res;
	return 0;
}

```