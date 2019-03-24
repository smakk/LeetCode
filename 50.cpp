/*
一、问题描述
　　求x的n次方

二、问题解决
1、最简单的思路，当n大于0时，对1乘n次x。当n小于0时，对1乘n次1/x。
*/

double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    double result = 1;
    for (long long i = 0; i < N; i++) {
        result = result * x;
    }
    return result;
}

//这是测试用例
int main()
{
    cout << myPow(2.0000,INT_MIN) << endl;

    system("pause");
    return 0;
}

/*
2、时间复杂度为log的解决。每次对n取n/2，对x取x的平方（如果n%2 == 1时结果还需乘一个n）。
*/

double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    double result = 1;
    double temp = x;
    for (long long i = N; i != 0; i /= 2) {
        if (i % 2 == 1)
            result = result * temp;
        temp = temp * temp;
    }
    return result;
}

//这是测试用例
int main()
{
    cout << myPow(2.0000,INT_MIN) << endl;

    system("pause");
    return 0;
}

/*
三、问题思考
　　本题注意n<0的情况，能转化成1/x的多少次方来求。但是注意INT_MIN取负的问题。
*/