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
//        // arr���� �ִ밪�� ã���ش�.
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



// # ����Լ� - ��� ��� Ž��
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
//    //����
//    recur(num + 1,profit ,money+arr[num],cnt+1);
//    // ���� ����
//    recur(num + 1, profit, money, cnt);
//    //�Ǹ�
//    if(cnt>0)recur(num + 1, profit + cnt * arr[num] - money, 0, 0);
//    
//}




// # �ݺ��� - �ٷ� ���� ���� ���ؼ� ������ ���Ǹ� ��� �ƴϸ� �ȱ�
//{
//    int T;
//    int i;
//    //int n;
//    scanf("%d", &T);
//    for (i = 0; i < T; i++)
//    {
//        maxProfit = 0;
//        // �Է�
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
    //    int money=0;// ������ ��
    //    int profit=0;// ����

    //    // ������ ������ ���� ���� ����
    //    bool equal=false;
    //    int eCnt = 0;
    //    int eMoney = 0;
    //     
    //    // �Է�
    //    scanf("%d", &n);
    //    for (int j = 0; j < n; j++)
    //    {
    //        scanf("%d", &arr[j]);
    //    }

    //    for (int j = 0; j < n-1; j++)
    //    {
    //        // ������ ���ɶ�
    //        if (arr[j] < arr[j+1])
    //        {
    //            if (equal)
    //            {
    //                equal = false;
    //                cnt += eCnt;
    //                money += eMoney;
    //                eCnt = 0; eMoney = 0;
    //            }
    //            //����
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
    //            //������ �����ߴٸ� �Ǹ�
    //            if (cnt > 0)
    //            {
    //                profit += (arr[j] * cnt - money);
    //                cnt = 0; money = 0;
    //            }
    //        }
    //        else
    //        {
    //            //������ ������ �� ���� ����صα�
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