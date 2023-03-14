## 아이디어

가장 높은 탑을 쌓았을 때, 총 탑이 몇개의 블록으로 쌓았고 그 블록의 번호는 무엇인지를 출력해야한다.
따라서 LIS와 동일한 알고리즘으로 가장 높은 탑을 구하면서 그 과정에서 count배열에 count[i]에는 
i번째 블록이 탑의 제일 꼭대기 일때 사용된 블록의 개수를 저장한다.
그리고 사용된 블록의 번호를 출력해야하기에 a 배열을 사용한다. 
a[i] = j 라고 했을 때, i번째 블록 바로 밑에는 j 블록이 있다는 것을 뜻한다.

```cpp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Block
{
	int area;
	int h;
	int w;
	int id;
}Block;

bool compare(const Block& a, const Block& b)
{
	if (a.area > b.area)return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<Block> arr(n);
	vector<int> dp(n, 0);
	vector<int> count(n, 0);
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].area >> arr[i].h >> arr[i].w;
		arr[i].id = i + 1;
	}

	sort(arr.begin(), arr.end(), compare);

	

	dp[0] = arr[0].h;

	int res = dp[0];
	int resId = 0;
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		int maxId = -1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i].w < arr[j].w && max < dp[j])
			{
				max = dp[j];
				maxId = j;
			}
		}
		dp[i] = max + arr[i].h;
		if (maxId == -1)count[i] = 1;
		else count[i] = count[maxId] + 1;
		a[i] = maxId;

		if (res < dp[i])
		{
			res = dp[i];
			resId = i;
		}
	}

	// a[0] = 2; => 2번 벽돌 위에 0번 벽돌이 있다는 뜻.
	cout << count[resId]<<"\n";

	int c = resId;
	for (int i = 0; i < count[resId]; i++)
	{
		cout << arr[c].id << "\n";
		c = a[c];
	}

	return 0;
}

```