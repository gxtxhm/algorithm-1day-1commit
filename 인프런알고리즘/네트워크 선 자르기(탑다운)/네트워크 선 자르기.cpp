//#include <iostream>
//using namespace std;
//
//int dy[46];
//
//int D(int n)
//{
//	if (dy[n] > 0)return dy[n];
//	if (n == 1)return 1;
//	if (n == 2)return 2;
//	return D(n - 1) + D(n - 2);
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	int n;
//	cin >> n;
//	cout << D(n);
//
//	return 0;
//}