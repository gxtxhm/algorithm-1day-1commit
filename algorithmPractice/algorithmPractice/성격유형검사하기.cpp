//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(vector<string> survey, vector<int> choices) {
//    string answer = "";
//
//    // 유형,점수로 된 크키가 4인 배열
//    vector<pair<char, int>>table;
//    table.push_back(make_pair('R', 0));
//    table.push_back(make_pair('T', 0));
//    table.push_back(make_pair('C', 0));
//    table.push_back(make_pair('F', 0));
//    table.push_back(make_pair('J', 0));
//    table.push_back(make_pair('M', 0));
//    table.push_back(make_pair('A', 0));
//    table.push_back(make_pair('N', 0));
//    int cnt = 0;
//    for (int i : choices)
//    {
//        string s = survey[cnt++];
//        switch (i)
//        {
//        //동의
//        case 7:
//        case 6: 
//        case 5:
//            for (int j = 0; j < 8; j++)
//            {
//                if (s[1] == table[j].first)
//                {
//                    table[j].second += (i - 4); break;
//                }
//            }
//            break;
//        //점수 x
//        case 4:break;
//        //비동의
//        case 3: case 2: case 1:
//            for (int j = 0; j < 8; j++)
//            {
//                if (s[0] == table[j].first)
//                {
//                    table[j].second += -1*(i - 4); break;
//                }
//            }
//            break;
//
//        default:
//            break;
//        }
//
//    }
//    //점수에 따라유형선택
//    for (int i = 0; i < 8; i += 2)
//    {
//        if (table[i].second > table[i + 1].second)
//        {
//            answer += table[i].first;
//        }
//        else if (table[i].second == table[i + 1].second)
//        {
//            if (table[i].first > table[i + 1].first)
//            {
//                answer += table[i + 1].first;
//            }
//            else
//            {
//                answer += table[i].first;
//            }
//        }
//        else
//        {
//            answer += table[i + 1].first;
//        }
//    }
//
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> s = { "AN", "CF", "MJ", "RT", "NA" };
//    vector<int>c = { 5,3,2,7,5 };
//    solution(s, c);
//}