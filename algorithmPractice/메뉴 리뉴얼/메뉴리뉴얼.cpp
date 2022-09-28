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