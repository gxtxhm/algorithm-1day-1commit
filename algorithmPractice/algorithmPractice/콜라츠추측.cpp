//#include <string>
//#include <vector>
//
//// 콜라츠 추측 문제인데, 테스트케이스 1개가 오류라서 살펴보았다.
//// 이 문제의 경우 int의 범위를 넘어서기 때문에 longlong형으로 변수타입을 바꿔저장해서 계산해야한다.
//// 문제를 풀 때, 계산범위가 어느정도일지 예측하여 변수타입을 지정하는 것도 신경을 써야겠다.
//
//
//using namespace std;
//
//int solution(int num) {
//    int answer = 0;
//    int cnt = 0;
//    if (num == 1)return 0;
//    
//
//    while (num > 1)
//    {
//        if (cnt == 500)return -1;
//        if (num % 2 == 0)num /= 2;
//        else if (num % 2 == 1)num = (num * 3 + 1);
//        cnt++;
//    }
//
//    return cnt;
//}
//
//int main()
//{
//    solution(626331);
//    return 0;
//}