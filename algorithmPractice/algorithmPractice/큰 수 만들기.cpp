//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(string number, int k) {
//    string answer="";
//
//    int n = number.length();
//
//    for (int i = 0, idx = -1; i < n - k; i++)
//    {
//        char max = '0';
//        for (int j = idx + 1; j <= i + k; j++)
//        {
//            if (max < number[j])
//            {
//                max = number[j];
//                idx = j;
//            }
//        }
//        answer += max;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    solution("4177252841",4);
//    return 0;
//}