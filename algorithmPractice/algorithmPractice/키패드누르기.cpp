#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int handType;// 1 = �޼�����, 2 = ����������
    if (hand == "left")handType = 1;
    else handType = 2;

    // �޼�, �������� �� ��ġ
    int left = 10;
    int right = 11;

    // keypad �� x,y ��ǥ �������� ��ġ�� �����Ѵ�. 
    // numbers �迭���� 1�� ���´ٸ� keypad�� 1���ε����� �����Ѵ�. ex) keypad[1] 
    // 1�� �ε������� ��ư 1�� ��ġ (0,0)�� �ִ�. �� keypad�� �Ÿ��� ����Ѵ�.
    vector<pair<int, int>> keypad;

    // Ű�� ��ġ ����
    keypad.push_back(make_pair(3, 1));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            keypad.push_back(make_pair(i, j));
        }
    }
    
    // * �� #
    keypad.push_back(make_pair(3, 0));
    keypad.push_back(make_pair(3, 2));
    for (int index : numbers)
    {
        if (index == 1 || index == 4 || index == 7)
        {
            left = index; answer.push_back('L');
        }
        else if (index == 3 || index == 6 || index == 9)
        {
            right = index; answer.push_back('R');
        }
        else
        {
            int Llen, Rlen;
            // �Ÿ��� ���Ѵ�.
            Llen = abs(keypad[left].first - keypad[index].first) + abs(keypad[left].second - keypad[index].second);
            Rlen = abs(keypad[right].first - keypad[index].first) + abs(keypad[right].second - keypad[index].second);
        
            //�޼հ����� �� ������
            if (Llen < Rlen)
            {
                left = index; answer.push_back('L');
            }
            //�����հ����� �� ������
            else if (Rlen < Llen)
            {
                right = index; answer.push_back('R');
            }
            //�Ÿ��� ������
            else
            {
                if (handType == 1) {
                    left = index; answer.push_back('L');
                }
                else {
                    right = index; answer.push_back('R');
                }
            }
        
        }
        
        
    }

    return answer;
}

int main()
{
    vector<int> a = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string b = "right";
    solution(a, b);
    return 0;
}