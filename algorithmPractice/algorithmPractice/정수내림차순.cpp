//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool compare(int i, int j)
//{
//    return i > j;
//}
//
//long long solution(long long n) {
//    long long answer = 0;
//    vector<int> a;
//    while (n > 0)
//    {
//        a.push_back(n % 10);
//        n /= 10;
//    }
//    sort(a.begin(), a.end(), compare);
//    answer += a[0];
//    for (int i = 1; i < a.size(); i++)
//    {
//        answer *= 10;
//        answer += a[i];
//    }
//    printf("%d",answer);
//    return answer;
//}
//int main()
//{
//    solution(1857612);
//    return 0;
//}