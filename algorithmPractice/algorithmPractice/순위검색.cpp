//#include <string>
//#include <vector>
//#include<sstream>
//#include<algorithm>
//using namespace std;
//
//// �����ڸ� ǥ���ϴ� �ڷ���
//typedef struct {
//    /*string language;
//    string job;
//    string career;
//    string soulFood;*/
//    vector<string> useInfo; // 0 = language, 1 = job, 2 = career, 3 = soulFood
//    int scores;
//}Applicant;
//
//bool compare(Applicant& a, Applicant& b)
//{
//    if (a.scores > b.scores)return true;
//    else return false;
//}
//
//// ���� ���ڿ��� �и��Ͽ� applicant�� ����
//Applicant splitString(string info, char separator = ' ')
//{
//    Applicant applicant;
//    std::istringstream iss(info);
//    std::string str_buf;
//    int i = 0;
//    while (getline(iss, str_buf, separator)) {
//        if (str_buf == "and")continue;
//        if (i < 4)applicant.useInfo.push_back(str_buf); i++;
//    }
//    applicant.scores = stoi(str_buf);
//    return applicant;
//}
//
//// info���� ���� ���ڿ��� ������ applicant�ڷ����� ����
//void MakeApplicantsInfo(vector<Applicant>& applicants, vector<string>& info)
//{
//    for (string s : info)
//    {
//        applicants.push_back(splitString(s));
//    }
//}
//
//// query���ǿ� �����ϴ� �����ڰ� ������ ��ȯ
//int CountPassedApplicant(vector<Applicant>& applicants, string query)
//{
//    int cnt = 0;
//
//    // query �м�
//    Applicant tester = splitString(query);
//
//
//    for (Applicant a : applicants)
//    {
//        if (a.scores < tester.scores)break;
//        // ������ ������ ������
//        if (a.scores >= tester.scores)
//        {
//            //�ٸ� ���� üũ
//            bool isSatisfied = true;
//            for (int i = 0; i < 4; i++)
//            {
//                if (tester.useInfo[i] == "-")continue;
//                if (a.useInfo[i] != tester.useInfo[i])
//                {
//                    isSatisfied = false; break;
//                }
//            }
//            if (isSatisfied)cnt++;
//        }
//    }
//    return cnt;
//}
//
//vector<int> solution(vector<string> info, vector<string> query) {
//    vector<int> answer;
//    vector<Applicant>applicants;
//
//    MakeApplicantsInfo(applicants, info);
//
//    //���ھ� �������� applicants ����
//    sort(applicants.begin(), applicants.end(),compare);
//
//
//    for (string s : query)
//    {
//        answer.push_back(CountPassedApplicant(applicants,s));
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