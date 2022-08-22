//#include <string>
//#include <vector>
//#include <iostream>
//
//
//using namespace std;
//
//vector<int> solution(vector<int> lottos, vector<int> win_nums) {
//    vector<int> answer;
//
//    int lottosCnt[46] = { 0, };
//    int correctCnt = 0;
//    int zeroCnt = 0;
//    // 뽑은 번호 체크
//    for (int i = 0; i < 6; i++)
//    {
//        if (lottos[i] == 0) {
//            //0이 몇개인지
//            zeroCnt++;
//        }
//        else lottosCnt[lottos[i]]=1;
//    }
//
//    //맞은 수가 몇개인지 체크
//    for (int i : win_nums)
//    {
//        if (lottosCnt[i] == 1)correctCnt++;
//    }
//    //최고성적 결정하기
//    //correctCnt+zeroCnt에서 zeroCnt가 다 맞으면 최고
//    //    다 틀리면 최저
//    int a = correctCnt + zeroCnt;
//    if (a >= 6)a = 6;
//
//    switch (a)
//    {
//        //최고성적 1등
//    case 6:
//        answer.push_back(1); break;
//    case 5:
//        answer.push_back(2); break;
//    case 4:
//        answer.push_back(3); break;
//    case 3:
//        answer.push_back(4); break;
//    case 2:
//        answer.push_back(5); break;
//    case 1:
//        answer.push_back(6); break;
//    case 0:
//        answer.push_back(6); break;
//
//    default:
//        break;
//    }
//    //최저성적 결정하기
//    //알수없는번호 zeroCnt가 다 다른경우
//    switch (correctCnt)
//    {
//    case 6:
//        answer.push_back(1); break;
//    case 5:
//        answer.push_back(2); break;
//    case 4:
//        answer.push_back(3); break;
//    case 3:
//        answer.push_back(4); break;
//    case 2:
//        answer.push_back(5); break;
//    case 1: 
//    case 0:
//        answer.push_back(6); break;
//
//    default:
//        break;
//    }
//    return answer;
//}
//
//int main()
//{
//    vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
//    vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
//    vector<int> a=solution(lottos, win_nums);
//    cout << a[0] << a[1];
//    return 0;
//}