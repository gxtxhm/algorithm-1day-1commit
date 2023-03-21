//#include<iostream>
//
//using namespace std;
//
//int arr[21][21];
//int dy[21][21];
//
//int TD(int x, int y)
//{
//	if (x < 0 || y < 0)return 16000;
//	if (dy[x][y] > 0)return dy[x][y];
//	if (x == 0 && y == 0)return arr[0][0];
//	
//	return dy[x][y] = min(TD(x - 1, y), TD(x, y - 1)) + arr[x][y];
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> arr[i][j];
//
//	cout << TD(n - 1, n - 1);
//
//	return 0;
//}