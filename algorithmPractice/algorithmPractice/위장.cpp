#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 이번 문제는 해시문제다. 
// 얼굴,상의,하의,겉옷 4가지 유형의 종류 중 현재 가지고 있는 옷을 입력받아서
// 코디할 수 있는 종류를 세는 것이다.
// 먼저 해시맵을 이용해 자료를 저장해야겠다는 생각을 했다.
// 4가지 유형을 키로 한 해시맵이다.
// 그리고 경우의 수를 셀 때 한 유형이 나올수 있는 경우는 입력받은 옷의 수 + 1이다.
// +1 은 안입는 경우이다. 
// 그렇게 모든 유형의 경우를 곱한 후 전부 안입는 경우를 뺀 -1을 하면 답이 나온다.

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, vector<string>> um;

    for (auto c : clothes)
    {
        if (um.end() == um.find(c[1]))
        {
            um.insert(make_pair(c[1], vector<string>()));
            um[c[1]].push_back(c[0]);
        }
        else
        {
            um[c[1]].push_back(c[0]);
        }
    }

    for (auto c : um)
    {
        answer *= (c.second.size()+1);
    }
    answer--;
    return answer;
}

int main()
{

    return 0;
}