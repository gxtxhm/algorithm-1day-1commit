#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string,string> userInfo;// ������ ���̵�� �г����� ����
    vector<string>userOrder;// record���� �Է¹��� ������ ���� , ���̵�����
    vector<char> status; // Enter,Leave,Change�� ������� ����

    // ������ ����ȭ
    for (string s : record)
    {
        
        string im = s;
        int index=im.find(' ');
        int id2 = im.find(' ', index + 1);
        // ���� ���̵� �ڸ�
        string user = im.substr(index + 1, id2-index-1);
        // �г��Ӹ� �ڸ�
        string nickname = im.substr(id2 + 1);
        status.push_back(s[0]);
        
        userOrder.push_back(user);
        if (s[0] == 'L')continue;
        // ���̵� ������ ���� ���
        if (userInfo.find(user) == userInfo.end())
        {
            userInfo.insert(pair<string, string>(user, nickname));
        }
        // ���̵� �̹� ������ �г��Ӹ� ����, �� ������ ���ؼ� �ֽ��� �г����� �˾Ƴ� �� ����.
        else
        {
            auto u = userInfo.find(user);
            u->second = nickname;
        }
        
    }
    // �г����� �ֽ�ȭ �� ����, �ѹ��� ��� �����
    for (int i = 0; i < record.size(); i++)
    {
        if (status[i] == 'C')continue;
        // userOrder���� ���� ã��
        auto user = userInfo.find(userOrder[i]);
        string im = "";
        if (status[i] == 'E')
        {
            im += user->second;
            im += "���� ���Խ��ϴ�.";
        }
        else if (status[i] == 'L')
        {
            im += user->second;
            im += "���� �������ϴ�.";
        }
        
        answer.push_back(im);
    }


    return answer;
}

int main()
{
    vector<string> a = { 
        "Enter uid1234 Muzi", 
        "Enter uid4567 Prodo", 
        "Leave uid1234", 
        "Enter uid1234 Prodo", 
        "Change uid4567 Ryan" };
    solution(a);
    return 0;
}