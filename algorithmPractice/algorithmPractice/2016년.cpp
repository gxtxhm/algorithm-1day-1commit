//#include <string>
//#include <vector>
//#include<iostream>
//using namespace std;
//
//// 왜 안되나 봤더니 cnt가 0인경우 cnt-1 인덱스에 접근하게 된다. 에러가 나야하는데 
//// 테스트 결과 실패라고만 떴다. 이런 경우도 조심해야겠다.
//
//int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//vector<string> bb = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
//string solution(int a, int b) {
//    string answer = "";
//    int cnt = 0;
//    for (int i = 0; i < a - 1; i++)cnt += month[i];
//
//    cnt += (b + 5);
//
//    cnt %= 7;
//    if (cnt == 0)cnt = 7;
//    answer += bb[cnt - 1];
//    return answer;
//}
//
//int main()
//{
//    cout << solution(1, 6);
//    return 0;
//}