/*
一、简介
　　包含全排列问题、包含重复元素的全排列问题、以及它们的递归和非递归实现、还有如何寻找字典顺序的下一个排列、以及寻找第k个排列数。

二、内容
1、全排列问题（递归解法）
描述

给定一个数组nums，要求给出所有排列情况。

例子：nums = {1，2，3}，返回结果为

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

思路

对于以上nums = {1，2，3}的例子，我们对全排列的情况做一个分类：

　　①以1开头，后面跟着{2，3}的全排列

　　②以2开头，后面跟着{1，3}的全排列

　　③以3开头，后面跟着{1，2}的全排列

而对于{2，3}、{1，3}、{1，2}，我们又可以重复使用以上的思路，下面以{2，3}为例分析：

　　①以2开头，后面跟着{3}的全排列

　　②以3开头，后面跟着{2}的全排列

而对于{2}、{3}这些只有一个数的集合，它们的全排列就是它们本身。这也就是递归的终止条件。

以上的思路，用代码按如下方式实现：

对于一个有n个元素的数组a，假设其n个元素分别为a[n-1]。

第一步：

将其分成两个部分，第一个元素a[0]和后面其他元素，全排列表示以a[0]为首的所有排列，等于a[0]加上后面部分的全排列

第二步：

使用a[0]和后面的a[1]交换，同样，得到了以a[1]为首的所有全排列。

第三步：

交换回原来的序列，然后再交换a[0]和a[2]。这样能得到以a[2]为首的所有排列，然后再交换回初始状态

第四步：

按上面的交换--求排列--再交换回来的流程分别求出以a[3]-a[n-1]为首的所有排列。

这样就得到了所有的排列情况。

注意：对后面部分的排列情况调用递归实现，返回条件是当后面部分只有一个元素的时候。
*/

