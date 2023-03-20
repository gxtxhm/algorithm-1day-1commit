//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//typedef struct Block
//{
//	int area;
//	int h;
//	int w;
//	int id;
//}Block;
//
//bool compare(const Block& a, const Block& b)
//{
//	if (a.area > b.area)return true;
//	else return false;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	vector<Block> arr(n);
//	vector<int> dp(n, 0);
//	vector<int> count(n, 0);
//	vector<int> a(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i].area >> arr[i].h >> arr[i].w;
//		arr[i].id = i + 1;
//	}
//
//	sort(arr.begin(), arr.end(), compare);
//
//	
//
//	dp[0] = arr[0].h;
//
//	int res = dp[0];
//	int resId = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int max = 0;
//		int maxId = -1;
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (arr[i].w < arr[j].w && max < dp[j])
//			{
//				max = dp[j];
//				maxId = j;
//			}
//		}
//		dp[i] = max + arr[i].h;
//		if (maxId == -1)count[i] = 1;
//		else count[i] = count[maxId] + 1;
//		a[i] = maxId;
//
//		if (res < dp[i])
//		{
//			res = dp[i];
//			resId = i;
//		}
//	}
//
//	// a[0] = 2; => 2번 벽돌 위에 0번 벽돌이 있다는 뜻.
//	cout << count[resId]<<"\n";
//
//	int c = resId;
//	for (int i = 0; i < count[resId]; i++)
//	{
//		cout << arr[c].id << "\n";
//		c = a[c];
//	}
//
//	return 0;
//}