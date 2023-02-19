## 아이디어

이 문제는 LIS와 동일한 알고리즘을 적용하여 풀 수있다. 
결국 어떻게하면 병사의 나열을 가장 길게할 수 있을까? 라는 문제이다.
따라서 감소하는 최장수열문제로 해석하면 어렵지 않게 풀 수 있다.


```cpp

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int arr[2000] = { 0, };
	int dy[2000] = { 0, };

	for (int i = 0; i < n; i++)cin >> arr[i];

	int res = 0;
	dy[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] < arr[j]&&dy[j]>=max)
			{
				max = dy[j];
			}
		}
		dy[i] = max + 1;
		if (res < dy[i])res = dy[i];
	}
	cout << n-res;

	return 0;
}

```
