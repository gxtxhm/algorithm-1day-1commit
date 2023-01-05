## 아이디어
처음 문제를 보고 가로길이가 100, 덤프횟수는 1000, 케이스는 10개니까 아무리 많은 연산을 해도
시간초과가 날 것 같지 않아서 매번 max, min 값을 찾고 빼고 하는 방식으로 주어진 횟수 만큼 반복을 했다.


```cpp

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int max, min;
	int maxId=100, minId=1;
	int caseCnt = 0;
	int arr[101];
	while (caseCnt < 10)
	{
		int num;
		scanf("%d", &num);

		for (int i = 1; i <= 100; i++)
		{
			scanf("%d", &arr[i]);
		}
		max = -1; min = 101;
		int m;
		while (num > 0)
		{
			max = -1; min = 101;
			// max, min 위치 구하기
			for (int i = 1; i <= 100; i++)
			{
				if (max < arr[i])
				{
					max = arr[i];
					maxId = i;
				}
				if (min > arr[i])
				{
					min = arr[i];
					minId = i;
				}
			}
			// 덤프 실행
			arr[maxId]--; arr[minId]++;
			num--;
		}
		max = -1; min = 101;
		// max, min 위치 구하기
		for (int i = 1; i <= 100; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
				maxId = i;
			}
			if (min > arr[i])
			{
				min = arr[i];
				minId = i;
			}
		}
		m = arr[maxId] - arr[minId];

		caseCnt++;
		printf("%d", m);
	}


	return 0;
}

```