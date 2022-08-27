#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int handType;// 1 = 왼손잡이, 2 = 오른손잡이
    if (hand == "left")handType = 1;
    else handType = 2;

    // 왼손, 오른손의 현 위치
    int left = 10;
    int right = 11;

    // keypad 에 x,y 좌표 형식으로 위치를 저장한다. 
    // numbers 배열에서 1이 나온다면 keypad의 1번인덱스에 접근한다. ex) keypad[1] 
    // 1번 인덱스에는 버튼 1의 위치 (0,0)이 있다. 이 keypad로 거리를 계산한다.
    vector<pair<int, int>> keypad;

    // 키의 위치 저장
    keypad.push_back(make_pair(3, 1));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            keypad.push_back(make_pair(i, j));
        }
    }
    
    // * 과 #
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
            // 거리를 구한다.
            Llen = abs(keypad[left].first - keypad[index].first) + abs(keypad[left].second - keypad[index].second);
            Rlen = abs(keypad[right].first - keypad[index].first) + abs(keypad[right].second - keypad[index].second);
        
            //왼손가락이 더 가까우면
            if (Llen < Rlen)
            {
                left = index; answer.push_back('L');
            }
            //오른손가락이 더 가까우면
            else if (Rlen < Llen)
            {
                right = index; answer.push_back('R');
            }
            //거리가 같으면
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