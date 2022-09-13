//#include <string>
//#include <vector>
//#include<sstream>
//#include<algorithm>
//#include <unordered_map>
//using namespace std;
//
//// unordered_map �̶�� �ؽ����̺� �ڷᱸ���� �𸣴� ���·� �������� ���� 
//// ����� ��츦 ó���ϴ� �κп��� ����Լ��� ���ؼ� ��� ����Ǽ��� ���Ҿ���.
//// unordered_map�� ���� -�� �����Ǵ� ��츦 4�������� ���� ���� ���� ���� ������ �����ߴ�.
//// �ؿ� �ּ�ó���� �κ��� �� �ȵǴ��� �𸣰ڴ�.
//
//string splitString(int& score, string info, char separator = ' ')
//{
//    string type = "";
//    std::istringstream iss(info);
//    std::string str_buf;
//    int i = 0;
//    bool exception = false;
//    while (getline(iss, str_buf, separator)) {
//        if (str_buf == "and")continue;
//        else if (str_buf == "-")
//        {
//            type += str_buf;i++;
//        }
//        else if (i < 4)
//        {
//            type += str_buf[0]; i++;
//        }
//    }
//    score = stoi(str_buf);
//    return type;
//}
//
//
//vector<int> solution(vector<string> info, vector<string> query) {
//    vector<int> answer;
//
//    unordered_map<string, vector<int>> um;
//    int score;
//
//    for (string in : info)
//    {
//        string sliced_string = splitString(score,in);
//        string type("",4);
//        for (int lang = 0; lang < 2; lang++)
//        {
//            type[0] = ((lang == 0) ? '-' : sliced_string[0]);
//            for (int job = 0; job < 2; job++)
//            {
//                type[1] = ((job == 0) ? '-' : sliced_string[1]);
//                for (int career = 0; career < 2; career++)
//                {
//                    type[2] = ((career == 0) ? '-' : sliced_string[2]);
//                    for (int food = 0; food < 2; food++)
//                    {
//                        type[3] = ((food == 0) ? '-' : sliced_string[3]);
//
//                        if (um.end() == um.find(type))
//                        {
//                            um.insert(make_pair(type, vector<int>()));
//                            um[type].push_back(score);
//                        }
//                        else
//                        {
//                            um[type].push_back(score);
//                        }
//                    }
//                    
//                }
//            }
//        }
//    }
//    //�ּ��� �ȵǴ� �ڵ� ������ ��
//    //for (auto value:um)
//    for (auto it=um.begin();it!=um.end();it++)
//    {
//        sort(it->second.begin(), it->second.end());
//        //sort(value.second.begin(), value.second.end());
//    }
//    for (string q : query)
//    {
//        int score;
//        string ss = splitString(score, q);
//
//        int count = 0;
//        
//        if (um.end() != um.find(ss))
//        {
//            auto s = lower_bound(um[ss].begin(), um[ss].end(), score);
//
//            if (s != um[ss].end())
//            {
//                count += um[ss].end() - s;
//            }
//        }
//        answer.push_back(count);
//    }
//    return answer;
//}
//
//int main()
//{
//    vector<string>i = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
//    vector<string>q = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
//
//    solution(i, q);
//    return 0;
//}