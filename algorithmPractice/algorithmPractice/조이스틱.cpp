//#include <string>
//#include <vector>
//using namespace std;
//
//// �׸���˰��� : �����Ȳ�� ���� �����ظ� ���ϴ� �˰���.
//// �׸��� ������� �� �����ذ� ���´ٴ� ������ �־����.
//
//
//int solution(string name) {
//    int answer = 0;
//
//    int i = 0;// A = 0 , Z = 25;
//
//    string info = name;
//    for (int i = 0; i < info.length(); i++)info[i] = 'A';
//
//    while(true)
//    {
//        if (info == name)break;
//        // ���ĺ��� �ٲ���ϸ� ������ �Ǵ��� �̵� ��� �ٲٴ� ��.
//        if (info[i] != name[i])
//        {
//            if ((int)name[i] - 65 > 13)answer += 26 - ((int)name[i] - 65);
//            else answer += (int)name[i] - 65;
//            info[i] = name[i];
//            
//        }
//        // Ŀ���� �̵��ؾ� �Ѵٸ� ����?
//        else if (info[(i+1)%info.length()]!=name[(i + 1) % info.length()])
//        {
//            i = (i + 1) % info.length(); answer++;
//        }
//        else if (info[(i + 1) % info.length()] == name[(i + 1) % info.length()])
//        {
//            i--; if (i < 0)i = info.length() - 1; answer++;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    printf("%d",solution("ABAAAAAAAAABB"));
//    return 0;
//}