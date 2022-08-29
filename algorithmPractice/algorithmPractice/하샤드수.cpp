//#include <string>
//#include <vector>
//#include<iostream>
//using namespace std;
//
//// 아주 쉬운 문제지만, return 부분에서 나머지 연산이 아닌 몫을 구하는 연산을 사용해서
//// 값이 나오지 않았었다. 디버깅을 하며 오류를 찾을 수 있었다.
//
//bool solution(int x) {
//    bool answer = true;
//    int num = 0;
//    int original = x;
//    
//    
//    while (x > 0)
//    {
//        num += x % 10;
//        x /= 10;
//    }
//    return ((original % num) == 0);
//}
//
//int main()
//{
//    cout << solution(10);
//}