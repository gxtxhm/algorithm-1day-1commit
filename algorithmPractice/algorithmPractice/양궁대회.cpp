#include <string>
#include <vector>
#include <iostream>
using namespace std;


// 문제를 푸는데 정말 오랜시간이 걸렸다. 완전탐색으로 풀어야겠다는 생각이 들고, 구현한 뒤에 
// 테스트를 해보며 테스트케이스 하나씩 집어넣어보며 디버깅을 했다. 
// 로직은 맞았지만 조건들이 하나씩 어긋나 있었다. 또한 문제조건을 빼먹은 것도 있었다.
// 조건을 바꾸고 문제조건도 추가하니 결국 성공하였다.

int result[11] = { 0, };
// 라이언이 이기는 모든 경우의 수를 저장
vector<vector<int>> results;
vector<int> diff;
// 완전탐색 시작
// n(화살)의 개수를 전달, score는 현재 몇점짜리를 비교하는지
void recur(int n,int score,vector<int> info_apeach)
{
    // 종료지점을 잘 정해주어야 한다.
    // -1이 아닌 0으로 하면 마지막 0점짜리가 0일 경우를 전혀 체크하지 못한다.
    if (score < -1)return;
    // n 즉, 화살의 개수가 0개면 종료 결과 판단
    if (n == 0)
    {
        int lion = 0;
        int apeach = 0;

        for (int i = 0; i < 11; i++)
        {
            // 라이언이 더 많이 맞췄다면
            if (result[i] > info_apeach[i])
            {
                lion += (10 - i);
            }
            else if (result[i] == 0 && info_apeach[i] == 0)
            {

            }
            else
            {
                apeach += (10 - i);
            }
        }
        //라이언 점수가 더 높다면
        if (lion > apeach)
        {
            vector<int>win;
            for (int i = 0; i < 11; i++)win.push_back(result[i]);
            results.push_back(win);
            diff.push_back(lion - apeach);
            //for (int i : win)cout << i;
            //cout << endl;
        }
        return;
    }
    // 화살이 남아있으면 score를 맞출건지 판단
    // 화살을 쏘는 경우 무조건 어피치보다 1발더쏴야한다.
    //bool isShoot = false;
    //if (info_apeach[10 - score] < n)
    //{
    //    result[10 - score] = info_apeach[10 - score] + 1;
    //    isShoot = true;
    //    recur(n - result[10 - score], score - 1, info_apeach);
    //}
    //// 안쏘거나 못쏘는 경우
    //if (isShoot)result[10 - score] = 0;
    //recur(n, score - 1, info_apeach);
    for (int i = 0; i <= n; i++)
    {
        result[10 - score] = i;
        recur(n - i, score - 1, info_apeach);
        result[10 - score] = 0;
    }
}


vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    recur(n, 10, info);

    if (results.size() == 0)
    {
        answer.push_back(-1);
        return answer;
    }



    vector<int>alive;
    for (int i = 0; i < results.size(); i++)alive.push_back(0);

    int max_value2 = -1; int cnt2 = 0;
    int index;
    for (index = 0; index < diff.size(); index++)
    {
        if (max_value2 < diff[index])
        {
            max_value2 = diff[index]; cnt2 = 1;
        }
        else if (max_value2 == diff[index])cnt2++;
    }
    // 답 찾은 경우
    if (cnt2 == 1)
    {
        for (int j = 0; j < results.size(); j++)
        {
            if (diff[j] == max_value2)
            {
                answer = results[j];
                return answer;
            }
            
        }

    }
    //못 찾은 경우
    else
    {
        for (int j = 0; j < results.size(); j++)
        {
            if (max_value2 != diff[j])alive[j] = 1;
        }
    }
    // results 중에 가장 낮은 점수 많이 맞춘 경우를 고르기
    int max_value = -1; int cnt = 0;// cnt 는 포문을 돌며 답이 정해졌는지 판단하는 변수이다.
    for (int i = 10; i >= 0; i--)
    {
         cnt = 0;
         max_value = -1;
        // 10-i점수를 가장 많이 맞춘 경우 고르기
         for (int j = 0; j < results.size(); j++)
         {
             if (alive[j] == 0)
             {
                 if (max_value < results[j][i])
                 {
                     max_value = results[j][i]; cnt = 1;
                 }
                 else if (max_value == results[j][i])cnt++;// 많이 맞춘 경우가 2개이상이라면 더 높은 점수를 비교한다.
             }
            
         }
        // 답 찾은 경우
        if (cnt == 1)
        {
            for (int j = 0; j < results.size(); j++)
            {
                if (alive[j]==0 && max_value == results[j][i]) {
                    answer = results[j];
                    return answer;
                }
            }
        }
        //못 찾은 경우
        else
        {
            for (int j = 0; j < results.size(); j++)
            {
                if (max_value != results[j][i])alive[j] = 1;
            }
        }
    }

    return answer;
}

// 점수차이가 가장 큰 것을 해야되고 점수차이가 동일할 때 더 낮은거 많이 맞춘거 해야함

int main()
{
    vector<int> a = { 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3 };
    //vector<int> a = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    solution(10, a);
    //for (int i : solution(1, a))cout << i;
    cout << results.size();
    return 0;
}