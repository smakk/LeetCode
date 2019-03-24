/*
一、问题描述
　　给定一个字符串s，s是由多个单词组成，单词之间以‘ ’分开,找出最后一个单词的长度。如果没有最后单词则返回0。

二、问题描述
　　先找到最后一个单词的末尾，因为s可能以空格结尾，所以从后往前找到第一个不是空格的字符。然后再向前找到该单词的起始位置。
*/

int lengthOfLastWord(string s) {
    if (s.size() == 0) return 0;
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ')
        i--;
    //逆序来看，此时i为第一个不为‘ ’的字符串
    int endpos = i;
    //i继续向前找，endpos不用变了
    for (; i >= 0; --i)
        if (s[i] == ' ')
            return endpos - i;
    if (i == -1)
        return endpos+1;
}

//这是测试用例
int main()
{
    string s = "hello world";
    cout << lengthOfLastWord(s) << endl;

    system("pause");
    return 0;
}