#include <string>
#include<vector>
using namespace std;

// ���� ���� 2���� �� ���ڿ� ���� ���ڸ� �����ϰ� �ٷιٷ� ����ߴµ� ���� ���� ���ϴ� 
// ��� ������ ���� �־��� �� ����.
// �̰��� �迭�� �ٲ㼭 �����ϴ� �ٷ� �ذ�Ǿ���.

int solution(string dartResult) {
    int answer = 0;
    int before = 0;
    int Bbefore = 0;
    vector<int>data;
    for (int i=0;i<dartResult.length();i++)
    {
        //10�� ���
        if (dartResult[i] == '1' && dartResult[i + 1] == '0')
        {
            if (dartResult[i + 2] == 'S')
            {
                data.push_back(10);
                
            }
            else if (dartResult[i + 2] == 'D')
            {
                data.push_back(100);
            }
            else
            {
                data.push_back(1000);
            }
            i++;
        }
        // 0~9�� ���
        else if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            if (dartResult[i+1] == 'S')
            {
                data.push_back(dartResult[i] - 48);
                
            }
            else if (dartResult[i+1] == 'D')
            {
                data.push_back((dartResult[i] - 48) * (dartResult[i] - 48));
            }
            else
            {
                data.push_back((dartResult[i] - 48) * (dartResult[i] - 48) * (dartResult[i] - 48));
                
            }
        }
        else if (dartResult[i] == '*')
        {
            data[data.size() - 1] *= 2; data[data.size() - 2] *= 2;
        }
        else if (dartResult[i] == '#')
        {
            data[data.size() - 1] *= -1;
        }
    }
    for (int i : data)answer += i;
    return answer;
}

int main()
{
    //string a = "1S2D*3T";
    string a = "1D#2S*3S";
    solution(a);
    return 0;
}