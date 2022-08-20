//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(vector<int> answers) {
//    vector<int> answer;
//    
//    int num1 = 0, num2 = 0, num3 = 0;// 각 사람이 맞힌 정답개수
//
//    //각 사람의 찍는 패턴
//    int answer_1[5] = { 1,2,3,4,5 };
//    int answer_2[8] = { 2,1,2,3,2,4,2,5 };
//    int answer_3[10] = { 3,3,1,1,2,2,4,4,5,5 };
//
//    int id_1 = 0, id_2 = 0, id_3 = 0;//각 패턴의 인덱스
//    //정답의 수만큼 즉, 문제수 만큼 반복함
//    for (int fid : answers)
//    {
//        if (answer_1[id_1] == fid)//1번이 fid번째 문제를 맞히면
//        {
//            num1++; 
//        }
//        if (answer_2[id_2] == fid)//2번이 fid번째 문제를 맞히면
//        {
//            num2++; 
//        }
//        if (answer_3[id_3] == fid)//3번이 fid번째 문제를 맞히면
//        {
//            num3++; 
//        }
//        id_1 = (id_1 + 1) % 5; id_2 = (id_2 + 1) % 8; id_3 = (id_3 + 1) % 10;
//    }
//    //printf("%d %d %d\n", num1, num2, num3);
//
//    //밑에 if문들은 num1,num2,num3 3개의 변수를 직접 비교하여 
//    //answer에 넣는다.
//    if (num1 > num2)
//    {
//        if (num1 > num3)
//        {
//            //num1이 1등
//            answer.push_back(1);
//        }
//        else if (num1 == num3)
//        {
//            answer.push_back(1); answer.push_back(3);
//        }
//        else
//        {
//            answer.push_back(3);
//        }
//    }
//    else if (num1 < num2)
//    {
//        if (num2 > num3)
//        {
//            //num2가 1등
//            answer.push_back(2);
//
//        }
//        else if (num2 == num3)
//        {
//            answer.push_back(2); answer.push_back(3);
//        }
//        else
//        {
//            answer.push_back(3);
//        }
//    }
//    else// num1==num2
//    {
//        if(num1<num3)
//        {
//            //num3 이 1등
//            answer.push_back(3);
//        }
//        else if (num1 == num3)
//        {
//            answer.push_back(1); answer.push_back(2); answer.push_back(3);
//        }
//        else
//        {
//            answer.push_back(1); answer.push_back(2);
//        }
//    }
//
//    return answer;
//}
//
//
//
//int main()
//{
//    vector<int> a = { 1,3,2,4,2 };
//    solution(a);
//}