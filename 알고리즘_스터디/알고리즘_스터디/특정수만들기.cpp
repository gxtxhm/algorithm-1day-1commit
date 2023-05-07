//#include<iostream>
//
//using namespace std;
//
//int num, m;
//int arr[11];
//bool flag = false;
//int cnt = 0;
//
//void D(int n,int sum)
//{
//	if (n == num + 1)
//	{
//		if (sum == m)
//		{
//			flag = true;
//			cnt++;
//		}
//		
//	}
//	else
//	{
//		D(n + 1, sum + arr[n]);
//		D(n + 1, sum - arr[n]);
//		D(n + 1, sum);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//
//	cin >> num >> m;
//	for (int i = 1; i <= num; i++)cin >> arr[i];
//
//	D(1, 0);
//	if (flag)cout << cnt;
//	else cout << -1;
//
//	return 0;
//}