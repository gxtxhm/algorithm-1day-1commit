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
//    // ���� ��ȣ üũ
//    for (int i = 0; i < 6; i++)
//    {
//        if (lottos[i] == 0) {
//            //0�� �����
//            zeroCnt++;
//        }
//        else lottosCnt[lottos[i]]=1;
//    }
//
//    //���� ���� ����� üũ
//    for (int i : win_nums)
//    {
//        if (lottosCnt[i] == 1)correctCnt++;
//    }
//    //�ְ��� �����ϱ�
//    //correctCnt+zeroCnt���� zeroCnt�� �� ������ �ְ�
//    //    �� Ʋ���� ����
//    int a = correctCnt + zeroCnt;
//    if (a >= 6)a = 6;
//
//    switch (a)
//    {
//        //�ְ��� 1��
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
//    //�������� �����ϱ�
//    //�˼����¹�ȣ zeroCnt�� �� �ٸ����
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