/*
leetcode69
二分查找的变形，关键点在于怎样确定最终的位置，按照二分法最容易的想法就是如下代码：
*/

int mySqrt(int x) {
    long long pos1 = 0;
    long long pos2 = x;
    if (x <= 1) return x;
    while (pos1 < pos2) {
        long long mid = (pos1 + pos2) / 2;
        if (mid * mid == long long(x)) return mid;
        if (mid * mid > long long(x)) pos2 = mid;
        else pos1 = mid;
    }
    return pos1;
}

/*
这里需要注意的一点是当pos1 +1 = pos2时，会陷入死循环。
关键还是没有理解二分查找每个边界条件以及结尾两个指针的位置。正确答案如下：
*/

int mySqrt(int x) {
    long long pos1 = 0;
    long long pos2 = x;
    if (x <= 1) return x;
    while (pos1 < pos2) {
        long long mid = (pos1 + pos2) / 2;
        if (mid * mid == long long(x)) return mid;
        if (mid * mid > long long(x)) pos2 = mid;
        else pos1 = mid + 1;
    }
    return pos2-1;
}

/*
将pos1加一，如果加一之后的结果都大，那么循环退出时pos1 == pos2（这也是二分查找循环退出的很定条件，前一状态恒为pos+1==pos2），所以需要记住二分查找退出的前一状态和退出条件，这样才能做变形
*/