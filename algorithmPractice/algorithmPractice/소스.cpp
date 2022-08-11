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
    //���� info�� ���� ����Ʈ ���
    for (int i = 0; i < id_list.size(); i++)
    {
        answer[i] = 0;
        struct info in;
        in.user_id = id_list[i];
        Info.push_back(in);
        cntUserReported.push_back(make_pair(id_list[i], 0));
    }
    //����Ʈ ���鼭 �Ű���� Ƚ�� ī��Ʈ
    for (int i = 0; i < report.size(); i++)
    {
        int index = report[i].rfind(' ');
        string user = report[i].substr(0, index);
        string repo = report[i].substr(index + 1);

        for (int j = 0; j < Info.size(); j++)
        {
            bool check = false;
            //�̹�uesr�� repo�� �Ű��߾����� Ȯ��
            if (Info[j].user_id == user)//�ش� ������ ã��
            {
                for (int k = 0; k < Info[j].report_info.size(); k++)
                {
                    // �̹� �Ű��߾��ٸ�, ī��Ʈ x
                    if (Info[j].report_info[k] == repo)
                    {
                        check = true;
                        break;
                    }
                }
                if (check)break;
                else
                {
                    //�Ű� ó���̶�� ī��Ʈ 1���ϱ�
                    Info[j].report_info.push_back(repo);
                    for (int n = 0; n < cntUserReported.size(); n++)
                    {
                        if(cntUserReported[n].first==repo)cntUserReported[n].second++;
                    }
                    
                }
            }
            
        }
    }

    //���������� ������ ������ �ľ��ϸ� �Ű��ߴ� ������ ���� ���ϰ��� �ľ��ϱ�

    //������ ���� �ľ��ϱ�
    vector<string>result;
    for (int i = 0; i < cntUserReported.size(); i++)
    {
        //�ش������� k���̻� �Ű�Ǿ��ٸ�
        if (cntUserReported[i].second >= k)
        {
            result.push_back(cntUserReported[i].first);
        }
    }
    // �������� ������ �Ű��ߴ� �������� ���Ϻ�����
    
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