//#include <string>
//#include <vector>
//#include<sstream>
//#include<algorithm>
//using namespace std;
//
//// 순위검색_ver3
//
//// 처음엔 단순하게 전부 for문을 돌리면서 풀었는데 테스트케이스는 다 맞췄지만 효율성테스트에서 0점을 받았다.
//// 최대한 for문 횟수를 줄이고자 노력했고 for문을 정보를 분석하는 곳에서는 줄이는 것이 불가능하기에 
//// 분석된 정보를 바탕으로 카운트할때 줄이려고 노력했다.
//// 총 3 * 2 * 2 * 2로 24가지의 경우가 조건으로 나올 수 있다. 
//// 그래서 문자열을 인덱스화하여 해당하는 인덱스에 점수만 리스트로 추가하였다.
//// ex) java backend junior pizza 이 조건이면 jbjp로 해쉬함수를 통해 9로 만들 수 있다.
//// 그리고 - 로 조건이 상관없을때는 재귀함수를 통해 대입할 수 있는 경우의 수들을 다 만들어서 더했다. - recursive()
//
//// 순위검색, 순위검색_ver2보다 테스트케이스에서 걸리는 시간이 10분의 1 수준으로 확 줄었지만
//// 그럼에도 효율성테스트에서 단 한케이스도 통과하지 못했다. 
//
////????????????????????????????????????? 어쨋든 문자열을 상수화시켜줌.
//constexpr unsigned int Hash(const char* str) {
//    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * Hash(str + 1) : 8603;
//}
//
//// string을 다루는 대신 앞글자만 따서 비교
//
//// 지원자를 표시하는 자료형
//typedef struct {
//    /*string language;
//    string job;
//    string career;
//    string soulFood;*/
//    vector<char> useInfo; // 0 = language, 1 = job, 2 = career, 3 = soulFood
//    int scores;
//}Applicant;
//
//// - 가 어느 자리에 있는지.
//bool isDash[4];
//// splitString함수에서 만들어지는 type, - 가 있을경우 CountPassedApplicant()에서 필요
//string type;
//
//// 타입을 알려주는함수
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
//// 받은 문자열을 분리하여 applicant에 저장
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
//    // 만약 - 가 있으면 -1 리턴해서 - 가 있다는 것을 알려주고 Count함수에서 예외처리
//    if (exception)index = -1;
//    else index = FindOutType(type);
//    
//    return stoi(str_buf);
//}
//int recur_cnt = 0;
//bool imsi[24];
//void recursive(vector<vector<int>>& applicants,int order,string t,int testerScore)
//{
//    // 끝나는 조건
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
//        // 조건이 상관없음이면,
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
//// info에서 받은 문자열을 나눠서 applicant자료형에 저장
//void MakeApplicantsInfo(vector<vector<int>>& applicants, vector<string>& info)
//{
//    //
//    for (string s : info)
//    {
//        int index;
//        int score = splitString(index,s);
//
//        //splitString함수가 스코어만 리턴함.
//        applicants[index].push_back(score);
//        
//        
//    }
//}
//
//// query조건에 만족하는 지원자가 몇인지 반환
//int CountPassedApplicant(vector<vector<int>>& applicants, string query)
//{
//    int cnt = 0;
//    int index = 0;
//    // query 분석 -> testerScore에는 점수 조건이 리턴됨.
//    int testerScore = splitString(index,query);
//
//    //index가 -1 이면 조건 중 - 가 있다는 뜻.
//    // 부합하는 경우 전부 세야함.
//
//    if (index == -1)
//    {
//        // 인덱스를 공식 적용해서 만들고 cnt에 다 더함
//
//        // 인덱스 만들기
//        recur_cnt = 0;
//        recursive(applicants,0,"",testerScore);
//        cnt = recur_cnt;
//        // 만든 인덱스의 조건일때 만족하는 지원자 수 cnt에 더하기
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
//    vector<vector<int>>applicants;// 24개의 경우의 수가 있고, 해당 경우일 때 스코어들 저장.
//
//    //초기화
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