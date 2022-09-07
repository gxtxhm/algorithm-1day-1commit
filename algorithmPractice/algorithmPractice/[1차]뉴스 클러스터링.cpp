#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include<iostream>

using namespace std;

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

    if (s1.size() == 0 && s2.size())return 65536;

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