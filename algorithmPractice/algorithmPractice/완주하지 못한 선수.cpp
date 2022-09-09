#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

// �ؽ� ������, ��� unordered_map�� �����ϴ� ����� �����ϱ� ���ؼ� �ϼ��ڵ带 �ô�.
// unordered_map�� string �� ������ �̸��� Ű��, �� ���ڸ� value�� �ϴ� �ؽø��� �����Ѵ�.
// find�Լ��� key�� ������ end()�� ���� ���� ��ȯ�Ѵٴ� ����� ������� if���� �����Ѵ�.
// ���� unordered_multimap������ �Ұ������� unordered_map������ [] ������ �����ϴ�. 
// �׷��� �ս��� ++,-- �������� ��� ���� �� ����� ã�� �� �ְԵȴ�.


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