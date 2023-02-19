//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<vector>
//#include <algorithm>
//
//using namespace std;
//
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//
//    vector<int>arr;
//
//    for (int i = 0; i < T; i++)
//    {
//        arr.clear();
//        int n;
//        scanf("%d", &n);
//        for (int j = 0; j < n; j++)
//        {
//            int im;
//            scanf("%d", &im);
//            arr.push_back(im);
//        }
//        // arr에서 최대값을 찾아준다.
//        int max = *max_element(arr.begin(), arr.end());
//        int money = 0;
//        int cnt = 0;
//        long long profit = 0;
//        vector<int>::iterator it;
//        for (it=arr.begin();it!=arr.end();it++)
//        {
//            if (*it != max)
//            {
//                cnt++;
//                money += *it;
//            }
//            else
//            {
//                if(cnt>0)profit += (cnt * max - money); 
//                cnt = 0; money = 0;
//                if(it+1!=arr.end())max = *max_element(it + 1, arr.end());
//            }
//        }
//        printf("#%d %lld\n", i + 1, profit);
//    }
//    return 0;
//}



// # 재귀함수 - 모든 경우 탐색
//int n;
//
//long long maxProfit;
//
//void recur(int num,long long profit,long long money,int cnt)
//{
//    if (num == n)
//    {
//        if (maxProfit < profit)
//            maxProfit = profit;
//        return;
//    }
//    //구매
//    recur(num + 1,profit ,money+arr[num],cnt+1);
//    // 구매 안함
//    recur(num + 1, profit, money, cnt);
//    //판매
//    if(cnt>0)recur(num + 1, profit + cnt * arr[num] - money, 0, 0);
//    
//}




// # 반복문 - 바로 다음 수와 비교해서 수익이 기대되면 사고 아니면 팔기
//{
//    int T;
//    int i;
//    //int n;
//    scanf("%d", &T);
//    for (i = 0; i < T; i++)
//    {
//        maxProfit = 0;
//        // 입력
//        scanf("%d", &n);
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[j]);
//        }
//        recur(0, 0, 0, 0);
//        printf("#%d %lld\n", i + 1, maxProfit);
//    }
//    return 0;
//}
    //{
    //    int cnt = 0;
    //    int money=0;// 지불한 돈
    //    int profit=0;// 수익

    //    // 동일한 가격일 때를 위한 변수
    //    bool equal=false;
    //    int eCnt = 0;
    //    int eMoney = 0;
    //     
    //    // 입력
    //    scanf("%d", &n);
    //    for (int j = 0; j < n; j++)
    //    {
    //        scanf("%d", &arr[j]);
    //    }

    //    for (int j = 0; j < n-1; j++)
    //    {
    //        // 수익이 기대될때
    //        if (arr[j] < arr[j+1])
    //        {
    //            if (equal)
    //            {
    //                equal = false;
    //                cnt += eCnt;
    //                money += eMoney;
    //                eCnt = 0; eMoney = 0;
    //            }
    //            //구매
    //            cnt++;
    //            money += arr[j];
    //        }
    //        else if (arr[j] > arr[j + 1])
    //        {
    //            if (equal)
    //            {
    //                equal = false;
    //                eCnt = 0; eMoney = 0;
    //            }
    //            //이전에 구매했다면 판매
    //            if (cnt > 0)
    //            {
    //                profit += (arr[j] * cnt - money);
    //                cnt = 0; money = 0;
    //            }
    //        }
    //        else
    //        {
    //            //가격이 동일할 때 따로 계산해두기
    //            equal = true;
    //            eCnt++;
    //            eMoney += arr[j];
    //        }
    //    }
    //    if (cnt != 0)
    //    {
    //        profit += (arr[n] * cnt - arr[money]);
    //    }
    //    printf("#%d %d\n", i + 1, profit);
    //}
//
//    return 0;
//}