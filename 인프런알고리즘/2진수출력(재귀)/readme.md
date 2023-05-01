## 아이디어 
재귀함수를 이용하여 2진수를 출력한다.


```cpp
#include<iostream>

using namespace std;

void D(int x) {
	if (x == 0)return;

	D(x / 2);
	printf("%d",x % 2);
}


int main() {
	
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	D(n);
}
```