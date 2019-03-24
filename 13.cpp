/*
一、问题描述
　　将罗马数字转化成整数，数字范围在1到3999之间。
　　这题比较坑的是罗马数字，具体描述可以参见百度百科：https://baike.baidu.com/item/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97/772296?fr=aladdin
二、问题实现
　　思路比较简单，从前向后比较，如果前一个数大于等于后一个数，则将result和后面的数值相加，否则将result减去两倍前一个数，再加上后一个数（因为前一个数在之前已经加过一次，所以需要减两次）感觉要是从后向前遍历可以减少运算次数，因为在遇到减的时候不需要加一次再减两次。但是懒得写了。
*/
int romanToInt(string s) {
    unordered_map<char, int> m = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
    if (s.size() == 0) return 0;
    int result = m[s.at(0)];
    for (auto i = 1; i < s.size(); i++) {
        if (m[s.at(i-1)] >= m[s.at(i)])
            result = result + m[s.at(i)];
        else
            result = result + m[s[i]] - 2 * m[s[i-1]];
    }
    return result;
}

int main()
{
　　string s = "DCXXI";
　　cout << romanToInt(s) << endl;
 
　　system("pause");
　　return 0;
}