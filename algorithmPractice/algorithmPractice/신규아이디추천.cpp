//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//string solution(string new_id) {
//    string answer = "";
//
//    //1�ܰ� : ���ĺ� �ҹ��ڷ�
//    for (int i=0;i<new_id.length();i++)
//    {
//        if (isalpha(new_id[i])||isdigit(new_id[i]))//���ĺ��̳� �Ǵ� ���ڳ�
//        {
//            if (new_id[i] >= 65 && new_id[i] <= 90)//�빮���̸�
//                new_id[i] += 32;//�ҹ��ڷ�
//
//        }
//        else//���ĺ��̾ƴϸ�
//        {
//            if (new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.')
//            {
//                new_id.erase(i, 1); i--;
//            }
//        }
//    }
//    for (int i = 0; i < new_id.length(); i++)
//    {
//        // . �� 2�� �����̸� 
//        if (i != new_id.length() - 1 && new_id[i] == '.' && new_id[i + 1] == '.')
//        {
//            // erase�Լ��� ���� ������ ��ĭ�� �������� i�� 1�����ϱ� ������ 1���� ���ڰ� ���õȴ�.
//            // ���� i--�� �� ����� �Ѵ�.
//            new_id.erase(i, 1); i--;
//        }
//    }
//    // �� �հ� �� �ڰ� . �̸� ���� 
//    while (new_id[0] == '.')new_id.erase(0,1);
//    while (new_id[new_id.length()-1] == '.')new_id.erase(new_id.length()-1,1);
//
//
//    if (new_id.empty())new_id.push_back('a');
//    else if (new_id.length() >= 16) {
//        new_id = new_id.substr(0, 15);
//        while (new_id[new_id.length() - 1] == '.')new_id.erase(new_id.length() - 1);
//    }
//    if (new_id.length() <= 2)
//    {
//        while (new_id.length() <= 2)
//        {
//            new_id.push_back(new_id[new_id.length()-1]);
//        }
//    }
//    return new_id;
//}
//
//int main()
//{
//    string a = "...!@BaT#*..y.abcdefghijklm";
//    solution(a);
//    return 0;
//}