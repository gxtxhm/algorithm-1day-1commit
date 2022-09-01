#include <string>
#include <vector>
#include <iostream>
using namespace std;


// ������ Ǫ�µ� ���� �����ð��� �ɷȴ�. ����Ž������ Ǯ��߰ڴٴ� ������ ���, ������ �ڿ� 
// �׽�Ʈ�� �غ��� �׽�Ʈ���̽� �ϳ��� ����־�� ������� �ߴ�. 
// ������ �¾����� ���ǵ��� �ϳ��� ��߳� �־���. ���� ���������� ������ �͵� �־���.
// ������ �ٲٰ� �������ǵ� �߰��ϴ� �ᱹ �����Ͽ���.

int result[11] = { 0, };
// ���̾��� �̱�� ��� ����� ���� ����
vector<vector<int>> results;
vector<int> diff;
// ����Ž�� ����
// n(ȭ��)�� ������ ����, score�� ���� ����¥���� ���ϴ���
void recur(int n,int score,vector<int> info_apeach)
{
    // ���������� �� �����־�� �Ѵ�.
    // -1�� �ƴ� 0���� �ϸ� ������ 0��¥���� 0�� ��츦 ���� üũ���� ���Ѵ�.
    if (score < -1)return;
    // n ��, ȭ���� ������ 0���� ���� ��� �Ǵ�
    if (n == 0)
    {
        int lion = 0;
        int apeach = 0;

        for (int i = 0; i < 11; i++)
        {
            // ���̾��� �� ���� ����ٸ�
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
        //���̾� ������ �� ���ٸ�
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
    // ȭ���� ���������� score�� ������� �Ǵ�
    // ȭ���� ��� ��� ������ ����ġ���� 1�ߴ������Ѵ�.
    //bool isShoot = false;
    //if (info_apeach[10 - score] < n)
    //{
    //    result[10 - score] = info_apeach[10 - score] + 1;
    //    isShoot = true;
    //    recur(n - result[10 - score], score - 1, info_apeach);
    //}
    //// �Ƚ�ų� ����� ���
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
    // �� ã�� ���
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
    //�� ã�� ���
    else
    {
        for (int j = 0; j < results.size(); j++)
        {
            if (max_value2 != diff[j])alive[j] = 1;
        }
    }
    // results �߿� ���� ���� ���� ���� ���� ��츦 ����
    int max_value = -1; int cnt = 0;// cnt �� ������ ���� ���� ���������� �Ǵ��ϴ� �����̴�.
    for (int i = 10; i >= 0; i--)
    {
         cnt = 0;
         max_value = -1;
        // 10-i������ ���� ���� ���� ��� ����
         for (int j = 0; j < results.size(); j++)
         {
             if (alive[j] == 0)
             {
                 if (max_value < results[j][i])
                 {
                     max_value = results[j][i]; cnt = 1;
                 }
                 else if (max_value == results[j][i])cnt++;// ���� ���� ��찡 2���̻��̶�� �� ���� ������ ���Ѵ�.
             }
            
         }
        // �� ã�� ���
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
        //�� ã�� ���
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

// �������̰� ���� ū ���� �ؾߵǰ� �������̰� ������ �� �� ������ ���� ����� �ؾ���

int main()
{
    vector<int> a = { 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3 };
    //vector<int> a = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    solution(10, a);
    //for (int i : solution(1, a))cout << i;
    cout << results.size();
    return 0;
}