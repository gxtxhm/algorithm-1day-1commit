//#include <string>
//#include <vector>
//
//using namespace std;
//
//// 첫번째 풀이
//int solution(int n) {
//    int answer = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        int cnt = 0;
//        for (int j = 2; j * j <= i; j++)
//        {
//            if (i % j == 0)cnt++;
//        }
//        if (cnt == 0)answer++;
//    }
//    return answer;
//}
//// 
//// 
//// 두번째 풀이 - 효율성 통과 풀이
//// 에라토스테네스의 체라는 수학 이론을 적용해야 풀 수 있다. 
//// 이 이론은 2부터 시작해서 각 수의 배수를 다 제거해나가는 방법으로 소수를 찾는 이론이다.
//// 2와 3은 소수이기 때문에 2부터 시작해서 n까지 for문을 돌면 일단 2,3,4...의배수들이 차례로 제거되며
//// 제거가 되지않은 수는 소수이다.
//int solution(int n) {
//    int answer = 0;
//    int v[1000001] = { 0, };
//    for (int i = 2; i <= n; i++)
//    {
//        if (v[i] == 0)
//        {
//            answer++;
//            for (int j = i; j <= n; j += i)
//            {
//                v[j] = 1;
//            }
//        }
//    }
//    return answer;
//}