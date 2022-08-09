#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


// �־��� ���ڿ� s���� ���ڷε� ����(ex: seven)�� �����ϱ� ���ؼ�
// string, int ������ ������ �������.
// 1���� 9������ ���縵�� �� 2���ڷ� ������ �����ϴ�.
// ���� �� �α��ڸ� string�� �����ϰ� int���� ���縵 ���� �����Ͽ���.

int solution(string s) {
    vector<pair<string, int>> index;

    // �����ϱ����� �ε���ǥ�� �����Ѵ�. 
    // ex) �� : ze => zero, 4 -> zero�� ���縵 ��
    index.push_back(make_pair("ze", 4));
    index.push_back(make_pair("on", 3));
    index.push_back(make_pair("tw", 3));
    index.push_back(make_pair("th", 5));
    index.push_back(make_pair("fo", 4));
    index.push_back(make_pair("fi", 4));
    index.push_back(make_pair("si", 3));
    index.push_back(make_pair("se", 5));
    index.push_back(make_pair("ei", 5));
    index.push_back(make_pair("ni", 4));
    
    // ������ ����
    int answer = 0;

    // i�� �Ű����� ���ڿ��� s�� �Ķ���� �����̴�.
    int i = 0;
    int sLen = s.length();
    
    while (i<sLen)
    {
        if (s[i]>=48&&s[i]<=57)//�����̸� - (�ƽ�Ű�ڵ�)
        {
            answer *= 10;
            answer = answer+(s[i] - 48);//���� '0~9' �� ���� '0~9'�� ��ȯ
            //���ڴ� 1ĭ�� �����ϱ� ������ +1�� �Ѵ�.
            i++;
        }
        else//���ڸ�
        {
            for (int j = 0;j < 10; j++)
            {
                //�� �ΰ��� ���縵�� ��ġ�ϸ�
                if (s[i] == index[j].first[0]&& s[i+1] == index[j].first[1])
                {
                    //���縵 ����ŭ �Ķ���͸� �̵���Ų��.
                    i += index[j].second;
                    answer = answer * 10;
                    answer = answer + j;
                    break;
                }
            }
        }
    }
    
    
    return answer;
}


int main()
{
    string s = "1one4five";
	printf("%d", solution(s));


	return 0;
}