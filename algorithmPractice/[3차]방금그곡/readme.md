## 아이디어

먼저 #이 들어가는 음을 소문자로 바꾸는게 계산이 편할 것 같아서 바꾸자는 생각을 하였다. 
그리고 플레이시간과 곡길이를 파악하여 곡이 반복되는 경우에 곡을 쭉 이어붙인 악보에서 멜로디를 찾자는 생각을 하였다.
예를들어, 찾는 멜로디가 AB이고 악보가 EABD#이다.
플레이시간이 5이면 악보를 EABD#E로 바꾸는거다.
그리고 c++에 string.find함수를 통해 멜로디를 악보에서 찾으면 된다.

```cpp
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> split(string& s)
{
    vector<string>info;

    char separator = ',';
    std::istringstream iss(s);
    std::string str_buf;
    
    //HH:MM   HH:MM    제목    악보로 나눠짐
    while (getline(iss, str_buf, separator)) {
        info.push_back(str_buf);
    }
    vector<string>result;
    string im = "";
    im = info[0].substr(0, 2);
    int h1 = stoi(im);
    im = info[0].substr(3, 2);
    int m1 = stoi(im);
    im = info[1].substr(0, 2);
    int h2=stoi(im);
    im = info[1].substr(3, 2);
    int m2 = stoi(im);
    
    if (m1 > m2)
    {
        h2--; m2 += 60;
    }
    int rh = h2 - h1;
    int rm = m2 - m1;
    result.push_back(to_string(rh));
    result.push_back(to_string(rm));
    result.push_back(info[2]);

    int cnt = info[3].size();
    string r = "";
    for (int i=0;i<info[3].size();i++)
    {
        if (info[3][i] == '#')
        {
            cnt--; r[r.size() - 1] += 32;
        }
        else r += info[3][i];
    }
    result.push_back(to_string(cnt));
    result.push_back(info[3]);
    result.push_back(r);
    return result;
}
bool compare(const pair<string, int>& a, const pair<string, int>& b)
{
    //if (a.second < b.second)return true;
    if (a.second > b.second)return true;
    else return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    
    vector<pair<string, int>>result;
    string r = "";
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] == '#')r[r.size() - 1] += 32;
        else r += m[i];
    }

    //12:00,12:14,HELLO,CDEFGAB
    //정보분석
    // 플레이 시,플레이분,제목,악보길이,원래 악보,바꾼악보로 데이터변환
    int maxTime = -1;
    for (string& s : musicinfos)
    {
        vector<string>info = split(s);
        string song = info[5];
        //플레이 시간이 곡 길이보다 더 길면
        int playTime = stoi(info[0]) * 60 + stoi(info[1]);
        int cnt = stoi(info[3]);
        if (cnt < playTime)
        {
            while (cnt < playTime) {
                song += info[5]; cnt += stoi(info[3]);
            }
        }
        song = song.substr(0, playTime);
        //멜로디 찾기
        //찾았으면
        if (song.find(r) != string::npos)
        {
            if (maxTime < playTime)
            {
                maxTime = playTime; answer = info[2];
            }
            //result.push_back(make_pair(info[2], playTime));
        }
    }
    //if (result.size() == 0)return "(None)";
    //stable_sort(result.begin(), result.end(), compare);
    //answer = result[0].first;
    return answer;
}

int main()
{
    string s = "C#C";
    vector<string>a = { "12:00,12:06,HELLO,C#C#CC#" };
    solution(s, a);
    return 0;
}

```

## 아쉬운 점

문제를 내가 직접 푼 방법에서는 항상 몇가지가 통과가 안된다. 그러면 테스트케이스를 보면서 또는 반례를 보면서 항상 고쳐나가야한다. 한번에 맞는 코드를 못짜면 코딩테스트에서 통과가 안되는데 어떻게하면 한번에 통과하는 코드를 짤 수 있는지가 궁금하다.
이번에는 디테일한 부분에서 조금씩 실수가 있었다.