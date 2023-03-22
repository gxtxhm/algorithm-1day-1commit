//#include<iostream>
//
//using namespace std;
//
//int arr[301][301];
//int dy[301][301];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//
//	int n,m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//
//	dy[0][0] = arr[0][0];
//
//	for (int i = 1; i < n; i++)dy[i][0] = dy[i - 1][0] + arr[i][0];
//	for (int i = 1; i < m; i++)dy[0][i] = dy[0][i - 1] + arr[0][i];
//
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 1; j < m; j++)
//		{
//			dy[i][j] = max(dy[i - 1][j], dy[i][j - 1]) + arr[i][j];
//		}
//	}
//	cout << dy[n-1][m-1];
//	return 0;
//}