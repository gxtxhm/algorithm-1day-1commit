//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//    vector<string> answer;
//
//    // for문에서 각 원소를 2진수로 바꾸어 # 과 ' '을 정한다.
//    for (int i = 0; i < arr1.size(); i++)
//    {
//        vector<int>a1;
//        vector<int>a2;
//        //각 원소를 2진수로 나누기
//        while (arr1[i] > 0)
//        {
//            a1.push_back(arr1[i] % 2);
//            arr1[i] /= 2;
//        }
//        while (arr2[i] > 0)
//        {
//            a2.push_back(arr2[i] % 2);
//            arr2[i] /= 2;
//        }
//        // # 과 ' '정하기
//        int size1 = a1.size(), size2 = a2.size();
//        string an = "";
//        int j = 0;
//        for (j = 0; j < n; j++)
//        {
//            if (j > size1 || j > size2)
//            {
//                break;
//            }
//            else
//            {
//                // ' ' 추가
//                if (a1[j] == 0 && a2[j] == 0)
//                {
//                    an += ' ';
//                }
//                else an += '#';
//            } 
//        }
//        if (size1 > size2)
//        {
//            for (int i = j + 1; i < n; i++)
//            {
//                if (a1[i] == 0)an += ' ';
//                else an += '#';
//            }
//        }
//        else if (size1 < size2)
//        {
//            for (int i = j + 1; i < n; i++)
//            {
//                if (a2[i] == 0)an += ' ';
//                else an += '#';
//            }
//        }
//        // 문자열 뒤집기
//        for (int i = 0; i < an.length() / 2; i++)
//        {
//            char c = an[i];
//            an[i] = an[an.length() - i - 1];
//            an[an.length() - i - 1] = c;
//        }
//        answer.push_back(an);
//    }
//    // 그 문자열을 대입후 다음 원소확인
//    return answer;
//}
//
//int main()
//{
//    vector<int> a = { 22, 31,46, 33, 33,  50 };
//    vector<int> b = { 14, 14,27, 56, 19,  10 };
//    solution(6, a, b);
//    return 0;
//}