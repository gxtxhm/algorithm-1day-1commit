//#include<iostream>
//
//using namespace std;
//
//int R, C;
//int maxCnt;
//int arr[26];
//char board[20][20];
//
//void DFS(int cnt,int x,int y)
//{
//	if (arr[board[x][y] - 'A'] == 1)// 산 것이라면
//	{
//		if (cnt > maxCnt)maxCnt = cnt;
//		return;
//	}
//	if (x < 0 || x >= R || y < 0 || y >= C)//범위를 벗어났다면
//		return;
//
//	
//	arr[board[x][y] - 'A'] = 1;
//	DFS(cnt + 1, x + 1, y);
//	arr[board[x][y] - 'A'] = 0;
//	
//	arr[board[x][y] - 'A'] = 1;
//	DFS(cnt + 1, x - 1, y);
//	arr[board[x][y] - 'A'] = 0;
//
//	arr[board[x][y] - 'A'] = 1;
//	DFS(cnt + 1, x, y + 1);
//	arr[board[x][y] - 'A'] = 0;
//
//	arr[board[x][y] - 'A'] = 1;
//	DFS(cnt + 1, x, y - 1);
//	arr[board[x][y] - 'A'] = 0;
//}
//
//
//int main()
//{
//	int T;
//
//	cin >> T;
//
//	for (int i = 0; i < T; i++)
//	{
//		maxCnt = 0;
//		for (int i = 0; i < 26; i++)arr[i] = 0;
//		cin >> R >> C;
//		for (int j = 0; j < R; j++)for (int k = 0; k < C; k++)cin >> board[j][k];
//
//		DFS(0, 0, 0);
//
//		cout << "#" << i + 1 << " " << maxCnt << endl;
//	}
//	return 0;
//}