//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//int main()
//{
//	int max, min;
//	int maxId=100, minId=1;
//	int caseCnt = 0;
//	int arr[101];
//	while (caseCnt < 100)
//	{
//		int num;
//		scanf("%d", &num);
//
//		for (int i = 1; i <= 100; i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		max = -1; min = 101;
//		int m;
//		while (num > 0)
//		{
//			max = -1; min = 101;
//			// max, min 위치 구하기
//			for (int i = 1; i <= 100; i++)
//			{
//				if (max < arr[i])
//				{
//					max = arr[i];
//					maxId = i;
//				}
//				if (min > arr[i])
//				{
//					min = arr[i];
//					minId = i;
//				}
//			}
//			// 덤프 실행
//			arr[maxId]--; arr[minId]++;
//			num--;
//		}
//		max = -1; min = 101;
//		// max, min 위치 구하기
//		for (int i = 1; i <= 100; i++)
//		{
//			if (max < arr[i])
//			{
//				max = arr[i];
//				maxId = i;
//			}
//			if (min > arr[i])
//			{
//				min = arr[i];
//				minId = i;
//			}
//		}
//		m = arr[maxId] - arr[minId];
//
//		caseCnt++;
//		printf("%d", m);
//	}
//
//
//	return 0;
//}