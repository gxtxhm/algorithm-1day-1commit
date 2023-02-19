//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//string convertNunToString(int num)
//{
//	string r = "";
//	vector<int> arr;
//	string ret = "";
//	bool clap = false;
//	while (num > 0)
//	{
//		int c = num % 10;
//		if (c == 3 || c == 6 || c == 9)
//		{
//			r += '-'; clap = true;
//		}
//		else
//		{
//			r += to_string(c);
//		}
//		
//		arr.push_back(num % 10);
//		num /= 10;
//	}
//	if (clap)
//	{
//		for (int i = 0; i < r.size(); i++)
//		{
//			if (r[i] == '-')
//			{
//				ret += "-";
//			}
//		}
//		r = ret;
//	}
//	reverse(r.begin(), r.end());
//	
//	return r;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		cout << convertNunToString(i) << " ";
//	}
//	return 0;
//}