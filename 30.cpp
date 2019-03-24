/*
一、问题描述
　　嗯，题目很难理解。

　　我按我的理解翻译一下：words中有“foo”和“bar”，我们就在s中寻找“foobar”或“barfoo”，返回它们在s中出现的第一个位置。（题目给出words中每一个字符串长度是相等的）

　　假如说words中有3个字符串，则在s中寻找寻找words中3个字符串的全排列中的一个，返回它在s中出现的位置

二、问题解决
　　思路：假设words中每个字符串长度为subslength，words中有wordnums个子串，我们从头遍历s，以wordnums*subslength这个长的字符串s_target为研究目标，然后在s_target中，每次取出subslength个字符（一共有wordnums个），在map结构see（表示在s_target中每个子串出现的次数）中增加该字符出现的次数，增加完之后和count（count为遍历words得出，表示words中每个子串应该出现的次数）之中做对比，如果出现see中没有出现的串或是一个串出现的次数多余count，则表示字符串不匹配，应该使用下一个s_target做目标。
*/

/*
需要牢记的一点是在for循环for (int i = 0; i < slength - subslength*wordnums + 1; i++)中i<slength - subslength*wordnums + 1的值。+1必须很明白。
*/

vector<int> findSubstring(string s, vector<string>& words) {
    //用来表示words中每个单词应该出现的次数
    unordered_map<string, int> count;
    for (auto i : words)
        count[i]++;
    vector<int> result;
    int slength = s.size(); 
    int wordnums = words.size();
    int subslength = words.at(0).length(); 
    for (int i = 0; i < slength - subslength*wordnums + 1; i++) {
        unordered_map<string, int> see;
        int j = 0;
        for (; j < wordnums; j++) {
            string temp = s.substr(i+j*subslength,subslength);
            see[temp]++;
            if (see[temp] > count[temp])
                break;
        }
        if (j == wordnums)
            result.emplace_back(i);
    }
    return result;
}

int main()
{
    vector<string> v = { "foo","bar" };
    vector<int> result = findSubstring("barfoothefoobarman",v);
    for (auto i : result)
        cout << i << endl;

    system("pause");
    return 0;
}