
```cpp


#include<iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> arr(n,0);
	vector<int> dy(n,0);
	dy[0] = 1;

	for (int i = 0; i < n; i++)cin >> arr[i];

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		/*for (int j = i + 1; j < n; j++)
		{
			if(arr[i]<arr[j])
				dy[j] = max(dy[j], dy[i] + 1);
			if (res < dy[j])res = dy[j];
		}*/

		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j]&&dy[j]>=max)
			{
				max = dy[j];
			}
		}
		
		dy[i] = max+1;
		if (res < dy[i])res = dy[i];
	}
	cout << res;
	return 0;
}
```

주석 처리한 부분이 처음 접근했던 방법인데 저런식으로 하면 뒤의 경우에서 중복문제가 발생해서 오답이발생하였다. 따라서 i번째 수가 가장 마지막이라는 전제로 그 앞의 것들을 비교하니 중복문제가 발생하지 않았다.