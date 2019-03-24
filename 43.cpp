/*
一、问题描述
翻译一下：给定两个string表示的数num1和num2，以string返回他们的乘积。num1满足如下条件：
1、num1和num2的长度都小于110。
2、num1和num2都只含有0-9。
3、num1和num2前都不以0开头。
4、不能使用string转int的任何函数
二、问题解决
　　思路一：将乘法拆解为加法，先实现两个string数的加法，再依次遍历num1，不断累加得出结果
*/

string stradd(string num1, string num2) {
    string result = "";
    int pos1 = num1.size()-1;
    int pos2 = num2.size()-1;
    int len = min(pos1,pos2) +1;
    int carry = 0;                    //用来标志有没有进位
    //从尾部向前相加，直达有一个数位数用完
    while (len > 0) {
        char c = num1[pos1] + num2[pos2] - '0' + carry;
        if (c > '9') {
            c = c - 10 ;
            carry = 1;
        }
        else
            carry = 0;
        result.insert(result.begin(),c);
        --pos1;
        --pos2;
        --len;
    }
    //如果两数位数相同，则看carry，有进位则前面加1，没有则直接返回
    if (num1.size() == num2.size()) {
        if (carry)
            result.insert(result.begin(), '1');
        return result;
    }
    //处理剩余部分
    string remain = "";
    if (num1.size() > num2.size())
        remain = num1.substr(0,pos1+1);
    else
        remain = num2.substr(0, pos2+1);
    if (remain == "0" && carry == 0)
        return result;
    //然后是remain加上carry位，将remain附加在result之前
    if (carry == 1) {
        int i = remain.size() - 1;
        for (; i>=0 ; --i) {
            if (remain[i] == '9')
                remain[i] = '0';
            else {
                ++remain[i];
                break;
            }
        }
        if (i < 0)
            remain.insert(remain.begin(),'1');
    }
    result = result.insert(0,remain);
    return result;
}
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    string result = "";
    string bit = "";
    for (int i = num1.size() - 1; i >= 0;--i) {
        string temp = bit;
        while (num1[i] != '0') {
            temp = stradd(temp,num2);
            --num1[i];
        }
        result = stradd(result,temp.append(bit));
        bit.append("0");
    }
    int i = 0;
    while( i+1< result.size()-1 && result[i] == '0')
        result = result.substr(i+1,result.size()-i);
    return result;
}

//这是测试用例
int main()
{
    string s1 = "9800"; string s2 = "294";
    cout << stradd(s1,s2) << endl;
    cout << stoi(s1) * stoi(s2) << endl;

    system("pause");
    return 0;
}

/*
思路二：自己的解答太繁琐，大佬的解答。题目只说了不能使用string转数，但是没说不能用乘法。
*/
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}

/*
三、问题思考
1、char转int的简便方式，使用char-‘0’可以得到（因为本身char就是一个数，可以参与运算）。
2、find_first_not_of的使用。
*/


