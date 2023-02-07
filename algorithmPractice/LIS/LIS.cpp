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