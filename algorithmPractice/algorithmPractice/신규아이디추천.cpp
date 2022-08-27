//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//string solution(string new_id) {
//    string answer = "";
//
//    //1단계 : 알파벳 소문자로
//    for (int i=0;i<new_id.length();i++)
//    {
//        if (isalpha(new_id[i])||isdigit(new_id[i]))//알파벳이냐 또는 숫자냐
//        {
//            if (new_id[i] >= 65 && new_id[i] <= 90)//대문자이면
//                new_id[i] += 32;//소문자로
//
//        }
//        else//알파벳이아니면
//        {
//            if (new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.')
//            {
//                new_id.erase(i, 1); i--;
//            }
//        }
//    }
//    for (int i = 0; i < new_id.length(); i++)
//    {
//        // . 이 2번 연속이면 
//        if (i != new_id.length() - 1 && new_id[i] == '.' && new_id[i + 1] == '.')
//        {
//            // erase함수를 쓰면 앞으로 한칸씩 땡겨지고 i가 1증가하기 때문에 1개의 문자가 무시된다.
//            // 따라서 i--를 꼭 해줘야 한다.
//            new_id.erase(i, 1); i--;
//        }
//    }
//    // 맨 앞과 맨 뒤가 . 이면 삭제 
//    while (new_id[0] == '.')new_id.erase(0,1);
//    while (new_id[new_id.length()-1] == '.')new_id.erase(new_id.length()-1,1);
//
//
//    if (new_id.empty())new_id.push_back('a');
//    else if (new_id.length() >= 16) {
//        new_id = new_id.substr(0, 15);
//        while (new_id[new_id.length() - 1] == '.')new_id.erase(new_id.length() - 1);
//    }
//    if (new_id.length() <= 2)
//    {
//        while (new_id.length() <= 2)
//        {
//            new_id.push_back(new_id[new_id.length()-1]);
//        }
//    }
//    return new_id;
//}
//
//int main()
//{
//    string a = "...!@BaT#*..y.abcdefghijklm";
//    solution(a);
//    return 0;
//}