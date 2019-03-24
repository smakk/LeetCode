/*
一、问题描述
　　这个题面是很难理解，简单总结一下：

　　从1开始，序列是1。到2的时候，读1的序列，发现只有1个1，2的序列为11。到3的时候，去读2的序列，发现2个1，即3的序列为21。到4的时候，读3的序列，发现3的序列为1个2加1个1，所以4的序列为1211。到5的时候，读4的序列，发现4为1个1，1个2，2个1（这里必须按顺序，而不能写成3个1，1个2），所以5的序列为111221。

二、问题解决
　　应该能很轻松解决，直接贴代码
*/

/*
这个问题在v=result的时候是否能使用move，应该是可以的。
*/

string countAndSay(int n) {
    vector<int> v = {1};
    for (int i = 1; i < n; i++) {
        int num = v[0]; int times=0;
        vector<int> result;
        for (auto j : v) {
            if (j == num)
                times++;
            else {
                result.emplace_back(times);
                result.emplace_back(num);
                num = j;
                times = 1;
            }
        }
        //将最后数和其次数记录添加到数组中
        result.emplace_back(times);
        result.emplace_back(num);
        v = result;
    }
    string s;
    for (auto i : v)
        s.append(to_string(i));
    return s;
}

int main()
{
    cout << countAndSay(5) << endl;

    system("pause");
    return 0;
}