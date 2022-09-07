#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include<iostream>

using namespace std;

// ����� ���� ����ϴ¹� ���� �ϴ� �ּ����� ��.

// 1. �ҹ��ڷ� ���ڿ� ���� 2. ������������ ���� 3. ������������ ����
// 4. ������ ���� ���ϱ� 5. ������ ���� ���ϱ�

// �������� id_s1, id_s2 2���� �ε����� 0���� ���س����� 
// if s1,s2���ڿ��� ������ , s1�� ���� ���ڿ��� ����. �׸��� s2�� ���� ���ڿ��� ����.
// 2�� �� �� ���� ������ iCnt(������ ������ ����)�� ���Ѵ�.
// else�� s1,s2�� ���������� �� ���� ���� �ε��� ����.

// �����յ� ���� ������ ������� ������ ���ߴ�. 

// �ٸ� ģ���� ��⸦ �غ��� �ξ� ȿ�������� Ǯ��´�. 
// �������� ������ ���Ҷ� �������� ������ �ΰ��� ���� �� �� ������ ������ ���� ������ ���Ұ����� 
// ���� �� ���ٴ� ���̵� �����Ͽ� �ҰŹ����� Ǯ��´�. 
// ex) �� ���Ұ� ���� ���� A, �׷����������� B�϶�, A�� ���Ҹ� for������ ���� B���� �ϳ��� �Ұ��ϸ� 
// ������ ������ �������״�.
// �׸��� �������� ������ n(A) + n(B) - n(A ^ B)�� ������ �̿��Ͽ� Ǯ��´�. 

// �ڵ� ��, ����� �������� �ѹ� �� �����غ��� �� ȿ������ ����� ã������ ����� �ʿ��غ��δ�.


void MakeMultipleSet(vector<string>& s,string str)
{
    for (int i = 0; i < str.length() - 1; i++)
    {
        // �α��� ��� ���ĺ��̸�
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

    // ���ڿ��� �빮�ڸ� �ҹ��ڷ�
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    //�������� �����
    MakeMultipleSet(s1, str1);
    MakeMultipleSet(s2, str2);

    if (s1.size() == 0 && s2.size()==0)return 65536;

    // �������� ����
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    int id_s1 = 0;
    int id_s2 = 0;
    int cnt1 = 0, cnt2 = 0;
    int iCnt = 0;// ������ ����
    int SCnt = 0;// ������ ����
    
    // ������ ���� ���ϱ�
    while (id_s1 < s1.size() && id_s2 < s2.size())
    {
        // ���� ���Ҹ�
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
    // ������ ���� ���ϱ�
    while (id_s1 < s1.size() && id_s2 < s2.size())
    {
        // ���� ���Ҹ�
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
    // ���� ���� 
    // s1�� ���Ұ� ���Ҵٸ�
    while (id_s1 < s1.size())
    {
        id_s1++; SCnt++;
    }
    // s2�� ���Ұ� ���Ҵٸ�
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