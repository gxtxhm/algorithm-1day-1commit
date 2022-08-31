#include <string>
#include<vector>
using namespace std;

// 원래 변수 2개로 전 숫자와 전전 숫자를 관리하고 바로바로 계산했는데 내가 알지 못하는 
// 계산 오류가 많이 있었던 것 같다.
// 이것을 배열로 바꿔서 관리하니 바로 해결되었다.

int solution(string dartResult) {
    int answer = 0;
    int before = 0;
    int Bbefore = 0;
    vector<int>data;
    for (int i=0;i<dartResult.length();i++)
    {
        //10인 경우
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
        // 0~9인 경우
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