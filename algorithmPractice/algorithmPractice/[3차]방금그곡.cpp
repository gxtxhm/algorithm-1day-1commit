//#include <string>
//#include <vector>
//#include <sstream>
//#include <algorithm>
//using namespace std;
//
//vector<string> split(string& s)
//{
//    vector<string>info;
//
//    char separator = ',';
//    std::istringstream iss(s);
//    std::string str_buf;
//    
//    //HH:MM   HH:MM    제목    악보로 나눠짐
//    while (getline(iss, str_buf, separator)) {
//        info.push_back(str_buf);
//    }
//    vector<string>result;
//    string im = "";
//    im = info[0].substr(0, 2);
//    int h1 = stoi(im);
//    im = info[0].substr(3, 2);
//    int m1 = stoi(im);
//    im = info[1].substr(0, 2);
//    int h2=stoi(im);
//    im = info[1].substr(3, 2);
//    int m2 = stoi(im);
//    
//    if (m1 > m2)
//    {
//        h2--; m2 += 60;
//    }
//    int rh = h2 - h1;
//    int rm = m2 - m1;
//    result.push_back(to_string(rh));
//    result.push_back(to_string(rm));
//    result.push_back(info[2]);
//
//    int cnt = info[3].size();
//    string r = "";
//    for (int i=0;i<info[3].size();i++)
//    {
//        if (info[3][i] == '#')
//        {
//            cnt--; r[r.size() - 1] += 32;
//        }
//        else r += info[3][i];
//    }
//    result.push_back(to_string(cnt));
//    result.push_back(info[3]);
//    result.push_back(r);
//    return result;
//}
//bool compare(const pair<string, int>& a, const pair<string, int>& b)
//{
//    //if (a.second < b.second)return true;
//    if (a.second > b.second)return true;
//    else return false;
//}
//
//string solution(string m, vector<string> musicinfos) {
//    string answer = "(None)";
//    
//    vector<pair<string, int>>result;
//    string r = "";
//    for (int i = 0; i < m.length(); i++)
//    {
//        if (m[i] == '#')r[r.size() - 1] += 32;
//        else r += m[i];
//    }
//
//    //12:00,12:14,HELLO,CDEFGAB
//    //정보분석
//    // 플레이 시,플레이분,제목,악보길이,원래 악보,바꾼악보로 데이터변환
//    int maxTime = -1;
//    for (string& s : musicinfos)
//    {
//        vector<string>info = split(s);
//        string song = info[5];
//        //플레이 시간이 곡 길이보다 더 길면
//        int playTime = stoi(info[0]) * 60 + stoi(info[1]);
//        int cnt = stoi(info[3]);
//        if (cnt < playTime)
//        {
//            while (cnt < playTime) {
//                song += info[5]; cnt += stoi(info[3]);
//            }
//        }
//        song = song.substr(0, playTime);
//        //멜로디 찾기
//        //찾았으면
//        if (song.find(r) != string::npos)
//        {
//            if (maxTime < playTime)
//            {
//                maxTime = playTime; answer = info[2];
//            }
//            //result.push_back(make_pair(info[2], playTime));
//        }
//    }
//    //if (result.size() == 0)return "(None)";
//    //stable_sort(result.begin(), result.end(), compare);
//    //answer = result[0].first;
//    return answer;
//}
//
//int main()
//{
//    string s = "C#C";
//    vector<string>a = { "12:00,12:06,HELLO,C#C#CC#" };
//    solution(s, a);
//    return 0;
//}