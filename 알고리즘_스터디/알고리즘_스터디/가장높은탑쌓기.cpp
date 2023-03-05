//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef struct Block {
//	int a;
//	int h;
//	int w;
//	int cnt;
//}Block;
//
//bool compare(const Block& a, const Block& b)
//{
//	if (a.a > b.a)
//		return true;
//	else
//		return false;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//
//	vector<Block> arr(n);
//	vector<int> dy(n, 0),id(n,0);
//	int a, h, w;
//	
//	for (int i = 0; i < n; i++) {
//		cin >> a >> h >> w;
//		arr[i].a = a;
//		arr[i].h = h;
//		arr[i].w = w;
//		arr[i].cnt = 1;
//	}
//
//	// 정렬 필요 : 밑면기준 내림차순
//	sort(arr.begin(), arr.end(), compare);
//
//	int res = 0,resId=0;
//	dy[0] = 1;
//	for (int i = 0; i < n; i++)
//	{
//		int max = 0,maxId=0;
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (arr[i].a < arr[j].a && arr[i].w < arr[j].w && dy[j] >= max)
//			{
//				max = dy[j];
//				maxId = j;
//			}
//		}
//		dy[i] = max + 1;
//		id[i] = maxId;
//		arr[i].cnt += arr[maxId].cnt;
//		if (res < dy[i])
//		{
//			res = dy[i];
//			resId = i;
//		}
//	}
//	int dest= resId;
//	cout << arr[resId].cnt;
//	while (id[dest] != 0)
//	{
//		cout << dest + 1 << "\n";
//		dest = id[dest];
//	}
//
//	return 0;
//}