## 아이디어
정렬 방법 중 재구함수를 이용해 구현할 수 있는 병합정렬이다. 
최대한 작은 범위까지 쪼개서 그 작은 조각끼리 정렬을 시켜서 최종적으로 해당 배열을
정렬시키는 방법이다. 


```cpp

#include<iostream>

using namespace std;

int arr[101];
int test[101];
void D(int lt, int rt)
{
	if (lt < rt)
	{
		int mid = (lt + rt) / 2;
		D(lt, mid);
		D(mid + 1, rt);

		int lp = lt, rp = mid + 1, cur = lt;
		while (lp <= mid && rp <= rt) {
			if (arr[lp] < arr[rp])
			{
				test[cur++] = arr[lp++];
			}
			else test[cur++] = arr[rp++];
		}
		while (lp <= mid)test[cur++] = arr[lp++];
		while (rp <= rt)test[cur++] = arr[rp++];

		for (int i = lt; i <= rt; i++)arr[i] = test[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];

	D(1, n);

	for (int i = 1; i <= n; i++)cout << arr[i] << " ";

	return 0;
}

```