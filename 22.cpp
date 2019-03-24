/*
一、问题描述
　　给一个数字n，求出所有可能的括号组合
　　例子：给定数字n，输出如下
　　　　　　()()()
　　　　　　()(())
　　　　　　(())()
　　　　　　(()())
　　　　　　((()))
二、问题解决
　　关键在于理解什么样的括号顺序是正确的，如何用程序表示出来。右括号的数量不能大于左括号，依次遍历所有可能，选出符合的。
三、问题思考　　 
　　本题可以结合第20题思考。当20题只包含一种括号的时候能不能不使用栈，而是通过左右括号的数量比较来实现。
*/

void par(vector<string> &v, string str, int n, int m) {
    if (n == 0 && m == 0) {
        v.push_back(str);
        return;
    }
    if (m > 0) {
        par(v, str + ")", n, m - 1);
    }
    if (n > 0) {
        par(v, str + "(", n - 1, m + 1);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    par(result, "", n, 0);
    return result;
}