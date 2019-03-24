/*
 Word Pattern https://leetcode.com/problems/word-pattern/description/
 
 边界条件必须掌握好，长度必须一样，各个对于字符的对于关系处理方式参考205
*/

bool wordPattern(string pattern, string str) {
    map<char, string> m1;
    map<string, char> m2;
    int firstpos = 0;
    int i = 0;
    for (; i<pattern.size() && firstpos<str.size(); i++) {
        int nextspace = firstpos;
        while (nextspace<str.size() && str[nextspace] != ' ') {
            nextspace++;
        }
        string currents = str.substr(firstpos, nextspace - firstpos);
        //判断
        if (m1.find(pattern[i]) != m1.end() || m2.find(currents) != m2.end()) {
            if (m1[pattern[i]] != currents || m2[currents] != pattern[i])
                return false;
        }
        else {
            m1[pattern[i]] = currents;
            m2[currents] = pattern[i];
        }
        firstpos = nextspace + 1;
    }
    if (i >= pattern.size() && firstpos >= str.size())
        return true;
    else
        return false;
}
