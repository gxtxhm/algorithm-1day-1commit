//#include <string>
//#include <vector>
//using namespace std;
//
//int solution(string s) {
//
//    // ���̰� 1�� ��� for���� ���� �ʰ� ���������� �� ���ڿ��� ��ȯ�Ǿ�����. 
//    if (s.length() == 1)
//    {
//        return 1;
//    }
//
//    int answer = 0;
//    string min_str;
//    bool start = false;
//    bool isCompression = false;
//    //�ڸ��� ������ for������ �ϳ��� �÷�����.
//    for (int slice = 1; slice < s.size(); slice++)
//    {
//        int cnt = 1;
//        string unit_str = s.substr(0, slice);
//        string compStr = "";
//        isCompression = false;
//        // ���ڿ����̸�ŭ for���� ����.
//        for (int i = slice; i < s.length(); i += slice)
//        {
//            //isCompression = false;
//            // if �������ڿ��� ������ ��������, 
//            if (unit_str == s.substr(i,slice))
//            {
//                cnt++; isCompression = true;
//            }
//            // �ƴϸ� ������ڿ� ���ڿ� + �ϱ�
//            else
//            {
//                if (isCompression)
//                {
//                    // (char)cnt �� ���� ����ȯ�ϸ� ���� �̻��� ���ڰ� ���ͼ� �Լ�������ߴ�.
//                    compStr += to_string(cnt) + unit_str;
//                }
//                else 
//                {
//                    compStr += unit_str;
//                }
//                isCompression = false;
//                cnt = 1;
//                //�����ų ���ο� ���ڿ�
//                if (i + slice >= s.length())
//                {
//                    unit_str = s.substr(i);
//                    compStr += unit_str;
//                }
//                else {
//                    unit_str = s.substr(i, slice); 
//                }
//            }
//        }
//        //������ ���� ���ڿ� ���̱�
//        // ���ڿ��� abaccc���� ���, ������c���� cnt�� ������Ű�� for���� ���������� �ȴ�.
//        // �׷��� for�� �ۿ� ���������� ���ڿ� �߰� �ڵ带 �־���.
//        if (cnt > 1)
//        {
//            compStr += to_string(cnt) +unit_str;
//        }
//        //else compStr += unit_str;
//        // ���̺�  
//        if (!start)
//        {
//            min_str = compStr; start = true;
//        }
//        else
//        {
//            if (min_str.length() > compStr.length())
//            {
//                min_str = compStr;
//            }
//        }
//    }
//
//    return min_str.length();
//}
//
//int main()
//{
//    solution("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
//
//    return 0;
//}