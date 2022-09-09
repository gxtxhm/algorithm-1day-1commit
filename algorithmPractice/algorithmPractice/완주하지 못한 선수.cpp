#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

// 해시 문제로, 사실 unordered_map을 적용하는 방법을 공부하기 위해서 완성코드를 봤다.
// unordered_map로 string 즉 참가자 이름을 키로, 그 숫자를 value로 하는 해시맵을 구성한다.
// find함수는 key가 없으면 end()와 같은 값을 반환한다는 사실을 기반으로 if문을 구성한다.
// 또한 unordered_multimap에서는 불가하지만 unordered_map에서는 [] 연산이 가능하다. 
// 그래서 손쉽게 ++,-- 연산으로 통과 못한 한 사람을 찾을 수 있게된다.


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> ummap;

    for (auto p : participant)
    {
        if (ummap.end() == ummap.find(p))
            ummap.insert(make_pair(p, 1));
        else
            ummap[p]++;
    }
    for (string p : completion)
    {
        ummap[p]--;
    }
    for (auto p : participant)
    {
        if (ummap[p] > 0)
        {
            return p;
        }
    }
    return answer;
}

int main()
{

    return 0;
}