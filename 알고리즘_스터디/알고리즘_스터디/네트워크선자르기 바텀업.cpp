//#include<iostream>
//
//using namespace std;
//
//int dy[46];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	dy[1] = 1; dy[2] = 2;
//	for (int i = 3; i <= n; i++)dy[i] = dy[i - 1] + dy[i - 2];
//
//	cout << dy[n];
//
//}