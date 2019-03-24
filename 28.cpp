/*
一、问题描述
　　实现子串寻找，给定一个str1和str2，在str1中寻找str2第一次出现的位置，返回第一个字符在str1中的位置，如果没有找到则返回-1。

　　例子：haystack = "hello", needle = "ll"，返回2。

二、问题解决
　　对，没错，这就是KMP算法。

　　这里写了个简单好理解的吗，思路也很简单了，每次找到第一个字母相等的情况就拿str2和去比较后面的字符。
*/

int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size()) return -1;
    if (needle.size() == 0) return 0;
    if (haystack.size() == needle.size())
        if (haystack == needle)
            return 0;
        else
            return -1;
    for (int i = 0; i < haystack.size() - needle.size()+1; i++) {
        if (haystack.at(i) == needle.at(0)) {
            int temp = i;
            for (auto j : needle) {
                if (j != haystack.at(temp))
                    break;
                temp++;
            }
            if (temp - i == needle.size())
                return i;
        }
    }
    return -1;
}

int main()
{
    string s1 = "mississippi";
    string s2 = "pi";
    cout << strStr(s1,s2) << endl;

    system("pause");
    return 0;
}