#include<cstdio>
#include<vector>
#include<iostream>
#include <stack>


using namespace std;

//index��� <int,int>�迭�� �̿��ؼ� �� ���� ���� ���ʿ� �ִ� ������ ��ǥ�� �����ߴ�. 
// move�� 1�� ������ index�� ù��° ĭ�� ����� ��ǥ�� �ٷ� �̵��Ͽ� ���忡�� ������ �̴´�.
// ������ ������ index�� ������Ʈ�Ѵ�.

int solution(vector<vector<int>> board, vector<int> moves) {
    
    stack<int> stack;//�ٱ���
    
    //���κ� ���� ���� �ִ� ������ ��ǥ�� ������ 1���� �迭
    vector<pair<int, int>>index;
    int n = 0;
    //board�� �̿��� index�ʱ�ȭ
    //����, n x n ������ n�� ũ�⸦ �˾Ƴ���.
    for (int id : board[0])
    {
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for ( j = 0; j < n; j++)
        {
            if (board[j][i] != 0)//������ �������� Ȯ��, ��ĭ�̾ƴϸ�
            {
                index.push_back(make_pair(j, i)); break;
            }
        }
        if (j == n)//�� ������ ������ ���ٴ� ��
        {
            index.push_back(make_pair(-1,-1));
        }
    }

    int answer = 0;
    //moves������ �ϳ��� ���ÿ� �ֱ�
    for (int i : moves)
    {
        i--;
        // �ش� ���ο� �ƹ��͵� ������ �н�
        if (index[i].first == -1 && index[i].second == -1)
        {

        }
        else//�ٱ��Ͽ� �ְ� ���ϱ�
        {
            int x = index[i].first;
            int y = index[i].second;

            

            if (stack.empty())//����ٸ� 
            {
                // ������ �ٱ��Ͽ� �ִ´�.
                stack.push(board[index[i].first][index[i].second]);
            }
            else
            {
                // ������ �ٱ��Ͽ� �ִ´�.
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
            //�ش� ������ �ٱ��Ͽ� �ְ� index ������Ʈ
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