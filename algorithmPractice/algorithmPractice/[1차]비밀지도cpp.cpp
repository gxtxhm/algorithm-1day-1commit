#include <string>
#include <vector>

using namespace std;

// ���ڿ��� ��������� ���̴� ������ n�̾�� �ߴµ� �׷��� �ʾƼ� 1���� ������ �־���.
// ���������� 1�� ������ �̾����µ� for������ 2���� ������ ���̰� ������ ������ ���������� �� �̻� 
// ���̰� n�� ���ڿ��� ����� ��ġ�� ������. �װ��� �߰��ߴ��� �ذ�Ǿ���.
// �ᱹ �����ľ��� ����� ���ؼ� ���� ���̾���. 
// �� �� �Ĳ��� �ľ��ؾ߰ڴ�.
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    // for������ �� ���Ҹ� 2������ �ٲپ� # �� ' '�� ���Ѵ�.
    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int>a1;
        vector<int>a2;
        //�� ���Ҹ� 2������ ������
        while (arr1[i] > 0)
        {
            a1.push_back(arr1[i] % 2);
            arr1[i] /= 2;
        }
        while (arr2[i] > 0)
        {
            a2.push_back(arr2[i] % 2);
            arr2[i] /= 2;
        }
        // # �� ' '���ϱ�
        int size1 = a1.size(), size2 = a2.size();
        string an = "";
        int j = 0;
        for (j = 0; j < n; j++)
        {
            if (j == size1 || j == size2)
            {
                break;
            }
            else
            {
                // ' ' �߰�
                if (a1[j] == 0 && a2[j] == 0)
                {
                    an += ' ';
                }
                else an += '#';
            } 
        }
        if (size1 > size2)
        {
            int i;
            for ( i = j; i < size1; i++)
            {
                if (a1[i] == 0)an += ' ';
                else an += '#';
            }
            for (int k = i; k < n; k++)an += ' ';
        }
        else if (size1 < size2)
        {
            int i;
            for ( i = j; i < size2; i++)
            {
                if (a2[i] == 0)an += ' ';
                else an += '#';
            }
            for (int k = i; k < n; k++)an += ' ';
        }
        else
        {
            for (int k = j; k < n; k++)an += ' ';
        }
        
        // ���ڿ� ������
        for (int i = 0; i < an.length() / 2; i++)
        {
            char c = an[i];
            an[i] = an[an.length() - i - 1];
            an[an.length() - i - 1] = c;
        }
        answer.push_back(an);
    }
    // �� ���ڿ��� ������ ���� ����Ȯ��
    return answer;
}

int main()
{
    vector<int> a = { 22,46, 33, 33, 31, 50 };
    //{ 22, 31,46, 33, 33,  50 };
    vector<int> b = { 14,27, 56, 19, 14, 10 };
    //{ 14, 14,27, 56, 19,  10 };
    solution(6, a, b);
    return 0;
}