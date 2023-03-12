## 아이디어 

맨마지막 계단을 반드시 밟아야 하므로 마지막 계단을 1칸 뛰어서 밟느냐 2칸 뛰어서 밟느냐로 
시작한다. 
만약 2칸을 뛰어서 밟았다면 dp[i] = dp[i-2]+ arr[i]이고 ,
1칸을 뛰어서 밟았다면 i-1을 도착할 때는 반드시 2칸을 뛰어서 밟았어야 한다. 연속된 3계단은 밟을 수 없기
때문이다. 
따라서 dp[i] = dp[i-3] + arr[i-1] + arr[i]가 된다. dp[i]는 둘 중 더 큰수를 취하게 된다.  


```cpp

#include<iostream>

using namespace std;

int arr[301];
int dp[301];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = max(arr[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < n; i++)dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];

	cout << dp[n - 1];

	return 0;
}

```