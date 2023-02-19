//#include<iostream>
//#include<string>
//
//using namespace std;
//
//
//int main()
//{
//	int T;
//	cin >> T;
//	
//	char x, y;
//	string N;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> N >> x >> y;
//		string Num = "";
//		bool isSmall = false;
//		for (int j = 0;j<N.length();j++)
//		{
//			
//
//			if (N[j] > y)isSmall = true;
//			if (N[j] >= y)
//			{
//				Num += y;
//			}
//			else if (N[j] < y && N[j] >= x)
//			{
//				Num += x;
//			}
//			else
//			{
//				if (isSmall)
//				{
//					Num += y;
//				}
//				/*else
//				{
//					Num[j-1]=
//				}*/
//			}
//		}
//
//		//cout << "#" << i + 1 << " " << maxNum << endl;
//	}
//	
//	return 0;
//}