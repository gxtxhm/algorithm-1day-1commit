#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


// 주어진 문자열 s에서 문자로된 숫자(ex: seven)를 구분하기 위해서
// string, int 데이터 구조를 만들었다.
// 1부터 9까지의 스펠링은 앞 2글자로 구분이 가능하다.
// 따라서 앞 두글자를 string에 저장하고 int에는 스펠링 수를 저장하였다.

int solution(string s) {
    vector<pair<string, int>> index;

    // 구분하기위한 인덱스표를 생성한다. 
    // ex) 뜻 : ze => zero, 4 -> zero의 스펠링 수
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
    
    // 리턴할 변수
    int answer = 0;

    // i가 매개변수 문자열인 s의 파라미터 변수이다.
    int i = 0;
    int sLen = s.length();
    
    while (i<sLen)
    {
        if (s[i]>=48&&s[i]<=57)//숫자이면 - (아스키코드)
        {
            answer *= 10;
            answer = answer+(s[i] - 48);//문자 '0~9' 를 숫자 '0~9'로 변환
            //숫자는 1칸을 차지하기 떄문에 +1을 한다.
            i++;
        }
        else//문자면
        {
            for (int j = 0;j < 10; j++)
            {
                //앞 두개의 스펠링이 일치하면
                if (s[i] == index[j].first[0]&& s[i+1] == index[j].first[1])
                {
                    //스펠링 수만큼 파라미터를 이동시킨다.
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