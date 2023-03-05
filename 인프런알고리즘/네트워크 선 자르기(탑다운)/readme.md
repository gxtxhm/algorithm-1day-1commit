## 아이디어 
바텀업 방식과 마찬가지로 dy[n]=dy[n-1]+dy[n-2] 식이 성립하는데 
이를 메모이제이션 방식으로 재귀함수를 이용하였다.


``` cpp

#include <iostream>
using namespace std;

int dy[46];

int D(int n)
{
	if (dy[n] > 0)return dy[n];
	if (n == 1)return 1;
	if (n == 2)return 2;
	return D(n - 1) + D(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << D(n);

	return 0;
}


```