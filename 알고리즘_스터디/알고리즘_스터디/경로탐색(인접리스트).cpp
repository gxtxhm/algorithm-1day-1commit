//#include<iostream>
//#include<vector>
//using namespace std;
//
//int n, m, cnt = 0;
//vector<int> map[21];
//int ch[21];
//
//void DFS(int v)
//{
//	if (v == n)
//	{
//		cnt++;
//		return;
//	}
//	else
//	{
//		for (int i = 0; i < map[v].size(); i++)
//		{
//			if (ch[map[v][i]] == 0)
//			{
//				ch[map[v][i]] = 1;
//				DFS(map[v][i]);
//				ch[map[v][i]] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	int a, b;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> a >> b;
//		map[a].push_back(b);
//	}
//	ch[1] = 1;
//	DFS(1);
//	cout << cnt;
//	return 0;
//}