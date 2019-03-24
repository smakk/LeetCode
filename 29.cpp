/*
一、问题描述
　　实现两个int数的相除，返回它们相除的int值，但是不能使用乘法、除法、和mod运算。

二、问题解决
　　最开始能想到的方法就是不断用被除数去减除数，等到被除数小于0的时候相减了多少轮就是两数相除的int值，但是一个很大的数除以一个很小的数可能会超时，实验一下，果然会超时。

　　要解决这个问题还需要使用减法，只是要想办法提高相减的次数。这里使用右移运算，假设被除数为M，除数为N，M第一次减去N，第二次减去N<<1，第三次减去（N<<1)<<1，使被除数快速的减小，当发现N右移n次后比M大的时候，用M减去N右移n-1次的结果，然后又重复上面的寻找n的步骤。由于每次是从N开始，相当于每次N*2的方式增大，但是有不用到乘法。

　　举个例子：假设使用M=15除N=3，第一次使用15-3，发现12大于3，然后又使用15-(3<<1)=9，发现9还是比3大，然后用15-((3<<1)<<1)=3，发现还是不小于3，于是使用15-(((3<<1)<<1)<<1)=-9，是小于3的，于是令M=15-((3<<1)<<1)=3，次数n=n+(1<<1)<<1=4(初始n=0)。再使用M(现在等于3)去减N(还是从初始N开始)，发现M-N<N，所以这次不用右移，n=n+1，所以n=5，即两数相除等于5。
*/

int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN && divisor==-1))return INT_MAX;
    int sig = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    int time = 0;
    long long d1 = labs(dividend);
    long long d2 = labs(divisor);
    while (d1 >= d2) {
        long long temp = d2, a = 1;
        while (d1 >= (temp << 1)) {
            temp <<= 1;
            a <<= 1;
        }
        d1 -= temp;
        time += a;
    }
    return sig == 1 ? time : -time;
}

int main()
{
    cout << divide(1,-1) << endl;

    system("pause");
    return 0;
}

/*
1、在这次的代码中，对dividend和divisor求绝对值的时候使用了long long类型，但凡考虑绝对值的情况一定考虑INT_MAX和INT_MIN的情况，这里如果对INT_MIN去绝对值就会溢出，所以使用long long类型。
1、在32位系统之中，long为32位，64位系统之中，long为64位。int始终为32位。
3、代码中在右移的时候使用变量a，a也是long long 类型，发现使用int值时会超时，而使用long long就不会。思考的是会不会64位系统之中64位数据移位运算会比32位数据移位运算更快？随手下了下面的例子：
*/
long long looptime = 100000000;

void test2() {
    long long a;
    for (int t = 0; t < looptime; t++) {
        for (auto i = 0; i < 30; i++) {
            a << i;
        }
    }
}

void test1() {
    int a;
    for (int t = 0; t < looptime; t++) {
        for (auto i = 0; i < 30; i++) {
            a << i;
        }
    }
}

int main()
{
    double start1, stop1, duration1, start2, stop2, duration2;
    start1 = clock();
    test1();
    stop1 = clock();
    start2 = clock();
    test2();
    stop2 = clock();
    duration1 = ((double)(stop1 - start1)) / CLK_TCK;
    duration2 = ((double)(stop2 - start2)) / CLK_TCK;
    cout << duration1 << " "<< duration2 <<endl;

    system("pause");
    return 0;
}

/*
发现事实好像并不是这样，和long long 还是int类型无关，倒是先算计算的一定比后计算的快，即duration1小于duration2，于是我改成两个测试函数一样，都使用int或都使用long long，发现还是这个结果。
我又使用同一函数，时刻1使用int值，时刻2使用long long，发现结果也并不是这样，使用long long时间又是也高过int。
没搞清楚这是为什么，希望以后能弄明白，现在先记在这里。
*/
