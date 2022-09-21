#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// 10������ k������, �������� �����
void TransformToKNumber(vector<int>& arr,int n, int k)
{
    int num = n;
    while (num > 0)
    {
        arr.push_back(num % k);
        num /= k;
    }
}

// k������ 10������
long long TransformToInteger(vector<int>& arr, int k)
{
    reverse(arr.begin(), arr.end());
    long long base = 1;
    long long sum = 0;
    for (int i : arr)
    {
        sum += i * base;
        base *= 10;
    }
    reverse(arr.begin(), arr.end());
    return sum;
}
// �Ҽ��� true ����
bool isPrime(long long num)
{
    if (num == 1)return false;
    for (long long i = 2; i*i <= num; i++)
    {
        if (num % i == 0)return false;
    }
    return true;
}
int solution(int n, int k) {
    //if (n == 1)return 0;
    int answer = 0;

    vector<int>arr;

    TransformToKNumber(arr, n, k);

    reverse(arr.begin(), arr.end());
    
    vector<int> p;
    int index=0;
    bool ch = false;
    bool last = false;
    for (int i = 0; i < arr.size(); i++)
    {
        
        if (arr[i] != 0)
        {
            if (!ch)
            {
                index = i; ch = true;
            }
            p.push_back(arr[i]);
        }
        else
        {
            last = true;
            if (p.size() == 0)continue;
            // P0
            if (index == 0 )
            {
                if (isPrime(TransformToInteger(p, k)))
                {
                    answer++; 
                }
                
            }
            
            // 0P0
            //���ڰ� �Ҽ��鼭
            else if (arr[index-1]==0 && isPrime(TransformToInteger(p, k)))
            {
                answer++;
            }
            p.clear(); ch = false;
        }
        // 0P
        if (last&&i == arr.size() - 1 && arr[index - 1] == 0 && isPrime(TransformToInteger(p, k)))
        {
            answer++;
        }
    }
    // P
    if (!last)
    {
        if (isPrime(TransformToInteger(p, k)))
        {
            answer++;
        }

    }
    return answer;
}

int main()
{
    
    solution(437674,3);
    return 0;
}