## 아이디어

처음 보자마자 해쉬맵이 생각났다. 어떤 특정조합이 몇개 나왔는지 계산하면 되기 때문이다. 그런데 order문자열로 만들수 있는 모든 경우의 조합을 어떻게 만들지를 떠올리지 못하였다. for문으로 시도를 하였지만 몇 개의 조합으로 만들지가 정해지지 않았기에 애매했다. 

## 다른사람의 아이디어

구글링을 통해 풀이를 보았다. 해쉬맵을 동일하게 사용하였으나 위에서 내가 해결못한 모든 경우의 문자열을 만들어서 카운트하는 것을 재귀함수를 통해 구현하였다. 조합의 수가 (2~10)이기 때문에 11개의 해쉬맵 배열을 만들어서 주어지는 orders문자열들의 모든 조합을 파악한다. 
그리고 maxCnt배열에는 각 조합개수에서 최대로 중복된 수가 저장되어있다.


```cpp

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um[11];

int maxCnt[11] = { 0, };

void recur(string s, int cnt, string result)
{
    if (cnt == s.size())
    {
        int num = result.size();
        um[num][result]++;

        maxCnt[num] = max(maxCnt[num], um[num][result]);
        return;
    }

    recur(s, cnt + 1, result+s[cnt]);
    recur(s, cnt + 1, result);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    //  오름차순 정렬하기
    for (string& s : orders)
    {
        sort(s.begin(), s.end());

        recur(s, 0, "");
    }
    
    for (int i : course)
    {
        for (auto p : um[i])
        {
            if (p.second == maxCnt[i]&&maxCnt[i]>=2)answer.push_back(p.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<string>a = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> b = { 2,3,4 };
    solution(a, b);
    return 0;
}

```

## 새로 알게된 점과 아쉬운 점

```cpp
먼저 string의 멤버함수인 size()함수는 size_t 자료형을 리턴한다. 
그리고 c++,c에서는 +,- 등 연산 시 자동형변환을 하는데 이 때, 더 넓은 범위를 가진 자료형으로 형변환되어 계산된다. ex) int + double = double

내 코드에서 0<=s.size()-cnt (s.size()==2,cnt==3 이었다.) 이 조건에서 자꾸 참이 되는 오류가 발생했었다. 
size_t는 unsigned int64만큼의 크기를 가진다. 그리고 int는 int32이다. 따라서 int 보다 크기가 size_t + int 연산 시 결과값은 size_t가 되는데 unsigned이기 때문에 음수가 나올수가 없었다. 따라서 무조건 참이되는 것이었다. 


아쉬운 점은 재귀함수를 사용한 해법을 생각해내지 못하는 것이다. 안쓰다 보니 재귀함수적 사고도 약해지는 것 같다. for문 말고도 재귀적인 해법도 떠올리려고 노력해야겠다. 

```