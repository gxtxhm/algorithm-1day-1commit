#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// �̹� ������ �ؽù�����. 
// ��,����,����,�ѿ� 4���� ������ ���� �� ���� ������ �ִ� ���� �Է¹޾Ƽ�
// �ڵ��� �� �ִ� ������ ���� ���̴�.
// ���� �ؽø��� �̿��� �ڷḦ �����ؾ߰ڴٴ� ������ �ߴ�.
// 4���� ������ Ű�� �� �ؽø��̴�.
// �׸��� ����� ���� �� �� �� ������ ���ü� �ִ� ���� �Է¹��� ���� �� + 1�̴�.
// +1 �� ���Դ� ����̴�. 
// �׷��� ��� ������ ��츦 ���� �� ���� ���Դ� ��츦 �� -1�� �ϸ� ���� ���´�.

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