/*
一、问题描述
　　给定一个数组v和一个数n，要求删除数组中所有和n向等的数，并且将不为n的数放入数组前面，返回数组长度。

　　例子：v={3，2，2，3}，n=3，返回2，且v的前两项必须为两个2

二、问题解决
　　这个题目和26题其实是一模一样的，看看26题吧。
*/

int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0) return 0;
    int pos = 0; 
　　 //先找到第一个为val的地方，如果前面都不为val，则可以避免写操作。
    while (pos<nums.size() && nums.at(pos) != val) {
        pos++;
    }
    int pos2 = pos;
    while (pos2 < nums.size()) {
        if (nums.at(pos2) == val) {
            pos2++;
            continue;
        }
        if (pos2 != pos)
            nums.at(pos) = nums.at(pos2);
        pos++;
        pos2++;
    }
    return pos;
}

int main()
{
    vector<int> v = {1};
    cout << removeElement(v,1) << endl;

    system("pause");
    return 0;
}

/*
三、问题反思
这个题明明和26题一样，写的时候还是写了很久。而且写了一个很复杂的版本，逻辑不清楚，看下面
*/
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

