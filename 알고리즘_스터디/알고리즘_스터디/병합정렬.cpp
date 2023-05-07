//#include<iostream>
//
//using namespace std;
//
//int arr[101];
//int test[101];
//void D(int lt, int rt)
//{
//	if (lt < rt)
//	{
//		int mid = (lt + rt) / 2;
//		D(lt, mid);
//		D(mid + 1, rt);
//
//		int lp = lt, rp = mid + 1, cur = lt;
//		while (lp <= mid && rp <= rt) {
//			if (arr[lp] < arr[rp])
//			{
//				test[cur++] = arr[lp++];
//			}
//			else test[cur++] = arr[rp++];
//		}
//		while (lp <= mid)test[cur++] = arr[lp++];
//		while (rp <= rt)test[cur++] = arr[rp++];
//
//		for (int i = lt; i <= rt; i++)arr[i] = test[i];
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)cin >> arr[i];
//
//	D(1, n);
//
//	for (int i = 1; i <= n; i++)cout << arr[i] << " ";
//
//	return 0;
//}