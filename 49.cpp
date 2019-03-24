/*
一、问题描述
二、问题解决
　　自己的想法，最后一个用例超时了，太过于复杂繁琐。（使用map数组来保存每个字符串字母出现的频率）
*/

bool check_map(map<char, int>& m1, map<char, int>& m2) {
    if (m1.size() != m2.size()) return false;
    for (auto i = m1.begin(); i != m1.end(); i++) {
        if (m1[i->first] != 2 * m2[i->first])
            return false;
    }
    return true;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    vector<map<char,int>> char_times;
    for (int i = 0; i < strs.size(); i++) {
        int find = -1;    //记录下寻找到的位置，没有找到则保持-1.
        for (int j = 0; j < result.size() && find == -1; j++) {
            //如果长度一样，则逐个字符比较
            if (result[j][0].size() == strs[i].size()) {
                
                map<char, int> u = char_times[j];
                for (int k =0; k < strs[i].size(); k++)
                    u[strs[i][k]]++;

                //表示找到了和strs[i]相匹配的字符串，用find记录下位置
                if (check_map(u, char_times[j])) {
                    find = j;
                }
            }
        }
        //表示没有找到，则需要添加strs[i]到新的vector<string>，然后将其加到result，然后还要在map中建立数据
        if (find == -1) {
            vector<string> v;
            v.push_back(strs[i]);
            result.push_back(v);
            map<char, int> m;
            for (auto o : strs[i])
                m[o] ++;
            char_times.push_back(m);
        }//找到了，则在位置find添加该字符串
        else
            result[find].push_back(strs[i]);
    }
    return result;
}

//这是测试用例
int main()
{
    vector<string> v =  {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(v);
    for (auto i : result) {
        for (auto j : i) {
            cout << j;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}

/*
更简单的答案
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }


/*
三、问题思考
　　关键在于两点没有把握好：1、string能使用sort算法，即string的遍历器不够了解。2、multiset的使用。关键还是STL不够熟悉。
*/

