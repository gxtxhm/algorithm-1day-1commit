//#include <vector>
//#include <iostream>
//using namespace std;
//
//// 방금 전 에라토스테네스의 체를 이용한 소수찾기 알고리즘을 학습하여 바로 적용해보았다.
//// 3개 숫자의 합이 최대 3천이 나올 수 있으므로 3천까지의 수 중 소수인 수를 전부 찾아낸다.
//// 그것을 에라토스테네스의 체를 이용하여 구했다. 
//// 그리고 3중 포문을 통해 모든 경우의 수를 구하고 각 경우의 수가 소수가맞는지 미리 구해놓은 배열을 통해
//// 확인한다.
//int solution(vector<int> nums) {
//    int answer = 0;
//
//    int v[3000] = { 0, };
//
//
//    // 3천까지중 소수인 수만 걸러내기
//    for (int i = 2; i <= 3000; i++)
//    {
//        if (v[i] == 0)
//        {
//            for (int j = i + i; j <= 3000; j += i)
//                v[j] = 1;
//        }
//    }
//
//
//    int size = nums.size();
//    for (int i = 0; i < size - 2; i++)
//    {
//        for (int j = i + 1; j < size - 1; j++)
//        {
//            for (int k = j + 1; k < size; k++)
//            {
//                if (v[nums[j] + nums[k] + nums[i]] == 0)answer++;
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<int>a = { 1, 2, 3, 4 };
//    solution(a);
//    return 0;
//}