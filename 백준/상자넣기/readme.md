
## 아이디어

이 문제는 LIS랑 거의 똑같은 문제다. 수열이 상자의 나열로 바뀐 것 뿐이다.
따라서 알고리즘도 동일하게 적용하여 풀었다.


```cpp


#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int arr[1001] = { 0, };
	int dy[1001] = { 0, };

	for (int i = 0; i < n; i++)cin >> arr[i];
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j] && dy[j] >= max)
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
