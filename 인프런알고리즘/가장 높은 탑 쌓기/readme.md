## 아이디어

LIS랑 거의 동일한 문제인데 다루는 자료형만 달라졌다. int형 대신 구조체로 다루게 되는데
알고리즘은 동일하다.

```cpp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



typedef struct Brick
{
	int a;
	int h;
	int w;
}Brick;

bool compare(const Brick& a,const Brick& b)
{
	if (a.a > b.a)return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<Brick> brick(n);
	vector<int> dy(n,0);
	Brick im;
	for (int i = 0; i < n; i++)
	{
		cin >> brick[i].a >> brick[i].h >> brick[i].w;
	}

	sort(brick.begin(), brick.end(), compare);
	int res=0;
	dy[0] = brick[0].h;
	for (int i = 1; i < n; i++)
	{
		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (brick[i].w < brick[j].w && max < dy[j])
			{
				max = dy[j];
			}
		}
		dy[i] = max + brick[i].h;
		if (res < dy[i])res = dy[i];
	}
	cout << res;
	return 0;
}

```