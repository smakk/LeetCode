/*
一、问题描述
给定一个数字组成的string，其中每一个数字代表着下图的几个字符，要求输出他们的全排列

例子：给定字符串“23”，输出结果为["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

二、问题解决
　　这个问题很想数据结构里面的输出一个字符串全排列的例子，但是又不完全相同。

　　思路：按照递归的思想，每一个字符串S可以分成两个部分S1+S2，其中S1是开头的一个字符，S2是除去S1之后的所有字符，对于S2，可以递归调用得出结果，然后用S1中的每个字符和S2结果组成排列，可以得出最后结果。

　　实现：按照递归的要求，先找出返回的条件，在本例中，返回条件为输入字符串为空的时候
*/

vector<string> dig2str = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> letterCombinations(string digits) {
    vector<string> result;
　　//递归返回条件
    if (digits.size() == 0) 
        return result;

    string currentstr = dig2str[digits[0] - '2'];
　　//递归步骤
    vector<string> temp = letterCombinations(digits.substr(1));

　　//这里是由于测试用例中对于""字符串要求返回[]而不是[""]专门处理的，只有加上了""，下面的第二层遍历才能继续运行，当
　　//字符串长度为1的时候能进入运行第二层，从而将数据保证写入到result中。

    if(temp.size() == 0)
        temp.emplace_back("");
    for (auto i : currentstr)
        for (auto j : temp)
            result.emplace_back(i + j);
    return result;
}

int main()
{
    vector<string> v = letterCombinations("2");
    for (auto i : v)
        cout << i << endl;

    system("pause");
    return 0;
}