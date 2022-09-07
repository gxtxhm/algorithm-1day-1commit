//#include <string>
//#include <vector>
//using namespace std;
//
//int solution(string s) {
//
//    // 길이가 1인 경우 for문을 돌지 않고 빠져나가서 빈 문자열이 반환되었었다. 
//    if (s.length() == 1)
//    {
//        return 1;
//    }
//
//    int answer = 0;
//    string min_str;
//    bool start = false;
//    bool isCompression = false;
//    //자르는 단위를 for문으로 하나씩 늘려간다.
//    for (int slice = 1; slice < s.size(); slice++)
//    {
//        int cnt = 1;
//        string unit_str = s.substr(0, slice);
//        string compStr = "";
//        isCompression = false;
//        // 문자열길이만큼 for문을 돈다.
//        for (int i = slice; i < s.length(); i += slice)
//        {
//            //isCompression = false;
//            // if 단위문자열이 같으면 숫자증가, 
//            if (unit_str == s.substr(i,slice))
//            {
//                cnt++; isCompression = true;
//            }
//            // 아니면 압축숫자와 문자열 + 하기
//            else
//            {
//                if (isCompression)
//                {
//                    // (char)cnt 로 강제 형변환하면 가끔 이상한 문자가 나와서 함수를사용했다.
//                    compStr += to_string(cnt) + unit_str;
//                }
//                else 
//                {
//                    compStr += unit_str;
//                }
//                isCompression = false;
//                cnt = 1;
//                //압축시킬 새로운 문자열
//                if (i + slice >= s.length())
//                {
//                    unit_str = s.substr(i);
//                    compStr += unit_str;
//                }
//                else {
//                    unit_str = s.substr(i, slice); 
//                }
//            }
//        }
//        //마지막 남은 문자열 붙이기
//        // 문자열이 abaccc같은 경우, 마지막c에서 cnt만 증가시키고 for문을 빠져나오게 된다.
//        // 그래서 for문 밖에 마지막으로 문자열 추가 코드를 넣었다.
//        if (cnt > 1)
//        {
//            compStr += to_string(cnt) +unit_str;
//        }
//        //else compStr += unit_str;
//        // 길이비교  
//        if (!start)
//        {
//            min_str = compStr; start = true;
//        }
//        else
//        {
//            if (min_str.length() > compStr.length())
//            {
//                min_str = compStr;
//            }
//        }
//    }
//
//    return min_str.length();
//}
//
//int main()
//{
//    solution("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
//
//    return 0;
//}