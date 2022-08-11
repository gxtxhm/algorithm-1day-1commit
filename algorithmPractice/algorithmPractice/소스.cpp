#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


struct info
{
    string user_id;
    vector<string>report_info;

};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    

    vector<info>Info;
    vector<pair<string, int>>cntUserReported;
    //먼저 info에 유저 리스트 등록
    for (int i = 0; i < id_list.size(); i++)
    {
        answer[i] = 0;
        struct info in;
        in.user_id = id_list[i];
        Info.push_back(in);
        cntUserReported.push_back(make_pair(id_list[i], 0));
    }
    //리포트 돌면서 신고당한 횟수 카운트
    for (int i = 0; i < report.size(); i++)
    {
        int index = report[i].rfind(' ');
        string user = report[i].substr(0, index);
        string repo = report[i].substr(index + 1);

        for (int j = 0; j < Info.size(); j++)
        {
            bool check = false;
            //이미uesr가 repo를 신고했었는지 확인
            if (Info[j].user_id == user)//해당 유저를 찾고
            {
                for (int k = 0; k < Info[j].report_info.size(); k++)
                {
                    // 이미 신고했었다면, 카운트 x
                    if (Info[j].report_info[k] == repo)
                    {
                        check = true;
                        break;
                    }
                }
                if (check)break;
                else
                {
                    //신고 처음이라면 카운트 1번하기
                    Info[j].report_info.push_back(repo);
                    for (int n = 0; n < cntUserReported.size(); n++)
                    {
                        if(cntUserReported[n].first==repo)cntUserReported[n].second++;
                    }
                    
                }
            }
            
        }
    }

    //마지막으로 정지된 유저를 파악하며 신고했던 유저가 받을 메일개수 파악하기

    //정지된 유저 파악하기
    vector<string>result;
    for (int i = 0; i < cntUserReported.size(); i++)
    {
        //해당유저가 k번이상 신고되었다면
        if (cntUserReported[i].second >= k)
        {
            result.push_back(cntUserReported[i].first);
        }
    }
    // 정지당한 유저를 신고했던 유저에게 메일보내기
    
    for (int j = 0; j < result.size(); j++)
    {
        for (int i = 0; i < Info.size(); i++)
        {
            for (int k = 0; k < Info[i].report_info.size(); k++)
            {
                if (result[j] == Info[i].report_info[k])
                {
                    answer[i]++; break;
                }
            }
        }
    }
    return answer;
}


int main()
{
    vector<string> a;
    a.push_back("muzi");
    a.push_back("frodo");
    a.push_back("apeach");
    a.push_back("neo");

    vector<string> b;
    b.push_back("muzi frodo");
    b.push_back("apeach frodo");
    b.push_back("frodo neo");
    b.push_back("muzi neo");
    b.push_back("apeach muzi");

    vector<int> c = solution(a, b, 2);

    for (int i = 0; i < c.size(); i++)
        printf("%d ", c[i]);
	return 0;
}