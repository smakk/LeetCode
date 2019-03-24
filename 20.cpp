/*
一、问题描述
　　给定一个字符串，字符串中只包含'(', ')', '[', ']', '{', '}'，判断该字符串是否符合算术式括号的顺序。

　　例子：不符合的情况比如说“([)]”，符合的情况比如说“()”

二、问题解决
　　应该是很简单的一个问题了，使用一个栈，在遇到'('，'['，'{'时入栈，在遇到')'，']'，'}'时和栈定元素比较，如果是配对的，则将站定元素出栈，如果不配对，则直接返回错误。当遍历完整个字符串，且栈为空的时候，表明这个字符串括号的顺序是完整的。

　　下面的代码中使用了map将每个括号对关联起来，以便查找对于括号对。
*/

bool isValid(string s) {
    stack<char> stack;
    map<char, char> m = { {')','('},{'}','{'},{']','['} };
    for (auto i : s) {
        if (i == '(' || i == '[' || i == '{')
            stack.push(i);
        if (i == ')' || i == ']' || i == '}') {
            //bool  r = s.empty();
            if (stack.empty() == false && m[i] == stack.top())
                stack.pop();
            else
                return false;
        }
    }
    if(stack.empty())
        return true;
    return false;
}

int main()
{
    cout << isValid("]") << endl;

    system("pause");
    return 0;
}