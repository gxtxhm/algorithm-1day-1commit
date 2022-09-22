## 아이디어

차량번호를 키로 pair<시간,누적시간>을 값으로 하는 해쉬맵에 모든 누적시간을
더해서 그 fees배열을 기준으로 요금을 계산한다.

```cpp
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

```

## 다른 사람의 아이디어 
1. in,out계산을 in일때 -계산, out일때 +계산을 하여 손쉽게 푼것을 보았다.
2. 해쉬맵에 value를 vector<string>으로 하여 in,out을 차량에 따라 저장해두고 한번에 계산하는 방법으로 코드가 엄청 짧았다.

## 기타

주석처리한 부분을 그 위(실수로 계산하여 ceil로 올림한 부분)코드로 바꾸었더니 정답이 나왔다. 왠지 주석처리한 부분이 걸려서 어떤게 문제일까 살펴봐도 모르겠어서 일단 바꿔봤더니 성공했다. 아직도 왜 성공한건지 무슨차이인건지 모르겠다. 