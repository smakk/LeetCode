/*
一、问题描述
给定一系列区间，要求将其中重叠的、临接的区间合并成一个区间

例子：

给定[1,3],[2,6],[8,10],[15,18]

输出[1,6],[8,10],[15,18]

二、问题解决
第一步：先对区间按区间头进行排序

第二步：从第一个区间开始遍历，如果后一个区间与前一个区间有重叠或是紧挨着，则合并，并且继续往后读。如果没有，则将该区间加入result中，并且以下一个区间为起始区间重复这一步。
*/

//表示区间的结构
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
//排序函数
void mysort(vector<Interval>& intervals) {
    for (int i = 0; i < intervals.size(); i++) {
        int pos = i;
        while (pos < intervals.size()) {
            if (intervals[pos].start < intervals[i].start)
                swap(intervals[pos], intervals[i]);
            pos++;
        }
    }
}
vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> result;
    if (intervals.size() == 0) return result;
    mysort(intervals);
    int pos = 0;
    while (pos < intervals.size()) {
        Interval temp(intervals[pos].start,intervals[pos].end);
        while (++pos < intervals.size() && intervals[pos].start <= temp.end)
            temp.end = max(intervals[pos].end,temp.end);
        result.emplace_back(temp);
    }
    return result;
}

//这是测试用例
int main()
{
    vector<Interval> v = {Interval(1,4),Interval(0,4)};
    auto result = merge(v);
    for (auto i : result) {
        cout << i.start;
        cout << i.end;
        cout << endl;
    }

    system("pause");
    return 0;
}