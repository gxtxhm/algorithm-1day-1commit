## 아이디어

부분집합을 1개 만들면 나머지 한개도 자동으로 완성된다는 것이 아이디어이다.

```cpp

#include<iostream>

using namespace std;

int num;
int total;
bool flag = false;
int arr[11];

void D(int n,int sum)
{
	if (flag == true)return;
	if (n == num+1)
	{
		if (sum == (total - sum))flag = true;
	}
	else 
	{
		D(n + 1,sum+arr[n]);
		D(n + 1,sum);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i]; total += arr[i];
	}
	

	D(1,0);
	cout << (flag ? "YES" : "NO");
	return 0;
}

```