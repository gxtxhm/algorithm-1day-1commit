#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, pair<string, int>>m;
    map<string, bool>m2;
    for (string s : records)
    {
        string time = s.substr(0, 5);
        string carNum = s.substr(6, 4);
        string order = s.substr(11);

        if (order == "IN")
        {
            if (m.end() == m.find(carNum))
            {
                m.insert(make_pair(carNum, make_pair(time, 0)));
                m2.insert(make_pair(carNum, true));
            }
            else
            {
                m[carNum].first = time;
                m2[carNum] = true;
            }
        }
        else
        {
            // 요금계산
            // 입차시간 구하기
            string n = m[carNum].first.substr(0, 2);
            int h = (n[0] - 48) * 10 + n[1] - 48;
            n = m[carNum].first.substr(3, 2);
            int m1 = (n[0] - 48) * 10 + n[1] - 48; 
            // 출차시간 구하기
            string n2 = time.substr(0, 2);
            int h2 = (n2[0] - 48) * 10 + n2[1] - 48;
            n2 = time.substr(3, 2);
            int m3 = (n2[0] - 48) * 10 + n2[1] - 48;    

            int t1 = h * 60 + m1; int t2 = h2 * 60 + m3;
            int t = t2 - t1;

            m[carNum].second += t;
            m2[carNum] = false;
        }
    }
    for (auto i : m2)
    {
        string carNum = i.first;
        
        if (i.second)
        {
            
            string n = m[carNum].first.substr(0, 2);
            int h = (n[0] - 48) * 10 + n[1] - 48;
            n = m[carNum].first.substr(3, 2);
            int m1 = (n[0] - 48) * 10 + n[1] - 48;

            int h2 = 23;
            int m3 = 59;

            int t1 = h * 60 + m1; int t2 = h2 * 60 + m3;
            int t = t2 - t1;
            m[carNum].second += t;
        }
    }
    //sort(m.begin(), m.end());
    for (auto i : m)
    {
        int t = i.second.second;
        int sum = 0;
        if (t <= fees[0])
        {
            sum += fees[1];
        }
        else
        {
            sum += fees[1] + ceil((t - fees[0]) / (double)fees[2]) * fees[3];
            /*if (t % fees[2] == 0)
            {
                sum += fees[1] + ((t - fees[0]) / fees[2]) * fees[3];
            }
            else
            {
                sum += fees[1] + ((t - fees[0]) / fees[2]+1) * fees[3];
            }*/
        }
        answer.push_back(sum);
    }
    return answer;
}
int main()
{
    vector<int>a = { 1, 461, 1, 10 };
    vector<string>b = { };
    solution(a, b); 
    return 0;
}