void get_permute(vector<int>& nums, int pos, vector<vector<int>>& result) {
    if (nums.size() == pos) {
        result.push_back(nums);
        return;
    }
    for (int i = pos; i < nums.size(); i++) {
        swap(nums[pos], nums[i]);
        get_permute(nums,pos+1,result);
        swap(nums[i], nums[pos]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    get_permute(nums,0,result);
    return result;
}

//这是测试用例
int main()
{
    vector<int> v = {1,1,3};
    auto result = permute(v);
    for (auto i : result) {
        for (auto j : i)
            cout << j;
        cout << endl;
    }

    system("pause");
    return 0;
}


/*
2、含有重复元素的全排列问题（递归解法）
描述：

假如给定的数组有重复元素，比如nums={1，1，2}，要求求出全排列，不能有重复。

思路：

考虑其中任意一个递归时的情况，假设其第一部分为a[i]，第二部分为a[i+1]到a[n-1]。在这种情况，按照上面的描述将数组分为两个部分求解全排列。（我们假设有元素a[j]，其中i+1 ≤ j ≤ n-1）

重复的情况分为以下两种：

　　①a[i] = a[j]时，a[i]和a[j]互换得到的序列与之前一样，再求一遍全排列会有重复

　　②a[j] = a[j2]（j2和j取同样范围，但j != j2）。当a[i]与a[j]互换后得到的序列与a[i]与a[j2]互换得到的序列相等，分别对他们求全排列也会出现重复

于是，在上述解法的代码中，get_permute函数的for循环中加入限制条件，让他们跳过这两种情况。
*/

void get_permuteUnique(vector<int>& nums, int pos, vector<vector<int>>& result) {
    if (nums.size() == pos) {
        result.push_back(nums);
        return;
    }
    for (int i = pos; i < nums.size(); i++) {
        //第一种重复，位置pos和位置i的数重复
        if (i != pos && nums[i] == nums[pos]) continue;
        //第二种重复，位置pos和位置i的数不重复
        //但pos之后有两个位置i和j，nums[i]和nums[j]有重复,导致pos和同一个数交换了两次
        bool find = false;        //用find来指示是否找到了这样的i和j
        if(i != pos){
            int temp = i;
            while (temp < nums.size()) {
                if (temp != i && nums[temp] == nums[i]) {
                    find = true;
                    break;
                }
                temp++;
            }
        }
        if (find == true)
            continue;
        //除去重复结束

        swap(nums[pos], nums[i]);
        get_permuteUnique(nums, pos + 1, result);
        swap(nums[i], nums[pos]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    get_permuteUnique(nums, 0, result);
    return result;
}

//这是测试用例
int main()
{
    vector<int> v = {1,1,3};
    auto result = permuteUnique(v);
    for (auto i : result) {
        for (auto j : i)
            cout << j;
        cout << endl;
    }

    system("pause");
    return 0;
}


/*
3、下一个排列（在讲解非递归实现之前的问题）
描述：

给定一个数，按字典顺序找出下一个排列。（如果给出是最大的，则返回最小）

例子：123，下一个比123大的排列是132

　　　321，这是最大的数，返回最小的数123

　　　115，下一个比112大的数是152

思路：

　　第一步：我们从后往前遍历，寻找第一个位置i，其中i满足nums[i]<nums[i+1]，即前项数比后项数小。因为下一个排列数一定比当前数大，当数组从后往前依次递增的时候表示数是最大的，在i处数突然变小了，说明使用后面的一位比i更大的数来替换i能获得更大的排列数。

　　第二步：从i处向后寻找，找到一个比i处数更大，但是和i处的数之差最小的位置j。要得到下一个排列数，一定要使换到u处的数尽可能小，但是要大于i处的数。

　　第三步：调换i和j处的数。这样确保了i处的数是最合适的。因为此时数组后半部分中，j处的数是所有大于i处的数中最小的

　　第四部：对i+1到末尾的数据进行从小到大排序。最高位替换成了更大的数，故后面的数要尽可能的小，大的数要往后排。
*/

void nextPermutation(vector<int>& nums) {
    int last = INT_MIN;
    int i;
    for (i = nums.size() - 1; i >= 0; i--) {
        if (nums.at(i) < last) 
            break;
        last = nums.at(i);
    }
    //判断数据是否是最大排列数，如果是，返回最小排列数
    if (i == -1) {
        sort(nums.begin(), nums.end());
        return;
    }
    int min_pos = i;
    int min = INT_MAX;
    for (int j = i; j < nums.size(); j++) {
        if (nums.at(j) - nums.at(i)>0&& nums.at(j) - nums.at(i)< min)
            min_pos = j;
    }
    swap(nums.at(i), nums.at(min_pos));
    sort(nums.begin()+i+1,nums.end());
}

//这是测试用例
int main()
{
    vector<int> v = {2,3,1};
    nextPermutation(v);
    for (auto k : v) {
        cout << k << endl;
    }

    system("pause");
    return 0;
}

/*
4、全排列的非递归实现（不含重复元素）
思路：

上面我们描述了如何寻找下一个排列，嗯，那是非递归实现的，我们只需要对先数进行排序，然后依次调用这个函数就可以了。看实现。
*/

void nextPermutation(vector<int>& nums,bool& end) {
    int last = INT_MIN;
    int i;
    for (i = nums.size() - 1; i >= 0; i--) {
        if (nums.at(i) < last) 
            break;
        last = nums.at(i);
    }
    if (i == -1) {
        end = true;
        return;
    }
    int min_pos = i;
    int min = INT_MAX;
    for (int j = i; j < nums.size(); j++) {
        if (nums.at(j) - nums.at(i)>0&& nums.at(j) - nums.at(i)< min)
            min_pos = j;
    }
    swap(nums.at(i), nums.at(min_pos));
    sort(nums.begin()+i+1,nums.end());
}

vector<vector<int>> permuteNoRecursion(vector<int>& nums) {
    vector<vector<int>> result;
    bool end = false;
    sort(nums.begin(),nums.end());
    while (end == false) {
        vector<int> thistime = nums;
        result.push_back(thistime);
        nextPermutation(nums,end);
    }
    return result;
}

//这是测试用例
int main()
{
    vector<int> v = {1,2,3};
    auto result = permuteNoRecursion(v);
    for (auto i : result) {
        for (auto j : i)
            cout << j;
        cout << endl;
    }

    system("pause");
    return 0;
}

/*
5、全排列的非递归实现（含重复元素）
思路：
和上面一样利用nextPermutation函数，只是在得到排列之后判断一下是否与之前的排列一样。为此实现了一个简单判断vector<int>是否一致的函数check。应该很好懂了。直接上代码
*/
void nextPermutation(vector<int>& nums,bool& end) {
    int last = INT_MIN;
    int i;
    for (i = nums.size() - 1; i >= 0; i--) {
        if (nums.at(i) < last) 
            break;
        last = nums.at(i);
    }
    if (i == -1) {
        end = true;
        return;
    }
    int min_pos = i;
    int min = INT_MAX;
    for (int j = i; j < nums.size(); j++) {
        if (nums.at(j) - nums.at(i)>0&& nums.at(j) - nums.at(i)< min)
            min_pos = j;
    }
    swap(nums.at(i), nums.at(min_pos));
    sort(nums.begin()+i+1,nums.end());
}

//判断两个vector<int>是否相等
bool check(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() != nums2.size()) return false;
    for (int i = 0; i < nums1.size(); i++)
        if (nums2[i] != nums1[i])
            return false;
    return true;
}

//主逻辑函数
vector<vector<int>> permuteNoRecursion(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> thistime;
    bool end = false;
    sort(nums.begin(),nums.end());
    while (end == false) {
        if (check(thistime, nums) == false) {
            thistime = nums;
            result.push_back(thistime);
        }
        nextPermutation(nums,end);
    }
    return result;
}


//这是测试用例
int main()
{
    vector<int> v = {1,1,3};
    auto result = permuteNoRecursion(v);
    for (auto i : result) {
        for (auto j : i)
            cout << j;
        cout << endl;
    }

    system("pause");
    return 0;
}

/*
6、寻找第k个排列（不含重复元素）
第一种：使用前面提到的寻找下一个排列，循环k次，得到第k个排列

第二种：使用排列顺序的规则来直接得到数字

假设有n=4个数，nums={1，2，3，4}

我们可以得到它的有序排列为，共有n！个排列

以1开头	1234
1243
1324
1342
1423
1432
以2开头	2134
2143
2314
2341
2413
2431
以3开头	3124
3142
3214
3241
3412
3421
以4开头	
4123
4132
4213
4231
4312
4321

我们首先看第一个位置的数，假设我们要得到第10个排列，以每一个数开头的排列都有（n-1）！种，使用10除（n-1）！，得10/(n-1)! = 1，即第一个数为1，由于10%(n-1)!=4，所以我们要求的排列数在以2开头的排列中位于第四。

接着，n减一，我们使用上一步的余数4/2!得到2，即开头第一个数应该是第二个（由于2在第一个数已经被用到了，所以第二个数应该为3）。

接着后面只有两位，该规律到两位的时候就不符合了。直接判断得出结果。

代码中，使用map的第二个值来表示该数书否已经用过了，而getn函数用来求阶乘
*/

int getn(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i)
        result = result * i;
    return result;
}
string getPermutation(int n, int k) {
    --k;
    map<int, int> m = { {1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1} };
    string result = "";
    for (int i = 1; i <= n; ++i) {
        int pos;
        //除的方式到最后两项就不成立了,当剩余两项的时候，直接赋值
        if (n - i > 1)
            pos = k / (getn(n - i)) + 1;
        else if (n - i == 1)
            pos = k + 1;
        else if (n - i == 0)
            pos = 1;
        int j = 0;
        //寻找第pos个数，如果遇到map中第二个数为0，则表示该数已经被用过了
        for (; j < pos; ++j) {
            if (m[j+1] == 0)
                ++pos;
        }
        result += to_string(j);
        m[j] = 0;
        if(n - i > 1)
            k = k % getn(n - i);
    }
    return result;
}

//这是测试用例
int main()
{
    for (int i = 1; i <= 24; ++i) {
        cout << getPermutation(4, i) << endl;
    }

    system("pause");
    return 0;
}