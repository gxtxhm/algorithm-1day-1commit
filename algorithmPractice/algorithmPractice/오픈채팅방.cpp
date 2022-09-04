#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string,string> userInfo;// 유저의 아이디와 닉네임을 저장
    vector<string>userOrder;// record에서 입력받은 유저의 순서 , 아이디저장
    vector<char> status; // Enter,Leave,Change를 순서대로 저장

    // 정보를 구조화
    for (string s : record)
    {
        
        string im = s;
        int index=im.find(' ');
        int id2 = im.find(' ', index + 1);
        // 유저 아이디만 자름
        string user = im.substr(index + 1, id2-index-1);
        // 닉네임만 자름
        string nickname = im.substr(id2 + 1);
        status.push_back(s[0]);
        
        userOrder.push_back(user);
        if (s[0] == 'L')continue;
        // 아이디가 없으면 정보 등록
        if (userInfo.find(user) == userInfo.end())
        {
            userInfo.insert(pair<string, string>(user, nickname));
        }
        // 아이디가 이미 있으면 닉네임만 변경, 이 변경을 통해서 최신의 닉네임을 알아낼 수 있음.
        else
        {
            auto u = userInfo.find(user);
            u->second = nickname;
        }
        
    }
    // 닉네임을 최신화 한 다음, 한번에 결과 만들기
    for (int i = 0; i < record.size(); i++)
    {
        if (status[i] == 'C')continue;
        // userOrder에서 유저 찾기
        auto user = userInfo.find(userOrder[i]);
        string im = "";
        if (status[i] == 'E')
        {
            im += user->second;
            im += "님이 들어왔습니다.";
        }
        else if (status[i] == 'L')
        {
            im += user->second;
            im += "님이 나갔습니다.";
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