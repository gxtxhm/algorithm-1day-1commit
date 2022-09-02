#include <string>
#include <vector>

using namespace std;

// 문자열이 만들어지는 길이는 무조건 n이어야 했는데 그러지 않아서 1차로 문제가 있었다.
// 마찬가지로 1번 문제와 이어지는데 for문에서 2개의 이진수 길이가 같을때 포문을 빠져나오면 더 이상 
// 길이가 n인 문자열을 만드는 장치가 없었다. 그것을 추가했더니 해결되었다.
// 결국 문제파악을 제대로 못해서 생긴 일이었다. 
// 좀 더 꼼꼼히 파악해야겠다.
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    // for문에서 각 원소를 2진수로 바꾸어 # 과 ' '을 정한다.
    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int>a1;
        vector<int>a2;
        //각 원소를 2진수로 나누기
        while (arr1[i] > 0)
        {
            a1.push_back(arr1[i] % 2);
            arr1[i] /= 2;
        }
        while (arr2[i] > 0)
        {
            a2.push_back(arr2[i] % 2);
            arr2[i] /= 2;
        }
        // # 과 ' '정하기
        int size1 = a1.size(), size2 = a2.size();
        string an = "";
        int j = 0;
        for (j = 0; j < n; j++)
        {
            if (j == size1 || j == size2)
            {
                break;
            }
            else
            {
                // ' ' 추가
                if (a1[j] == 0 && a2[j] == 0)
                {
                    an += ' ';
                }
                else an += '#';
            } 
        }
        if (size1 > size2)
        {
            int i;
            for ( i = j; i < size1; i++)
            {
                if (a1[i] == 0)an += ' ';
                else an += '#';
            }
            for (int k = i; k < n; k++)an += ' ';
        }
        else if (size1 < size2)
        {
            int i;
            for ( i = j; i < size2; i++)
            {
                if (a2[i] == 0)an += ' ';
                else an += '#';
            }
            for (int k = i; k < n; k++)an += ' ';
        }
        else
        {
            for (int k = j; k < n; k++)an += ' ';
        }
        
        // 문자열 뒤집기
        for (int i = 0; i < an.length() / 2; i++)
        {
            char c = an[i];
            an[i] = an[an.length() - i - 1];
            an[an.length() - i - 1] = c;
        }
        answer.push_back(an);
    }
    // 그 문자열을 대입후 다음 원소확인
    return answer;
}

int main()
{
    vector<int> a = { 22,46, 33, 33, 31, 50 };
    //{ 22, 31,46, 33, 33,  50 };
    vector<int> b = { 14,27, 56, 19, 14, 10 };
    //{ 14, 14,27, 56, 19,  10 };
    solution(6, a, b);
    return 0;
}