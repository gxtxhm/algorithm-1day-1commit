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
//
//	int arr[2000] = { 0, };
//	int dy[2000] = { 0, };
//
//	for (int i = 0; i < n; i++)cin >> arr[i];
//
//	int res = 0;
//	dy[0] = 1;
//	for (int i = 0; i < n; i++)
//	{
//		int max = 0;
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (arr[i] < arr[j]&&dy[j]>=max)
//			{
//				max = dy[j];
//			}
//		}
//		dy[i] = max + 1;
//		if (res < dy[i])res = dy[i];
//	}
//	cout << n-res;
//
//	return 0;
//}