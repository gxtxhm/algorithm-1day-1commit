#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include<iostream>

using namespace std;

// 리드미 파일 사용하는법 몰라서 일단 주석으로 씀.

// 1. 소문자로 문자열 변경 2. 다중집합으로 만듦 3. 오름차순으로 정렬
// 4. 교집합 개수 구하기 5. 합집합 개수 구하기

// 교집합은 id_s1, id_s2 2개의 인덱스로 0부터 비교해나가며 
// if s1,s2문자열이 같으면 , s1의 같은 문자열을 센다. 그리고 s2의 같은 문자열을 센다.
// 2개 중 더 작은 개수를 iCnt(교집합 원소의 개수)에 더한다.
// else면 s1,s2중 사전순으로 더 앞인 것의 인덱스 증가.

// 합집합도 거의 동일한 방식으로 개수를 구했다. 

// 다른 친구와 얘기를 해보니 훨씬 효율적으로 풀어냈다. 
// 교집합의 개수를 구할때 교집합의 개수는 두개의 집합 중 더 원소의 개수가 적은 집합의 원소개수를 
// 넘을 수 없다는 아이디어를 적용하여 소거법으로 풀어냈다. 
// ex) 더 원소가 적은 집합 A, 그렇지않은집합 B일때, A의 원소를 for문으로 돌며 B에서 하나씩 소거하며 
// 같으면 개수를 증가시켰다.
// 그리고 합집합의 개수는 n(A) + n(B) - n(A ^ B)의 공식을 이용하여 풀어냈다. 

// 코딩 전, 방법이 생각나도 한번 더 생각해보며 더 효율적인 방법을 찾으려는 노력이 필요해보인다.


void MakeMultipleSet(vector<string>& s,string str)
{
    for (int i = 0; i < str.length() - 1; i++)
    {
        // 두글자 모두 알파벳이면
        if (isalpha(str[i]) && isalpha(str[i + 1]))
        {
            string a;
            a += str[i];
            a += str[i + 1];
            s.push_back(a);
        }
    }
}


int solution(string str1, string str2) {
    int answer = 0;

    vector<string> s1;
    vector<string> s2;

    // 문자열의 대문자를 소문자로
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    //다중집합 만들기
    MakeMultipleSet(s1, str1);
    MakeMultipleSet(s2, str2);

    if (s1.size() == 0 && s2.size()==0)return 65536;

    // 오름차순 정렬
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    int id_s1 = 0;
    int id_s2 = 0;
    int cnt1 = 0, cnt2 = 0;
    int iCnt = 0;// 교집합 개수
    int SCnt = 0;// 합집합 개수
    
    // 교집합 개수 구하기
    while (id_s1 < s1.size() && id_s2 < s2.size())
    {
        // 같은 원소면
        if (s1[id_s1] == s2[id_s2])
        {
            int i = id_s1 + 1;
            while (i < s1.size()&&(s1[id_s1] == s1[i]))
            {
                i++;
            }
            cnt1 = i - id_s1;
            i = id_s2 + 1;
            while (i < s2.size()&&(s2[id_s2] == s2[i]))
            {
                i++;
            }
            cnt2 = i - id_s2;
            int minCnt = min(cnt1, cnt2);
            iCnt += minCnt;
            id_s1+=cnt1; id_s2+=cnt2;
        }
        else
        {
            if (s1[id_s1] < s2[id_s2])id_s1++;
            else id_s2++;
        }
    }
    cout << iCnt;
    id_s1 = 0; id_s2 = 0;
    // 합집합 개수 구하기
    while (id_s1 < s1.size() && id_s2 < s2.size())
    {
        // 같은 원소면
        if (s1[id_s1] == s2[id_s2])
        {
            int i = id_s1 + 1;
            while (i < s1.size() && (s1[id_s1] == s1[i]))i++;
            cnt1 = i - id_s1;
            i = id_s2 + 1;
            while (i < s2.size() && (s2[id_s2] == s2[i]))i++;
            cnt2 = i - id_s2;
            int maxCnt = max(cnt1, cnt2);
            SCnt += maxCnt;
            id_s1+=cnt1; id_s2+=cnt2;
        }
        else
        {
            if (s1[id_s1] < s2[id_s2])id_s1++;
            else id_s2++;
            SCnt++;
        }
    }
    // 남은 원소 
    // s1의 원소가 남았다면
    while (id_s1 < s1.size())
    {
        id_s1++; SCnt++;
    }
    // s2의 원소가 남았다면
    while (id_s2 < s2.size())
    {
        id_s2++; SCnt++;
    }
    cout << iCnt;
    cout << SCnt;
    double similarity = (double)iCnt / SCnt;
    answer = similarity * 65536;
    return answer;
}


int main()
{
    string a = "E=M*C^2";
    string b = "e=m*c^2";
    solution(a, b);
    return 0;
}