//#include <string>
//#include <vector>
//using namespace std;
//
//// 그리디알고리즘 : 현재상황에 대한 최적해를 구하는 알고리즘.
//// 그리디를 사용했을 때 최적해가 나온다는 보장이 있어야함.
//
//
//int solution(string name) {
//    int answer = 0;
//
//    int i = 0;// A = 0 , Z = 25;
//
//    string info = name;
//    for (int i = 0; i < info.length(); i++)info[i] = 'A';
//
//    while(true)
//    {
//        if (info == name)break;
//        // 알파벳을 바꿔야하면 최적의 판단은 이동 대신 바꾸는 것.
//        if (info[i] != name[i])
//        {
//            if ((int)name[i] - 65 > 13)answer += 26 - ((int)name[i] - 65);
//            else answer += (int)name[i] - 65;
//            info[i] = name[i];
//            
//        }
//        // 커서를 이동해야 한다면 어디로?
//        else if (info[(i+1)%info.length()]!=name[(i + 1) % info.length()])
//        {
//            i = (i + 1) % info.length(); answer++;
//        }
//        else if (info[(i + 1) % info.length()] == name[(i + 1) % info.length()])
//        {
//            i--; if (i < 0)i = info.length() - 1; answer++;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    printf("%d",solution("ABAAAAAAAAABB"));
//    return 0;
//}