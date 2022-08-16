#include<cstdio>
#include<vector>
#include<iostream>
#include <stack>


using namespace std;

//index라는 <int,int>배열을 이용해서 각 열의 가장 위쪽에 있는 인형의 좌표를 저장했다. 
// move가 1이 나오면 index의 첫번째 칸에 저장된 좌표로 바로 이동하여 보드에서 인형을 뽑는다.
// 인형을 뽑으면 index를 업데이트한다.

int solution(vector<vector<int>> board, vector<int> moves) {
    
    stack<int> stack;//바구니
    
    //라인별 가장 위에 있는 인형의 좌표를 저장한 1차원 배열
    vector<pair<int, int>>index;
    int n = 0;
    //board를 이용해 index초기화
    //먼저, n x n 보드의 n의 크기를 알아낸다.
    for (int id : board[0])
    {
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for ( j = 0; j < n; j++)
        {
            if (board[j][i] != 0)//밑으로 내려가며 확인, 빈칸이아니면
            {
                index.push_back(make_pair(j, i)); break;
            }
        }
        if (j == n)//그 라인은 인형이 없다는 뜻
        {
            index.push_back(make_pair(-1,-1));
        }
    }

    int answer = 0;
    //moves읽으며 하나씩 스택에 넣기
    for (int i : moves)
    {
        i--;
        // 해당 라인에 아무것도 없으니 패스
        if (index[i].first == -1 && index[i].second == -1)
        {

        }
        else//바구니에 넣고 비교하기
        {
            int x = index[i].first;
            int y = index[i].second;

            

            if (stack.empty())//비었다면 
            {
                // 인형을 바구니에 넣는다.
                stack.push(board[index[i].first][index[i].second]);
            }
            else
            {
                // 인형을 바구니에 넣는다.
                stack.push(board[index[i].first][index[i].second]);
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                
                if (a == b)
                    answer += 2;
                else
                {
                    stack.push(b);
                    stack.push(a);
                }
            }  
            board[x][y] = 0;
            //해당 라인을 바구니에 넣고 index 업데이트
            int update;
            for (update = x+1; update < n; update++)
            {
                if (board[update][y] != 0)
                {
                    index[y].first = update; break;
                }
            }
            if (update==n&&board[update-1][y]==0)
            {
                index[y].first = -1;
                index[y].second = -1;
            }
        }
    }
    return answer;
}



int main()
{
    vector<vector<int>> b = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };

    vector<int> mv = {1, 5, 3, 5, 1, 2, 1, 4};
    
    cout<<solution(b,mv);
}