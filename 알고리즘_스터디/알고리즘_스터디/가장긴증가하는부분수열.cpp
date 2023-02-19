//#include<iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	vector<int> arr(n,0);
//	vector<int> dy(n,0);
//	dy[0] = 1;
//
//	for (int i = 0; i < n; i++)cin >> arr[i];
//
//	int res = 0;
//	for (int i = 0; i < n; i++)
//	{
//		/*for (int j = i + 1; j < n; j++)
//		{
//			if(arr[i]<arr[j])
//				dy[j] = max(dy[j], dy[i] + 1);
//			if (res < dy[j])res = dy[j];
//		}*/
//
//		int max = 0;
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (arr[i] > arr[j]&&dy[j]>=max)
//			{
//				max = dy[j];
//			}
//		}
//		
//		dy[i] = max+1;
//		if (res < dy[i])res = dy[i];
//	}
//	cout << res;
//	return 0;
//}