
## 아이디어 
 n이 3이라면 바로 이전 칸의 경우의 수 각각에 1씩 더해지고 + 2칸 전 경우의 수 각각에 2씩 더해진다.
 따라서 dy[n] = dy[n-1] + dy[n-2]식이 성립한다.

``` cpp
#include<iostream>

using namespace std;

int dy[46];

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	dy[1] = 1; dy[2] = 2;
	for (int i = 3; i <= n; i++)dy[i] = dy[i - 1] + dy[i - 2];

	cout << dy[n];

}
```