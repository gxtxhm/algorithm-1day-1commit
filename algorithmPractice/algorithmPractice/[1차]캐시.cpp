//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool isCacheHit(string& s, int cacheSize, vector<string>& cache)
//{
//    if (cacheSize==0) return false;
//    
//        // ĳ�� �̽��� ���
//        if (cache.end() == find(cache.begin(), cache.end(), s))
//        {
//            //�� �տ� ����
//            cache.insert(cache.begin(), s);
//            if (cache.size()-1 == cacheSize)
//            {
//                // ĳ�ð� ��á�ٸ� �� �ڿ� �ϳ� ����
//                cache.pop_back();
//            }
//            return false;
//        }
//        // ĳ�� ��Ʈ�� ���
//        else
//        {
//            // ������ �� ������ ������
//            cache.erase(find(cache.begin(), cache.end(), s));
//            cache.insert(cache.begin(), s);
//            return true;
//        }
//    
//    
//   
//}
//
//int solution(int cacheSize, vector<string> cities) {
//    int answer = 0;
//    vector<string>cache;
//    int index;
//    
//    // ���� �ҹ��ڷ�
//    for (int i = 0; i < cities.size(); i++)
//    {
//        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
//    }
//    
//    for (string s : cities)
//    {
//        //ĳ�� Hit�̸�
//        if (isCacheHit(s, cacheSize, cache))
//        {
//            answer++;
//        }
//        //ĳ�� miss��
//        else
//        {
//            answer += 5;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<string>c = { "Jeju", "Pangyo", "NewYork", "newyork" };
//    solution(2, c);
//    return 0;
//}