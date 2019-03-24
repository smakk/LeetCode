/*
一、问题描述
　　给定一个升序排列的数组nums，和一个目标数target，找出nums中target的索引范围。

　　例子：给定数组为{5, 7, 7, 8, 8, 10}，target=8。返回{3，4}

二、问题解决
　　思路一：直接遍历就可以，第一次碰到target的时候记录位置1，继续遍历到不是target或数组尾，记录下位置2。时间复杂度为n

1、注意当数组长度为0的时候，找不到元素的时候这两种情况的边界条件

2、熟记二分查找寻找边界
*/

vector<int> searchRange1(vector<int>& nums, int target) {
    vector<int> result = {-1,-1};
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            result[0] = i;
            while (i < nums.size() && nums[i] == target)
                i++;
            result[1] = i - 1;
            return result;
        }
    }
    return result;
}

int main()
{
    vector<int> v = { 5,7,7,8,8,10 };
    vector<int> result = searchRange(v, 8);
    for (auto i : result) {
        cout << i << endl;
    }

    system("pause");
    return 0;
}

/*
思路二：使用二分查找，找到第一个target之后，向左找第一个不是target的位置或是数组头，记录为位置1。然后从第一个target位置向后寻找，找到第一个不是target的位置或是数组尾，记录为位置2。这样复杂度比第一种情况要低一些，但是和数组中和target值相等的元素个数有关系。
*/

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = { -1,-1 };
    int pos1 = 0;
    int pos2 = nums.size() - 1;
    while (pos1 <= pos2) {
        int middle = (pos1 + pos2) / 2;
        if (nums[middle] == target) {
            int temp = middle;
            while (middle >= 0&&nums[middle] == target)
                --middle;
            result[0] = middle+1;
            while (temp < nums.size() && nums[temp] == target)
                ++temp;
            result[1] = temp - 1;
            return result;
        }
        if (nums[middle] > target)
            pos2 = middle - 1;
        if (nums[middle] < target)
            pos1 = middle + 1;
    }
    return result;
}

/*
思路三：使用彻底的二分查找思路，能保证复杂度降到logn。先使用二分法找出左边节点，再找出又边节点。但是找出左右节点需要对二分法做一些修改。
*/

vector<int> searchRange(vector<int>& nums, int target) {
    //总体思路，先二分法找到左端点，再二分法找到又端点
    vector<int> result = {-1,-1};
    //注意这里pos2初始化为size()而不是size()-1。
    int pos1 = 0; int pos2 = nums.size();
    int middle = (pos1 + pos2) / 2;
    while (pos1 < pos2) {
        middle = (pos1 + pos2) / 2;
        //注意此处和二分法的差别，等于条件的处理是怎么样的
        if (nums[middle] >= target)
            pos2 = middle ;
        if (nums[middle] < target)
            pos1 = middle + 1;
    }
    //第一个条件判断是不是没找到target，第二个条件筛选数组程度为1，且没有找到的情况。
    if (nums.size() == pos1 || nums[pos1] != target)
        return result;
    result[0] = pos1;

    //当pos1=n，pos2=n+1的时候，middle是指向n的，要找右边的节点，就必须想办法改变一下二分法。
    pos1 = 0;
    pos2 = nums.size() ;
    middle = (pos1 + pos2) / 2;
    while (pos1 < pos2) {
        middle = (pos1 + pos2) / 2;
        if (nums[middle] > target)
            pos2 = middle;
        if (nums[middle] <= target)
            pos1 = middle +1;
    }
    //这里需要减一
    result[1] = pos1-1;
    return result;
}

/*
　	第三种方法需要复习，理解二分法。

　　二分法需要注意的地方：

　　1、while循环的判断条件赢写成while(pos1<=pos2)而不是while(pos1<pos2)，没有等号时，当数组只有一个元素的情况会漏。在pos1=n，pos2=n+1，且target=nums[pos2]的时候也会遗漏。

　　2、当pos1=n，pos2=n+1时，middle会取得n，应为/2时忽略的余数，这使得选取middle会有“向左移”的倾向，思路三在找出右边范围的时候因此做了很多的修改。需要注意。
*/