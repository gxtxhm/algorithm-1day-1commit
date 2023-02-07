## 아이디어 

동적계획법으로 풀었다. 동적계획법이란 가장 작게 문제를 쪼개서 그 작은 문제를 풀고 그 답을 이용해 더 큰 문제를 푸는 식으로 진행되는 방법이다. 

앞쪽부터 수를 하나씩 살펴보며 그 수의 앞까지만 보고 만들수있는 가장 큰 수열을 계산한다. 그리고 그 다음 수는 바로 직전의 수들 중 가장 길게 만들 수 있는 수열을 판단하여 +1 한다. 


```
#include<iostream>

using namespace std;

int main()
{
	int N;
	int a[1001] = { 0, };
	int dy[1001] = { 0, };
	int res = 0;

	cin >> N;
	for (int i = 1; i <= N; i++)cin >> a[i];

	dy[1] = 1;
	for (int i = 1; i <= N; i++) {
		int max = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] > a[j] && dy[j] >= max) {
				max = dy[j];
			}
		}
		dy[i] = max + 1;
		if (res < dy[i])res = dy[i];
	}
	cout << res;
}
```