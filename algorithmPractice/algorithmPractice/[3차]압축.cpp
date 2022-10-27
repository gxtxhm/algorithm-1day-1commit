//    #include <string>
//    #include <vector>
//    #include <unordered_map>
//
//
//    using namespace std;
//
//    vector<int> solution(string msg) {
//        vector<int> answer;
//        unordered_map<string, int>um;
//        char al = 'A';
//
//        for (int i = 0; i < 26; i++)
//        {
//            string s = "";
//            s += al;
//            um.insert(make_pair(s, i + 1));
//            al++;
//        }
//        int r = 27;
//        int index = 0;
//        int len = 1;
//        while (msg.length() >index)
//        {
//            len = 1;
//            string s = msg.substr(index,len);
//            int before = um[s];
//            while (um.end() != um.find(s))
//            {
//                len++;
//                before = um[s];
//                s = msg.substr(index, len);
//                if (msg.length() <= index + len+1)break;
//            }
//            index+=(len-1);
//            um.insert(make_pair(s, r++));
//            answer.push_back(before);
//        }
//        return answer;
//    }
//
//int main()
//{
//    solution("ABABABABABABABAB");
//    return 0;
//}