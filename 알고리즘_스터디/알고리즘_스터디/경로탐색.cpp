//#include<iostream>
//
//using namespace std;
//
//int arr[21][21];
//int cnt = 0;
//int n;
//int ch[21];
//
//void DFS(int v)
//{
//	if (v == n)
//	{
//		cnt++;
//	}
//	else
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			if (arr[v][i] > 0 && ch[i]==0)
//			{
//				ch[v] = 1;
//				DFS(i);
//				ch[v] = 0;
//			}
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//
//	int m;
//	cin >> n >> m;
//	int a, b;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> a >> b;
//		arr[a][b] = 1;
//	}
//	DFS(1);
//	cout << cnt;
//	return 0;
//}