//#include <string>
//#include <vector>
//#include<sstream>
//#include<algorithm>
//using namespace std;
//
//// �����˻�_ver3
//
//// ó���� �ܼ��ϰ� ���� for���� �����鼭 Ǯ���µ� �׽�Ʈ���̽��� �� �������� ȿ�����׽�Ʈ���� 0���� �޾Ҵ�.
//// �ִ��� for�� Ƚ���� ���̰��� ����߰� for���� ������ �м��ϴ� �������� ���̴� ���� �Ұ����ϱ⿡ 
//// �м��� ������ �������� ī��Ʈ�Ҷ� ���̷��� ����ߴ�.
//// �� 3 * 2 * 2 * 2�� 24������ ��찡 �������� ���� �� �ִ�. 
//// �׷��� ���ڿ��� �ε���ȭ�Ͽ� �ش��ϴ� �ε����� ������ ����Ʈ�� �߰��Ͽ���.
//// ex) java backend junior pizza �� �����̸� jbjp�� �ؽ��Լ��� ���� 9�� ���� �� �ִ�.
//// �׸��� - �� ������ ����������� ����Լ��� ���� ������ �� �ִ� ����� ������ �� ���� ���ߴ�. - recursive()
//
//// �����˻�, �����˻�_ver2���� �׽�Ʈ���̽����� �ɸ��� �ð��� 10���� 1 �������� Ȯ �پ�����
//// �׷����� ȿ�����׽�Ʈ���� �� �����̽��� ������� ���ߴ�. 
//
////????????????????????????????????????? ��¶�� ���ڿ��� ���ȭ������.
//constexpr unsigned int Hash(const char* str) {
//    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * Hash(str + 1) : 8603;
//}
//
//// string�� �ٷ�� ��� �ձ��ڸ� ���� ��
//
//// �����ڸ� ǥ���ϴ� �ڷ���
//typedef struct {
//    /*string language;
//    string job;
//    string career;
//    string soulFood;*/
//    vector<char> useInfo; // 0 = language, 1 = job, 2 = career, 3 = soulFood
//    int scores;
//}Applicant;
//
//// - �� ��� �ڸ��� �ִ���.
//bool isDash[4];
//// splitString�Լ����� ��������� type, - �� ������� CountPassedApplicant()���� �ʿ�
//string type;
//
//// Ÿ���� �˷��ִ��Լ�
//int FindOutType(string type)
//{
//    switch (Hash(type.c_str()))
//    {
//    case Hash("cbjc"):return 0;
//    case Hash("cbjp"):return 1;
//    case Hash("cbsc"):return 2;
//    case Hash("cbsp"):return 3;
//    case Hash("cfjc"):return 4;
//    case Hash("cfjp"):return 5;
//    case Hash("cfsc"):return 6;
//    case Hash("cfsp"):return 7;
//
//    case Hash("jbjc"):return 8;
//    case Hash("jbjp"):return 9;
//    case Hash("jbsc"):return 10;
//    case Hash("jbsp"):return 11;
//    case Hash("jfjc"):return 12;
//    case Hash("jfjp"):return 13;
//    case Hash("jfsc"):return 14;
//    case Hash("jfsp"):return 15;
//
//    case Hash("pbjc"):return 16;
//    case Hash("pbjp"):return 17;
//    case Hash("pbsc"):return 18;
//    case Hash("pbsp"):return 19;
//    case Hash("pfjc"):return 20;
//    case Hash("pfjp"):return 21;
//    case Hash("pfsc"):return 22;
//    case Hash("pfsp"):return 23;
//    default:
//        break;
//    }
//}
//
//// ���� ���ڿ��� �и��Ͽ� applicant�� ����
//int splitString(int &index,string info, char separator = ' ')
//{
//    type = "";
//    std::istringstream iss(info);
//    std::string str_buf;
//    int i = 0;
//    bool exception = false;
//    for (int i = 0; i < 4; i++)isDash[i] = false;
//    while (getline(iss, str_buf, separator)) {
//        if (str_buf == "and")continue;
//        if (str_buf == "-") {
//            isDash[i] = true; exception = true;
//            i++; type += "-";
//        }
//        else if (i < 4)
//        {
//            type += str_buf[0]; i++;
//        }
//    }
//
//    // ���� - �� ������ -1 �����ؼ� - �� �ִٴ� ���� �˷��ְ� Count�Լ����� ����ó��
//    if (exception)index = -1;
//    else index = FindOutType(type);
//    
//    return stoi(str_buf);
//}
//int recur_cnt = 0;
//bool imsi[24];
//void recursive(vector<vector<int>>& applicants,int order,string t,int testerScore)
//{
//    // ������ ����
//    if (order >= 4)
//    {
//        
//        int index = FindOutType(t);
//        if (imsi[index])return;
//        for (int score : applicants[index])
//        {
//            if (score >= testerScore)recur_cnt++;
//        }
//        imsi[index] = true;
//    }
//    if (order == 0)
//    {
//        // ������ ��������̸�,
//        if (isDash[order])
//        {
//            recursive(applicants, order + 1, t + "c", testerScore);
//            recursive(applicants, order + 1, t + "j", testerScore);
//            recursive(applicants, order + 1, t + "p", testerScore);
//        }
//        else
//        {
//            recursive(applicants, order + 1, t + type[order], testerScore);
//        }
//    }
//    if (order == 1)
//    {
//        if (isDash[order])
//        {
//            recursive(applicants, order + 1, t + "b", testerScore);
//            recursive(applicants, order + 1, t + "f", testerScore);
//        }
//        else recursive(applicants, order + 1, t + type[order], testerScore);
//    }
//    if (order == 2)
//    {
//        if (isDash[order])
//        {
//            recursive(applicants, order + 1, t + "j", testerScore);
//            recursive(applicants, order + 1, t + "s", testerScore);
//        }
//        else recursive(applicants, order + 1, t + type[order], testerScore);
//    }
//    if (order == 3)
//    {
//        if (isDash[order])
//        {
//            recursive(applicants, order + 1, t + "c", testerScore);
//            recursive(applicants, order + 1, t + "p", testerScore);
//        }
//        else recursive(applicants, order + 1, t + type[order], testerScore);
//    }
//}
//
//// info���� ���� ���ڿ��� ������ applicant�ڷ����� ����
//void MakeApplicantsInfo(vector<vector<int>>& applicants, vector<string>& info)
//{
//    //
//    for (string s : info)
//    {
//        int index;
//        int score = splitString(index,s);
//
//        //splitString�Լ��� ���ھ ������.
//        applicants[index].push_back(score);
//        
//        
//    }
//}
//
//// query���ǿ� �����ϴ� �����ڰ� ������ ��ȯ
//int CountPassedApplicant(vector<vector<int>>& applicants, string query)
//{
//    int cnt = 0;
//    int index = 0;
//    // query �м� -> testerScore���� ���� ������ ���ϵ�.
//    int testerScore = splitString(index,query);
//
//    //index�� -1 �̸� ���� �� - �� �ִٴ� ��.
//    // �����ϴ� ��� ���� ������.
//
//    if (index == -1)
//    {
//        // �ε����� ���� �����ؼ� ����� cnt�� �� ����
//
//        // �ε��� �����
//        recur_cnt = 0;
//        recursive(applicants,0,"",testerScore);
//        cnt = recur_cnt;
//        // ���� �ε����� �����϶� �����ϴ� ������ �� cnt�� ���ϱ�
//    }
//    else
//    {
//        for (int score : applicants[index])
//        {
//            if (score >= testerScore)cnt++;
//        }
//    }
//
//    
//    
//    return cnt;
//}
//
//vector<int> solution(vector<string> info, vector<string> query) {
//    vector<int> answer;
//    vector<vector<int>>applicants;// 24���� ����� ���� �ְ�, �ش� ����� �� ���ھ�� ����.
//
//    //�ʱ�ȭ
//    for (int i = 0; i < 24; i++)applicants.push_back(vector<int>());
//
//    //
//    MakeApplicantsInfo(applicants, info);
//
//
//    for (string s : query)
//    {
//        for (int i = 0; i < 24; i++)imsi[i] = false;
//        answer.push_back(CountPassedApplicant(applicants, s));
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> b = {
//        "java backend junior pizza 150",
//        "python frontend senior chicken 210",
//        "python frontend senior chicken 150",
//        "cpp backend senior pizza 260",
//        "java backend junior chicken 80",
//        "python backend senior chicken 50"
//    };
//
//    vector<string> c = {
//        "java and backend and junior and pizza 100",
//        "python and frontend and senior and chicken 200",
//        "cpp and - and senior and pizza 250",
//        "- and backend and senior and - 150",
//        "- and - and - and chicken 100",
//        "- and - and - and - 150"
//    };
//    solution(b, c);
//    return 0;
//}