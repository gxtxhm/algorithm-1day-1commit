//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	int arr[301] = { 0, };
//	int dy[301] = { 0, };
//
//	for (int i = 0; i < n; i++)cin >> arr[i];
//
//	dy[0] = arr[0];
//	dy[1] = dy[0] + arr[1];
//	for (int i = 2; i < n; i++)
//	{
//		dy[i] = max(dy[i - 1], dy[i - 2]) + arr[i];
//	}
//	cout << max(dy[n - 1], dy[n - 2]);
//	return 0;
//}